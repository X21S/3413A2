#include <stdio.h>

#include "console.h"
#include "config.h"
#include "game.h"

int main(int argc, char**argv)
{
  char *board[GAME_ROWS] = {GAME_BOARD_RAW};

  if(!consoleInit(GAME_ROWS, GAME_COLS, board))
  {
    printf("Error occured: cannot to init console\n");
    return 1;
  }

  game_t game = GameStart();
  GameWait(game);
  GameDestroy(game);

  consoleFinish();
  return 0;
}
