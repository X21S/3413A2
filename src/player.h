#ifndef CATERPILLARS_PLAYER_H
#define CATERPILLARS_PLAYER_H

#include <pthread.h>

#include "config.h"
#include "game.h"

struct player_;
typedef struct player_* player_t;

player_t PlayerCreate();
void PlayerDestroy(player_t);
void* PlayerLoop(void*);

void PlayerProcessEvent(game_t game);
void PlayerMove(player_t player, int dx, int dy);

void PlayerPrintScore(player_t, drawer_t);
void PlayerPrintHealth(player_t, drawer_t);

#endif
