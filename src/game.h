#ifndef CATERPILLARS_GAME_H
#define CATERPILLARS_GAME_H

#include <pthread.h>

//Ugly code
typedef struct player_* player_t;
typedef struct event_* event_t;

struct game_
{
   int isRunning;
   player_t player;
   event_t event;

   pthread_t* playerThread;
   pthread_t* eventThread;


   pthread_mutex_t lock;
};
typedef struct game_* game_t;

game_t GameStart();
void GameDestroy(game_t);
int GameCheckNull(game_t);

player_t GetPlayer(game_t);
event_t  GetEvent(game_t);
int      GetRunning(game_t);

#endif
