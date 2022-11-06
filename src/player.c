#include "player.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

struct player_
{
   int posX;
   int posY;
   int health;
   int score;

   char** playerTile;
   int playerTileHeight;

   //char scoreTile[10];
   //char healthTile[10];

   pthread_mutex_t lock;
};

player_t PlayerCreate()
{
   player_t player = malloc(sizeof(struct player_));
   if(player == NULL)
      return NULL;

   player->health = GAME_PLAYER_DEFAULT_HEALTH;
   player->score = 0;
   //TODO: Ugly code
   player->posX = 4;
   player->posY = 5;
   player->playerTile = malloc(sizeof(char*) * 1);
   player->playerTile[0] = "X";
   player->playerTileHeight = 1;//GAME_PLAYER_TILE_HEIGHT;

   return player;
}

void PlayerDestroy(player_t player)
{
   if(player == NULL)
      return;

   free(player->playerTile);
   free(player);
}

void PlayerMove(player_t player)
{
   player->posX += 1;
   player->posY += 1;

   if(player->posX >= GAME_PLAYGROUND_MAX_X)
      player->posX = GAME_PLAYGROUND_MAX_X;

   if(player->posY >= GAME_PLAYGROUND_MAX_Y)
      player->posY = GAME_PLAYGROUND_MAX_Y;
}

int PlayerLoop(game_t game)
{
   if(GameCheckNull(game))
      return ERROR_NULL_OBJECT;

   while(GetRunning(game))
   {
      player_t player = GetPlayer(game);

      //snprintf(player->healthTile, 5, "%i", player->health);
      //snprintf(player->scoreTile, 5, "%i", player->score);

      consoleClearImage(player->posY, player->posX,
            player->playerTileHeight, strlen(player->playerTile[0]));

      PlayerMove(player);

      consoleDrawImage(player->posY, player->posX,
            player->playerTile, player->playerTileHeight);
      consoleRefresh();
      sleep(1);
   }

   return ERROR_SUCESSFUL;
}
