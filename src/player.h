#ifndef CATERPILLARS_PLAYER_H
#define CATERPILLARS_PLAYER_H

#include <pthread.h>

#include "config.h"
#include "game.h"

struct player_;
typedef struct player_* player_t;

player_t PlayerCreate();
void PlayerDestroy(player_t);
int PlayerLoop(game_t);


#endif
