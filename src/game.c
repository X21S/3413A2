#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "player.h"
#include "event.h"

struct game_
{
   int isRunning;
   player_t player;
   event_t event;

   pthread_t playerThread;
   pthread_t eventThread;

   pthread_mutex_t lock;
};

game_t GameStart()
{
   game_t game = malloc(sizeof(struct game_));
   if(game == NULL)
      return NULL;

   game->isRunning = true;
   game->player = PlayerCreate();
   game->event = EventCreate();

   pthread_create(&game->eventThread, NULL, EventLoop, game);
   pthread_create(&game->playerThread, NULL, PlayerLoop, game);

   return game;
}

void GameDestroy(game_t game)
{
   PlayerDestroy(GetPlayer(game));
   EventDestroy(GetEvent(game));
   free(game);
}

void GameWait(game_t game)
{
   pthread_join(game->playerThread, NULL);
   pthread_join(game->eventThread, NULL);
}

int GameCheckNull(game_t game)
{
   if(game == NULL)
      return true;
   if(game->player == NULL ||
      game->event == NULL)
      return true;

   return false;
}

void GameExit(game_t game)
{
   if(game == NULL)
      return;

   pthread_mutex_lock(&game->lock);
   game->isRunning = 0;
   pthread_mutex_unlock(&game->lock);
}

player_t GetPlayer(game_t game)
{
   if(game == NULL)
      return NULL; //TODO: create error signal
   if(game->player == NULL)
      return NULL; //TODO: create error signal
   return game->player;
}

event_t GetEvent(game_t game)
{
   if(game == NULL)
      return NULL; //TODO: create error signal
   if(game->event == NULL)
      return NULL; //TODO: create error signal
   return game->event;
}

int GetRunning(game_t game)
{
   if(game == NULL)
      return 0; //TODO: create error signal

   return game->isRunning;
}
