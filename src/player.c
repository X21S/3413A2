#include "player.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#include "console.h"
#include "event.h"

struct player_
{
   int posX;
   int posY;
   int health;
   int score;

   char** playerTile;
   int playerTileHeight;

   char scoreStr[GAME_PLAYER_SCORE_LENGTH];
   int scoreOld;

   char healthStr[GAME_PLAYER_HEALTH_LENGTH];
   int healthOld;

   pthread_mutex_t lock;
};

player_t PlayerCreate()
{
   player_t player = malloc(sizeof(struct player_));
   if(player == NULL)
      return NULL;

   player->health = GAME_PLAYER_HEALTH_DEFAULT;
   player->score = 0;
   player->posX = GAME_PLAYER_SPAWN_X;
   player->posY = GAME_PLAYER_SPAWN_Y;

   //TODO: Ugly code
   player->playerTile = malloc(sizeof(char*) * 1);
   player->playerTile[0] = "X";
   player->playerTileHeight = 1;//GAME_PLAYER_TILE_HEIGHT;

   player->scoreOld = -1;
   player->healthOld = -1;
   return player;
}

void PlayerDestroy(player_t player)
{
   if(player == NULL)
      return;

   free(player->playerTile);
   free(player);
}

void* PlayerLoop(void* gameRaw)
{
   if(gameRaw == NULL)
      return NULL;

   game_t game = (game_t) gameRaw;
   if(GameCheckNull(game))
      return NULL;


   while(GetRunning(game))
   {
      player_t player = GetPlayer(game);

      PlayerPrintScore(player);
      PlayerPrintHealth(player);

      consoleClearImage(player->posY, player->posX,
            player->playerTileHeight, strlen(player->playerTile[0]));

      PlayerProcessEvent(game);

      consoleDrawImage(player->posY, player->posX,
            player->playerTile, player->playerTileHeight);
      consoleRefresh();

      sleepTicks(GAME_PLAYER_SLEEP_TICKS);
   }

   return NULL;
}

void PlayerProcessEvent(game_t game)
{
   char key = EventProcessKey(GetEvent(game));
   player_t player = GetPlayer(game);

   switch(key)
   {
      case GAME_KEY_UP:     PlayerMove(player, 0, -1); break;
      case GAME_KEY_LEFT:   PlayerMove(player, -1, 0); break;
      case GAME_KEY_RIGHT:  PlayerMove(player, 1, 0); break;
      case GAME_KEY_BOTTOM: PlayerMove(player, 0, 1); break;
      case GAME_KEY_SHOOT:  /*PlayerShoot(game);*/ break;
      case GAME_KEY_EXIT:   GameExit(game); break;
      default: break;
   }
}

void PlayerMove(player_t player, int dx, int dy)
{
   if(player == NULL)
      return;

   pthread_mutex_lock(&player->lock);

   player->posX += dx;
   player->posY += dy;

   //Todo: need chevk collision with other objects
   if(player->posX < GAME_PLAYGROUND_MIN_X)
      player->posX = GAME_PLAYGROUND_MIN_X;
   else if(player->posX > GAME_PLAYGROUND_MAX_X)
      player->posX = GAME_PLAYGROUND_MAX_X;

   if(player->posY < GAME_PLAYGROUND_MIN_Y)
      player->posY = GAME_PLAYGROUND_MIN_Y;
   else if(player->posY > GAME_PLAYGROUND_MAX_Y)
      player->posY = GAME_PLAYGROUND_MAX_Y;

   pthread_mutex_unlock(&player->lock);
}

void PlayerPrintScore(player_t player)
{
   if(player == NULL)
      return;

   if(player->scoreOld != player->score)
   {
      snprintf(player->scoreStr,  GAME_PLAYER_SCORE_LENGTH,  "%i", player->score);
      putString(player->scoreStr,
            GAME_PLAYER_SCORE_POS_Y, GAME_PLAYER_SCORE_POS_X,
            GAME_PLAYER_SCORE_LENGTH);

      player->scoreOld = player->score;
   }
}

void PlayerPrintHealth(player_t player)
{
   if(player == NULL)
      return;

   if(player->healthOld != player->health)
   {
      snprintf(player->healthStr, GAME_PLAYER_HEALTH_LENGTH, "%i", player->health);
      putString(player->healthStr,
            GAME_PLAYER_HEALTH_POS_Y, GAME_PLAYER_HEALTH_POS_X,
            GAME_PLAYER_HEALTH_LENGTH);

      player->healthOld = player->health;
   }
}
