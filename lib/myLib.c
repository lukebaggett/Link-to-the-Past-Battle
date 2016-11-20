#include "myLib.h"
#include <string.h>
#include <stdlib.h>

//// Screen Control

void waitForVblank() {
  while(*SCANLINECOUNTER >= 160);
  while(*SCANLINECOUNTER < 160);
}

// Drawing

void drawImage3(int x, int y, int width, int height, const unsigned short *image) { 
  for(int i = 0; i < height - 1; i++) {
    DMA[3].src = &image[OFFSET(i, width)];
    DMA[3].dst = &videoBuffer[OFFSET(x + i, y)];
    DMA[3].cnt = 240 | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT | DMA_ON;
  }
}

void fillScreen3(volatile unsigned short color) {
  DMA[3].src = &color;
  DMA[3].dst = videoBuffer;
  DMA[3].cnt = (240*160) | DMA_SOURCE_FIXED | DMA_DESTINATION_INCREMENT | DMA_ON;
}

void setPixel(int row, int col, unsigned short color)
{
  videoBuffer[OFFSET(row, col)] = color;
}

void updateHearts(int hp, const unsigned short *image) {
  drawImage3(0, 0, 240, 160, image);
  unsigned short color;
  int ic;
  int ir;
  for (int h = 0; h < hp; h++) {
    ic = 214 + 9*h;
    ir = 2;
    if (h <= hp) {
      color = RED;
    } else {
      color = WHITE;
    }
    // set outside of heart
    for (int i = 0; i < 3; i++) {
      setPixel(ir + i, ic, color);
      setPixel(ir + i, ic + 4, color);
    }
    // set middle of heart
    for (int i = 0; i < 4; i++) {
      setPixel(ir + i, ic + 1, color);
      setPixel(ir + i + 1, ic + 2, color);
      setPixel(ir + i, ic + 3, color);
    }
  }
}

void drawRectangle(int row, int col, int width, int height, unsigned short color)
{
  for(int l = 0; l <= height/2; l++) {
    for(int i = 0; i < width; i++) {
      setPixel(row + l, col + i, color);
      setPixel(row + height - l, col + i, color);
    }
  }
}

void drawHollowRectangle(int row, int col, int width, int height, unsigned short color)
{
  for(int i = 0; i <= width; i++) {
    setPixel(row, col + i, color);
    setPixel(row + height, col + i, color);
  }
  for(int i = 0; i <= height; i++) {
    setPixel(row + i, col, color);
    setPixel(row + i, col + width, color);
  }
}

void delay(int n) {
  volatile int x = 0;
  for(int i = 0; i < n*500; i++) {
    x++;
  }
}

/*
void updateSpriteFrame(ObjAttr sp) {
  for(int i = 0; i < 256; i++) {
    SPRITEPAL[i] = ((u16 *)sp.palette)[i];
  }
  memcpy((u16 *)0x06014000, &(((u16 *)sp.data)[sp.framesize*sp.frame_index]),
      sp.framesize*2);
}*/

// Sprite Collision Detection
typedef struct { int top, bottom, left, right; } border;
int border_collision(ObjAttr sp, int row_dir, int col_dir) {
  BORDER bg;
  bg.top = 10;
  bg.bottom = 160 + 10;
  bg.left = 0;
  bg.right = 240 + 15;

  if ((sp.pos.row + sp.move.height + row_dir >= bg.bottom)
      || (sp.pos.row + row_dir <= bg.top)
      || (sp.pos.col + sp.move.width + col_dir >= bg.right)
      || (sp.pos.col + col_dir <= bg.left)) {
    return 1;
  }
  return 0;
}

int sprite_collision(ObjAttr sp1, ObjAttr sp2, POINT p1, POINT p2) {
  return (abs(p1.col - p2.col) * 2 < (sp1.walk.row + sp2.walk.row)) &&
    (abs(p1.row - p2.row) * 2 < (sp1.walk.col + sp2.walk.col));
}

int hit_detect(ObjAttr sp1, ObjAttr sp2) {
  return ((abs(sp1.pos.col - sp2.pos.col) * 2 < (sp1.hit.row + sp2.hit.row)) &&
        (abs(sp1.pos.row - sp2.pos.row) * 2 < (sp1.hit.col + sp2.hit.col))) &&
  ((sp2.state.facing == 0 && sp2.pos.row < sp1.pos.row) ||
  (sp2.state.facing == 1 && sp2.pos.row > sp1.pos.row) ||
  (sp2.state.facing == 3 && sp2.pos.col > sp1.pos.col) ||
  (sp2.state.facing == 2 && sp2.pos.col < sp1.pos.col));
}

void moveSprite(ObjAttr* sp, int x, int y)
{
  sp->attr1 = sp->attr1 & 0xFE00;
  sp->attr1 = sp->attr1 | x;

  sp->attr0 = sp->attr0 & 0xFF00;
  sp->attr0 = sp->attr0 | y;
}

