// HW9
// Name: Luke Baggett
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/myLib.h"
#include "lib/text.h"
#include "images/title.h"
#include "images/bg.h"
#include "images/gameover.h"
#include "lib/sprites.h"

void InitializeSprites(void);
void MoveSprite(ObjAttr* sp, int x, int y);

ObjAttr sprites[128];

char reset = 0;
char attack_ok = 1; // Player can attack
int hp = 3;
int hp_dir = 0;
int framesize = 32*32/2;
int spriteCount = 3;
int deadcount = 0;
int kills = 0;
ObjAttr DefaultPopo;

void InitializeSprites(void)
{
  for(int i = 0; i < 128; i++) {
    sprites[i].attr0 = 160;
    sprites[i].attr1 = 240;
  }
}

void updateSprites(void)
{
  for(int i = 0; i < 64; i++) {
    memcpy((u16*)(0x7000000 + i*16), &(sprites[i]), 16);
  }
}

void updateSprite(int sprite_index, int sprite_id, int fsize, int findex) {
  memcpy((u16 *)0x06014000 + 2048*sprite_index,
      &(sprites_data[sprite_id*16 + fsize*findex]), fsize*2);
}

int checkSpriteCollision(ObjAttr sp, int row_dir, int col_dir) {
  POINT p;
  p.row = sp.pos.row + row_dir;
  p.col = sp.pos.col + col_dir;
  for (int i = 0; i < spriteCount; i++) {
    if (i != sp.index && !sp.state.dead) {
      if (sprite_collision(sp, sprites[i],
            p, sprites[i].pos)) {
        return i + 1;
      }
    }
  }
  return 0;
}

int isHit(ObjAttr sp) {
  for (int i = 0; i < spriteCount; i++) {
    if (i != sp.index && sprites[i].state.attacking) {
      if (hit_detect(sp, sprites[i])) {
          return 1;
      }
    }
  }
  return 0;
}

void safeMove(ObjAttr* sp, int mult) {
  if (!border_collision((*sp), 0, (*sp).dv.col*mult) &&
    !checkSpriteCollision(*sp, 0, (*sp).dv.col*mult)) {
    (*sp).pos.col += (*sp).dv.col*mult;
  }
  if (!border_collision((*sp), (*sp).dv.row*mult, 0) &&
    !checkSpriteCollision(*sp, (*sp).dv.row*mult, 0)) {
    (*sp).pos.row += (*sp).dv.row*mult;
  }
  moveSprite(&(*sp), (*sp).pos.col, 
      (*sp).pos.row);
}

void updateHP() {
  if (sprites[0].state.hp_dir == 0) { return; }
  sprites[0].state.hp += sprites[0].state.hp_dir;
  sprites[0].state.hp_dir = 0;
  updateHearts(sprites[0].state.hp, bg);
}

