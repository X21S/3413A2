#ifndef CATERPILLARS_CONFIG_H
#define CATERPILLARS_CONFIG_H


#define GAME_ROWS 24
#define GAME_COLS 80

#define GAME_PLAYGROUND_MIN_X 0
#define GAME_PLAYGROUND_MIN_Y 2

#define GAME_PLAYGROUND_MAX_X (GAME_COLS - 1)
#define GAME_PLAYGROUND_MAX_Y (GAME_ROWS - 1)

#define GAME_BOARD_RAW \
  "                   Score:          Lives:", \
  "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-centipiede!=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "", \
  "",

#define GAME_KEY_UP 'w'
#define GAME_KEY_LEFT 'a'
#define GAME_KEY_RIGHT 'd'
#define GAME_KEY_BOTTOM 's'
#define GAME_KEY_SHOOT ' '
#define GAME_KEY_EXIT 'q'


#define GAME_PLAYER_SCORE_POS_X 26
#define GAME_PLAYER_SCORE_POS_Y 0
#define GAME_PLAYER_SCORE_LENGTH 10

#define GAME_PLAYER_HEALTH_DEFAULT 3
#define GAME_PLAYER_HEALTH_POS_X 42
#define GAME_PLAYER_HEALTH_POS_Y 0
#define GAME_PLAYER_HEALTH_LENGTH 10

#define GAME_PLAYER_SPAWN_X (GAME_PLAYGROUND_MAX_X / 2)
#define GAME_PLAYER_SPAWN_Y (GAME_PLAYGROUND_MAX_Y - 2)

#define GAME_PLAYER_TILE_HEIGHT 1
#define GAME_PLAYER_TILE_RAW "X"

#define GAME_PLAYER_SLEEP_TICKS 1

#define GAME_EVENT_TIMEOUT_TICKS 1

enum ERROR_CODE
{
  ERROR_SUCESSFUL,
  ERROR_OUT_OF_MEMORY,
  ERROR_NULL_OBJECT,
};

#endif
