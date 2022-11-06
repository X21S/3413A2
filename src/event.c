#include "event.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <pthread.h>

#include "config.h"
#include "console.h"

struct event_
{
   char pressedKey;

   pthread_mutex_t lock;
};

event_t EventCreate()
{
   event_t event = malloc(sizeof(struct event_));
   if(event == NULL)
      return NULL;

   event->pressedKey = 0;

   return event;
}

void EventDestroy(event_t event)
{
   if(event == NULL)
      return;

   free(event);
}

void* EventLoop(void* gameRaw)
{
   if(gameRaw == NULL)
      return NULL;

   game_t game = (game_t) gameRaw;
   if(GameCheckNull(game))
      return NULL;

   fd_set set;

   while(GetRunning(game))
   {
      FD_ZERO(&set);
      FD_SET(STDIN_FILENO, &set);
      struct timespec timeout = getTimeout(GAME_EVENT_TIMEOUT_TICKS);
      int ret = pselect(FD_SETSIZE, &set, NULL, NULL, &timeout, NULL);

      if (GetRunning(game) && ret >= 1)
      {
         event_t event = GetEvent(game);

         pthread_mutex_lock(&event->lock);
         event->pressedKey = getchar();
         pthread_mutex_unlock(&event->lock);
      }
   }

   return NULL;
}

char EventProcessKey(event_t event)
{
   if(event == NULL)
      return 0;

   char out = event->pressedKey;

   pthread_mutex_lock(&event->lock);
   event->pressedKey = 0;
   pthread_mutex_unlock(&event->lock);

   return out;
}
