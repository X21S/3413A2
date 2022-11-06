#ifndef CATERPILLARS_EVENT_H
#define CATERPILLARS_EVENT_H

#include "game.h"

struct event_;
typedef struct event_* event_t;

event_t EventCreate();
void EventDestroy(event_t);
void* EventLoop(void*);

char EventProcessKey(event_t);

#endif
