#include <ncurses/ncurses.h>
#include <unistd.h>
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;

void KOOR(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Hello(){
    cout << "\e[33m";
    KOOR(33, 10); cout <<    " ____  ____   ________   _____      _____        ___    ";
    Sleep(100);
    KOOR(33, 11); cout <<    "|_   ||   _| |_   __  | |_   _|    |_   _|     .'   `.  ";
    Sleep(100);
    KOOR(33, 12); cout <<   "  | |__| |     | |_ \\_|   | |        | |      /  .-.  \\ ";
    Sleep(100);
    KOOR(33, 13); cout <<    "  |  __  |     |  _| _    | |   _    | |   _  | |   | | ";
    Sleep(100);
    KOOR(33, 14); cout <<    " _| |  | |_   _| |__/ |  _| |__/ |  _| |__/ | \\  `-'  / ";
    Sleep(100);
    KOOR(33, 15); cout <<    "|____||____| |________| |________| |________|  `.___.'  ";
    Sleep(3000);
    cout << "\e[0m";
    system("cls");
}
void loading(){
    mvprintw(15, 70, "Loading...");
        mvprintw(16, 60, "-----------------------------");
        mvprintw(17, 59, "|                             |");
        mvprintw(18, 60, "-----------------------------");

    for(int j = 0; j < 29; j++){
        attron(COLOR_PAIR(2));
        mvprintw(17, 60 + j, " ");
        refresh();
        Sleep(100);
    }
}

void RegisART() {
    cout << "\e[33m";
    KOOR(20, 5);  cout << "#####   ######  ##### ####  #### ###### ###### #####   ";
    KOOR(20, 6);  cout << " ## ##   ##  # ##  ##  ##  ##  # # ## #  ##  #  ## ##  ";
    KOOR(20, 7);  cout << " ## ##   ##    ##      ##  ###     ##    ##     ## ##  ";
    KOOR(20, 8);  cout << " ####    ###   ## ###  ##   ###    ##    ###    ####   ";
    KOOR(20, 9);  cout << " ## #    ##    ##  ##  ##    ###   ##    ##     ## #   ";
    KOOR(20, 10); cout << " ## ##   ##  # ##  ##  ##  #  ##   ##    ##  #  ## ##  ";
    KOOR(20, 11); cout << "### ### ######  ####  #### ####   ####  ###### ### ### ";
    cout << "\e[0m";
}

void LoginART() {
    cout << "\e[33m";
    KOOR(20, 5);  cout << "####    ####   ##### #### ### ### ";
    KOOR(20, 6);  cout << " ##    ##  ## ##  ##  ##   ##  #  ";
    KOOR(20, 7);  cout << " ##    ##  ## ##      ##   ### #  ";
    KOOR(20, 8);  cout << " ##    ##  ## ## ###  ##   # # #  ";
    KOOR(20, 9);  cout << " ##  # ##  ## ##  ##  ##   # ###  ";
    KOOR(20, 10); cout << " ## ## ##  ## ##  ##  ##   #  ##  ";
    KOOR(20, 11); cout << "######  ####   ####  #### ###  #  ";
    cout << "\e[0m";
}
