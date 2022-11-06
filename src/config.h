#ifndef CATERPILLARS_CONFIG_H
#define CATERPILLARS_CONFIG_H

#define GAME_PLAYER_DEFAULT_HEALTH 3

#define GAME_ROWS 24
#define GAME_COLS 80

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

#define GAME_PLAYER_SCORE_POS_X 26
#define GAME_PLAYER_SCORE_POS_Y 0

#define GAME_PLAYER_HEALTH_POS_X 42
#define GAME_PLAYER_HEALTH_POS_Y 0

#define GAME_PLAYER_TILE_HEIGHT 1
#define GAME_PLAYER_TILE_RAW "X"

#define GAME_PLAYGROUND_MIN_X 0
#define GAME_PLAYGROUND_MIN_Y 2

#define GAME_PLAYGROUND_MAX_X GAME_COLS
#define GAME_PLAYGROUND_MAX_Y GAME_ROWS

enum ERROR_CODE
{
  ERROR_SUCESSFUL,
  ERROR_OUT_OF_MEMORY,
  ERROR_NULL_OBJECT,
};

#endif
