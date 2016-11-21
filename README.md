#Link to the Past Battle

![alt text](https://raw.githubusercontent.com/lukebaggett/Link-to-the-Past-Battle/master/images/gameplay.gif "Gameplay")

This is a small homework assignment I did for the GA Tech CS 2110 course.

It's a simple Game Boy Advance game written in C. Sprites and the background are taken from [this game](https://en.wikipedia.org/wiki/The_Legend_of_Zelda:_A_Link_to_the_Past).

###Quick Play in a Web Browser
Download [LTTPBattle.gba](https://github.com/lukebaggett/Link-to-the-Past-Battle/blob/master/LTTPBattle.gba) and use this emulator: http://endrift.github.io/gbajs/

###Installation
    Install these packages:
      libmagick++-dev libmagickwand-dev libmagickcore-dev
    Install cs2110-tools and cs2110-tools-emulator in the packages directory.
    Run:
      make vba

###Controls
    START - Start the game
    SELECT - Reset the game
    A - Sword Attack
    UP - Move Up
    DOWN - Move Down
    LEFT - Move Left
    RIGHT - Move Right

###How to Win
  Defeat all 10 of the enemies called "Popos"
  It's made to be easy.

###How to Lose
  If a Popo hits you while moving towards you, you lose a heart.
  Lose 3 hearts to lose.

