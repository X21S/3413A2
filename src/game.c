#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "player.h"

game_t GameStart()
{
   game_t game = malloc(sizeof(struct game_));
   if(game == NULL)
      return NULL;

   game->isRunning = true;
   game->player = PlayerCreate();

   printf("starting");
   pthread_create(&game->playerThread, NULL, PlayerLoop, game);

   return game;
}

void GameDestroy(game_t game)
{
   PlayerDestroy(GetPlayer(game));
   free(game);
}

void GameWait(game_t game)
{
   sleep(4);

   game->isRunning = false;
   pthread_join(game->playerThread, NULL);
}

int GameCheckNull(game_t game)
{
   if(game == NULL)
      return true;
   if(game->player == NULL/*||
      game->event == NULL*/)
      return true;

   return false;
}

player_t GetPlayer(game_t game)
{
   if(game == NULL)
      return NULL; //TODO: create error signal
   if(game->player == NULL)
      return NULL; //TODO: create error signal
   return game->player;
}

int GetRunning(game_t game)
{
   if(game == NULL)
      return NULL; //TODO: create error signal

   return game->isRunning;
}