void startGame() {
  InitializeSprites();
  int deadcount = 0;
  attack_ok = 1; // Player can attack
  hp = 3;
  hp_dir = 0;
  framesize = 32*32/2;
  spriteCount = 3;
  deadcount = 0;
  kills = 0;

  // SPRITE 0 (LINK)
  sprites[0].index = 0;
  sprites[0].pos.row = 120;
  sprites[0].pos.col = 100;
  sprites[0].dv.row = 0;
  sprites[0].dv.col = 0;
  sprites[0].spawn.row = 50;
  sprites[0].spawn.col = 50;

  sprites[0].move.width = 36;
  sprites[0].move.height = 36;
  sprites[0].move.size = sprites[0].move.width*sprites[0].move.height;
  sprites[0].move.dir = 0;
  sprites[0].move.index = 0;
  sprites[0].move.count = 7;
  sprites[0].move.idle = 3;

  sprites[0].attack = sprites[0].move;

  sprites[0].state.idle = 1;
  sprites[0].state.hit = 0;
  sprites[0].state.attacking = 0;
  sprites[0].state.dying = 0;
  sprites[0].state.facing = 0;
  sprites[0].state.hp = 3;
  sprites[0].state.hp_dir = 0;

  sprites[0].walk.row = sprites[0].move.width - 10*2;
  sprites[0].walk.col = sprites[0].move.height - 10*2;
  sprites[0].hit.row = sprites[0].move.width - 5*2;
  sprites[0].hit.col = sprites[0].move.height - 5*2;

  sprites[0].attr0 = ATTR0_REG | ATTR0_8BPP | LINKMOVEU0_SPRITE_SHAPE | sprites[0].pos.row;
  sprites[0].attr1 = LINKMOVEU0_SPRITE_SIZE | sprites[0].pos.col;
  sprites[0].attr2 = 512 + 128*sprites[0].index;

  // SPRITE 1 (POPO)
  sprites[1].index = 1;
  sprites[1].pos.row = 50;
  sprites[1].pos.col = 100;
  sprites[1].dv.row = -1;
  sprites[1].dv.col = 1;
  sprites[1].spawn.row = 50;
  sprites[1].spawn.col = 100;

  sprites[1].move.width = 36;
  sprites[1].move.height = 36;
  sprites[1].move.size = sprites[1].move.width*sprites[1].move.height;
  sprites[1].move.dir = 1;
  sprites[1].move.index = 0;
  sprites[1].move.count = 3;
  sprites[1].move.idle = 0;
  sprites[1].move.counter = 0;

  sprites[1].attack = sprites[1].move;

  sprites[1].state.idle = 0;
  sprites[1].state.hit = 0;
  sprites[1].state.attacking = 0;
  sprites[1].state.dying = 0;
  sprites[1].state.facing = 0;
  sprites[1].state.hp = 1;
  sprites[1].state.hp_dir = 0;

  sprites[1].walk.row = sprites[1].move.width - 12*2;
  sprites[1].walk.col = sprites[1].move.height - 11*2;
  sprites[1].hit.row = sprites[1].move.width - 6*2;
  sprites[1].hit.col = sprites[1].move.height - 6*2;

  sprites[1].attr0 = ATTR0_REG | ATTR0_8BPP | POPO0_SPRITE_SHAPE | sprites[1].pos.row;
  sprites[1].attr1 = POPO0_SPRITE_SIZE | sprites[1].pos.col;
  sprites[1].attr2 = 512 + 128*sprites[1].index;

  DefaultPopo = sprites[1];

  // SPRITE 2 (ANOTHER POPO)
  sprites[2] = sprites[1];
  sprites[2].index = 2;
  sprites[2].pos.row = 100;
  sprites[2].pos.col = 50;
  sprites[2].attr2 = 512 + 128*sprites[2].index;

/*
  // SPRITE 3 (ANOTHER POPO)
  sprites[3] = sprites[1];
  sprites[3].index = 3;
  sprites[3].pos.row = 70;
  sprites[3].pos.col = 50;
  sprites[3].attr2 = 512 + 64*sprites[3].index;

  // SPRITE 4 (ANOTHER POPO)
  sprites[4] = sprites[1];
  sprites[4].index = 4;
  sprites[4].pos.row = 10;
  sprites[4].pos.col = 50;
  sprites[4].attr2 = 512 + 64*sprites[4].index;
*/
  drawImage3(0, 0, 240, 160, bg);
  updateHearts(3, bg);

  for(int i = 0; i < 256; i++) {
    SPRITEPAL[i] = sprites_palette[i];
  }
}

void titleScreen() {
  drawImage3(0, 0, 240, 160, title);
  int counter = 0;
  char str[11] = "Press START";
  while(1) {
    if (KEY_DOWN_NOW(BUTTON_START)) { break; }
    waitForVblank();
    counter += 1;
    if (counter > 30) {
      counter = 0;
    }
    else if (counter > 20) { 
      fillScreen3(BLACK);
      drawImage3(0, 0, 240, 160, title);
    } else {
      drawString(10, 90, str, BLACK);
    }
    delay(10);
  }
}

void resetSprites() {
  InitializeSprites();
  updateSprites();
}

