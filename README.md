# Arcade

### Binary name: arcade
### Language: C++
### Compilation: CMake

## Description:
Arcade is a gaming platform and program that lets the user choose a game to play and keeps a register of player scores.

## Usage:
It take as its argument the graphics library to be used at the start. It is possible to change the graphics library at run-time.
After pressing enter, you will be able to see boxes showing you the available graphics libraries, games, and previous players scores.
You may then select a game and/or change the graphics library if you deisre. Another box will also be present, allowing you to enter your name.
In case of confusion or curiosity, a document detailing the ins and outs of this program is available in the doc directory: ./doc/Documentation.pdf

## Dependencies:
#### SDL2
#### SDL2_ttf
#### SDL2_image

## Execution:
#### cmake -S. -B build
#### cmake --build build
#### ./arcade libraryPath

## Available library paths:
#### lib/arcade_ncurses.so
#### lib/arcade_sfml.so
#### lib/arcade_sdl2.so

## Special Keys:
#### ESC - exit program
#### M - back to menu
#### R - restart current game
#### L - switch graphics libraries during game
#### G - switch games while playing

### Email address of the team leader of the group we collaborated with for the interface: tom.mendy@epitech.eu
