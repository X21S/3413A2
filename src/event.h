#ifndef CATERPILLARS_KEYS_H
#define CATERPILLARS_KEYS_H

#include <pthread.h>

#include "game.h"

struct event_;
typedef struct event_* event_t;

event_t EventCreate();
void EventDestroy(event_t);
void* EventLoop(void*);

char EventProcessKey(event_t);

#endif
