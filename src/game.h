#ifndef CATERPILLARS_GAME_H
#define CATERPILLARS_GAME_H

//Ugly code
typedef struct player_* player_t;
typedef struct event_* event_t;

struct game_;
typedef struct game_* game_t;

game_t GameStart();
void GameWait(game_t);
void GameDestroy(game_t);

int GameCheckNull(game_t);
void GameExit(game_t);

player_t GetPlayer(game_t);
event_t  GetEvent(game_t);
int      GetRunning(game_t);

#endif
