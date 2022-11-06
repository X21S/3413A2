#ifndef CATERPILLARS_DRAWER_H
#define CATERPILLARS_DRAWER_H

#include "game.h"

struct drawer_;
typedef struct drawer_* drawer_t;

drawer_t DrawerCreate();
void DrawerDestroy(drawer_t);
void* DrawerLoop(void*);

void ClearImage(drawer_t, int row, int col, int height, int width);
void DrawImage(drawer_t, int row, int col, char *image[], int height);
void DrawString(drawer_t, char*, int row, int col, int maxlen);

#endif