void handleInput(ObjAttr* sp) {
  if (KEY_DOWN_NOW(BUTTON_SELECT)) { reset = 1; }

  if (KEY_DOWN_NOW(BUTTON_A) && attack_ok == 1) {
    (*sp).state.attacking = (*sp).state.facing + 1;
    attack_ok = 0;
  } else if (!KEY_DOWN_NOW(BUTTON_A)){
    attack_ok = 1;
  }

  if (KEY_DOWN_NOW(BUTTON_UP)) {
    (*sp).dv.row = -1;
    (*sp).state.facing = 1;
    (*sp).state.idle = 0;
  } else if (KEY_DOWN_NOW(BUTTON_DOWN)) {
    (*sp).dv.row = 1;
    (*sp).state.facing = 0;
    (*sp).state.idle = 0;
  } else {
    (*sp).dv.row = 0;
  }

  if (KEY_DOWN_NOW(BUTTON_RIGHT)) {
    (*sp).dv.col = 1;
    (*sp).state.facing = 2;
    (*sp).state.idle = 0;
  } else if (KEY_DOWN_NOW(BUTTON_LEFT)) {
    (*sp).dv.col = -1;
    (*sp).state.facing = 3;
    (*sp).state.idle = 0;
  } else {
    (*sp).dv.col = 0;
  }

  if (!KEY_DOWN_NOW(BUTTON_UP) && !KEY_DOWN_NOW(BUTTON_DOWN) &&
      !KEY_DOWN_NOW(BUTTON_RIGHT) && !KEY_DOWN_NOW(BUTTON_LEFT)) {
    (*sp).state.idle = 1;
    (*sp).move.dir = 0;
  } else if ((*sp).move.dir == 0) {
    (*sp).move.dir = 1;
  }

}

void updatePopo(ObjAttr* sp) {
  if (!(checkSpriteCollision(*sp, (*sp).dv.row, (*sp).dv.col) - 1)) {
    sprites[0].state.hp_dir = -1;
    sprites[0].state.hit = 1;
  }

  if ((*sp).state.dying) {
    if ((*sp).move.index > DEATH_FRAMES - 2) {
      (*sp).state.dead = 1;
      deadcount += 1;
      (*sp).pos.row = -10;
      (*sp).pos.col = -10;
      (*sp).dv.row = 0;
      (*sp).dv.col = 0;
      (*sp).move.dir = 0;
      (*sp).move.index = 0;
      moveSprite(&(*sp), (*sp).pos.col, 
          (*sp).pos.row);
    } else {
      (*sp).move.index += (*sp).move.dir;
      updateSprite((*sp).index, DEATH0_ID, framesize, (*sp).move.index);
    }
    return;
  }

  if (!isHit(*sp)) {
    if ((*sp).dv.row == 0) {
      (*sp).dv.row = 1 + (rand() % 2)*-2; }
    if ((*sp).dv.col == 0) {
      (*sp).dv.col = 1 + (rand() % 2)*-2; }
    if ((*sp).state.hp_dir == -1) {
      (*sp).state.hp_dir = 0;
      (*sp).state.hp --;
      if ((*sp).state.hp <= 0) {
        (*sp).state.dying = 1;
        (*sp).move.index = 0;
        (*sp).move.dir = 1;
        updateSprite((*sp).index, DEATH0_ID, framesize, (*sp).move.index);
        return;
      }
    }
    if ((*sp).move.counter < 5) {
      (*sp).move.counter += 1;
    } else {
      (*sp).move.counter = 0;
      if ((*sp).move.index > (*sp).move.count - 2) {
        (*sp).move.dir = -1;
      } else if ((*sp).move.index < 1) {
        (*sp).move.dir = 1;
      }
      (*sp).move.index += (*sp).move.dir;
    }
  } else {
    (*sp).state.hp_dir = -1;
    if (sprites[0].state.facing == 0) {
      (*sp).dv.row = 2;
    } else if (sprites[0].state.facing == 1) {
      (*sp).dv.row = -2;
    } else if (sprites[0].state.facing == 2) {
      (*sp).dv.col = 2;
    } else if (sprites[0].state.facing == 3) {
      (*sp).dv.col = -2;
    }
  }

  if (!border_collision((*sp), 0, (*sp).dv.col) &&
      !checkSpriteCollision(*sp, 0, (*sp).dv.col)) {
    (*sp).pos.col += (*sp).dv.col;
  } else {
    (*sp).dv.col *= -1;
  }
  if (!border_collision((*sp), (*sp).dv.row, 0) && 
      !checkSpriteCollision(*sp, (*sp).dv.row, 0)) {
    (*sp).pos.row += (*sp).dv.row;
  } else {
    (*sp).dv.row *= -1;
  }

  moveSprite(&(*sp), (*sp).pos.col, 
      (*sp).pos.row);

  updateSprite((*sp).index, POPO0_ID, framesize, (*sp).move.index);
}

