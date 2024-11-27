#include <ncurses/ncurses.h>
#include <iostream>
#include <fstream>
#include <widows.h>
using namespace std;

void koordinat(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetSdHandle(STD_OUTPUT_HANDLE), coord);
}
