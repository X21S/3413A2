#include "drawer.h"

#include <stdlib.h>
#include <pthread.h>

#include "config.h"
#include "console.h"

struct drawer_
{

   pthread_mutex_t lock;
};

drawer_t DrawerCreate()
{
   drawer_t drawer = malloc(sizeof(struct drawer_));
   if(drawer == NULL)
      return NULL;

   return drawer;
}

void DrawerDestroy(drawer_t drawer)
{
   if(drawer == NULL)
      return;

   free(drawer);
}

void* DrawerLoop(void* gameRaw)
{
   if(gameRaw == NULL)
      return NULL;

   game_t game = (game_t) gameRaw;
   if(GameCheckNull(game))
      return NULL;

   drawer_t drawer = GetDrawer(game);
   while(GetRunning(game))
   {
      pthread_mutex_lock(&drawer->lock);
      consoleRefresh();
      pthread_mutex_unlock(&drawer->lock);

      sleepTicks(GAME_DRAWER_SLEEP_TICKS);
   }

   return NULL;
}

void ClearImage(drawer_t drawer, int row, int col, int height, int width)
{
   if(drawer == NULL)
      return;

   pthread_mutex_lock(&drawer->lock);
   consoleClearImage(row, col, height, width);
   pthread_mutex_unlock(&drawer->lock);
}

void DrawImage(drawer_t drawer, int row, int col, char *image[], int height)
{
   if(drawer == NULL || image == NULL)
      return;

   pthread_mutex_lock(&drawer->lock);
   consoleDrawImage(row, col, image, height);
   pthread_mutex_unlock(&drawer->lock);
}

void DrawString(drawer_t drawer, char* str, int row, int col, int maxlen)
{
   if(drawer == NULL || str == NULL)
      return;

   pthread_mutex_lock(&drawer->lock);
   putString(str, row, col, maxlen);
   pthread_mutex_unlock(&drawer->lock);
}