void updateLink(ObjAttr* sp) {
  if ((*sp).move.index > (*sp).move.count - 2) {
    (*sp).move.dir = -1;
  } else if ((*sp).move.index < 1) {
    (*sp).move.dir = 1;
  }

  if (!(*sp).state.attacking) {
    safeMove(sp, 3);
  }

  if ((*sp).state.idle) {
    (*sp).move.index = 3;
  }
  
  if ((*sp).state.facing == 0) {
    if ((*sp).state.attacking) {
      updateSprite((*sp).index, LINKSTRIKED0_ID, framesize, (*sp).attack.index);
      if ((*sp).attack.index > LINKSTRIKED_FRAMES - 2) {
        (*sp).attack.index = 0;
        (*sp).state.attacking = 0;
        (*sp).dv.row = -1;
        safeMove(sp, 6);
        (*sp).dv.row = 0;
      } else if (!(*sp).attack.index){
        (*sp).dv.row = 1;
        safeMove(sp, 6);
        (*sp).dv.row = 0;
        (*sp).attack.index += 1;
      } else {
        (*sp).attack.index += 1;
      }
    } else {
      updateSprite((*sp).index, LINKMOVED0_ID, framesize, (*sp).move.index);
    }
  } else if ((*sp).state.facing == 1) {
    if ((*sp).state.attacking) {
      updateSprite((*sp).index, LINKSTRIKEU0_ID, framesize, (*sp).attack.index);
      if ((*sp).attack.index > LINKSTRIKEU_FRAMES - 2) {
        (*sp).attack.index = 0;
        (*sp).state.attacking = 0;
        (*sp).dv.row = 1;
        safeMove(sp, 6);
        (*sp).dv.row = 0;
      } else if (!(*sp).attack.index){
        (*sp).dv.row = -1;
        safeMove(sp, 6);
        (*sp).dv.row = 0;
        (*sp).attack.index += 1;
      } else {
        (*sp).attack.index += 1;
      }
    } else {
      updateSprite((*sp).index, LINKMOVEU0_ID, framesize, (*sp).move.index);
    }
  } else if ((*sp).state.facing == 2) {
    if ((*sp).state.attacking) {
      updateSprite((*sp).index, LINKSTRIKEF0_ID, framesize, (*sp).attack.index);
      if ((*sp).attack.index > LINKSTRIKEF_FRAMES - 2) {
        (*sp).attack.index = 0;
        (*sp).state.attacking = 0;
        (*sp).dv.col = -1;
        safeMove(sp, 6);
        (*sp).dv.col = 0;
      } else if (!(*sp).attack.index){
        (*sp).dv.col = 1;
        safeMove(sp, 6);
        (*sp).dv.col = 0;
        (*sp).attack.index += 1;
      } else {
        (*sp).attack.index += 1;
      }
    } else {
      (*sp).attr1 = LINKMOVEF0_SPRITE_SIZE | (*sp).pos.col;
      updateSprite((*sp).index, LINKMOVEF0_ID, framesize, (*sp).move.index);
    }
  } else if ((*sp).state.facing == 3) {
    if ((*sp).state.attacking) {
      updateSprite((*sp).index, LINKSTRIKEF0_ID, framesize, (*sp).attack.index);
      if ((*sp).attack.index > LINKSTRIKEF_FRAMES - 2) {
        (*sp).attack.index = 0;
        (*sp).state.attacking = 0;
        (*sp).dv.col = 1;
        safeMove(sp, 6);
        (*sp).dv.col = 0;
      } else if (!(*sp).attack.index){
        (*sp).dv.col = -1;
        safeMove(sp, 6);
        (*sp).dv.col = 0;
        (*sp).attack.index += 1;
      } else {
        (*sp).attack.index += 1;
      }
    } else {
      (*sp).attr1 = LINKMOVEF0_SPRITE_SIZE | (*sp).pos.col | ATTR1_HFLIP;
      updateSprite((*sp).index, LINKMOVEF0_ID, framesize, (*sp).move.index);
    }
  }
  (*sp).move.index += (*sp).move.dir;
}

