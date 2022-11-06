#ifndef CATERPILLARS_KEYS_H
#define CATERPILLARS_KEYS_H

#include <pthread.h>

#include "game.h"

struct event_;
typedef struct event_* event_t;
//typedef struct
//{
//  char pressedKey;
//} Event;

//typedef struct
//{
//  pthread_mutex_t lock;
//} EventThread;

void ProcessEvent(event_t*);
void EventLoop(game_t*);

#endif