void gameOver() {
  if (sprites[0].state.facing == 0) {
    updateSprite(0, LINKDEATHD_ID, framesize, 0);
  } else if (sprites[0].state.facing == 1) {
    updateSprite(0, LINKDEATHU_ID, framesize, 0);
  } else if (sprites[0].state.facing == 3) {
    sprites[0].attr1 = LINKMOVEF0_SPRITE_SIZE | sprites[0].pos.col | ATTR1_HFLIP;
    updateSprite(0, LINKDEATHF_ID, framesize, 0);
  } else if (sprites[0].state.facing == 2) {
    updateSprite(0, LINKDEATHF_ID, framesize, 0);
  }
  delay(100);
  fillScreen3(RED);
  delay(1500);
  resetSprites();
  fillScreen3(BLACK);
  drawImage3(0, 0, 240, 160, gameover);
  char str[19] = "Press A To Continue";
  drawString(100, 60, str, WHITE);
  while(!reset) {
    if (KEY_DOWN_NOW(BUTTON_SELECT) || KEY_DOWN_NOW(BUTTON_A)) {
      reset = 1;
    }
  }
}

void respawnPopo(ObjAttr* sp) {
  switch(rand() % 4) {
    case 0:
      (*sp).pos.row = 10;
      (*sp).pos.col = 10;
      break;
    case 1:
      (*sp).pos.row = 10;
      (*sp).pos.col = 210;
      break;
    case 2:
      (*sp).pos.row = 130;
      (*sp).pos.col = 10;
      break;
    case 3:
      (*sp).pos.row = 130;
      (*sp).pos.col = 210;
      break;
  }
  (*sp).state.hp = 1;
  (*sp).state.dead = 0;
  (*sp).state.dying = 0;
  (*sp).attr0 = ATTR0_REG | ATTR0_8BPP | POPO0_SPRITE_SHAPE | (*sp).pos.row;
  (*sp).attr1 = POPO0_SPRITE_SIZE | (*sp).pos.col;
  (*sp).attr2 = 512 + 128*(*sp).index;

  deadcount --;
}

void win() {
  sprites[0].attr0 = ATTR0_REG | ATTR0_8BPP | TRIFORCE_SPRITE_SHAPE | sprites[0].pos.row;
  sprites[0].attr1 = TRIFORCE_SPRITE_SIZE | sprites[0].pos.col;
  updateSprite(0, TRIFORCE_ID, 64*32/2, 0);
  updateSprites();
  fillScreen3(WHITE);
  delay(1500);
  resetSprites();
  fillScreen3(BLACK);
}

int main(void) {
  REG_DISPCNT = MODE3 | BG2_ENABLE | OBJ_ENABLE | MODE1D;
  
  titleScreen();
  startGame();
  ObjAttr* player = &sprites[0];
  ObjAttr* popo1 = &sprites[1];
  ObjAttr* popo2 = &sprites[2];
//  ObjAttr* popo3 = &sprites[3];
//  ObjAttr* popo4 = &sprites[4];

  while(1) {
    if (sprites[0].state.hp == 0) { gameOver(); }
    if (reset) {
      resetSprites();
      titleScreen();
      reset = 0;
      startGame();
    }
    if (kills > 10) {
      win();
      kills = 0;
      resetSprites();
      titleScreen();
      startGame();
    }
    waitForVblank();
    
    if (deadcount > 0) {
      for (int i = 1; i < spriteCount; i++) {
        if (sprites[i].state.dead) {
          kills += 1;
          respawnPopo(&sprites[i]);
        }
      }
    }
    handleInput(player);
    updateLink(player);
    updatePopo(popo1);
    updatePopo(popo2);
//    updatePopo(popo3);
//    updatePopo(popo4);
    updateHP();
    updateSprites();

    delay(10);
  }
  
  return 0;
}

