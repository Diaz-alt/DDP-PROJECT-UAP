#include <ncurses/ncurses.h>
#include <unistd.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
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


void registration() {
	curs_set(1);
    ofstream file("userdata.txt", ios::app);
    string username;
    system("cls");
	RegisART();
    KOOR(20, 13); cout << "Enter a username to register : ";
    cin >> username;
    if (file.is_open()) {
        file << username << endl;
        KOOR(20,15);cout << "Registration successful!";
    } else {
        KOOR(20,15);cout << "Error opening file!";
    }
    file.close();
    KOOR(20,17);cout << "Please wait";
    Sleep(5000);
}

void login() {
	curs_set(1);
    ifstream file("userdata.txt");
    string username, line;
    bool login_success = false;
    system("cls");
    LoginART();
    KOOR(20, 13); cout << "Enter your username : ";
    cin >> username;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == username) {
                login_success = true;
                break;
            }
        }
        file.close();
    }

    if (login_success) {
        KOOR(20,15);cout << "Login successful!";
    } else {
        KOOR(20,15);cout << "Username not found";
    }
    KOOR(20,17);cout << "Please wait";
    Sleep(5000);
}

int main() {
    system("cls");
    Hello();
    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    loading();
    bkgd(COLOR_PAIR(1));
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    const char* options[] = { "Register", "Login", "Exit" };
    int choice = 0;
    int key;

    while (true) {
        clear();
        mvprintw(5, 10, "Welcome");
        for (int i = 0; i < 3; i++) {
            if (i == choice)
                attron(A_REVERSE);
            mvprintw(7 + i, 12, options[i]);
            attroff(A_REVERSE);
        }
        key = getch();

        if (key == KEY_DOWN) {
            choice = (choice + 1) % 3;
        } else if (key == KEY_UP) {
            choice = (choice + 2) % 3;
        } else if (key == '\n') {
            endwin();
            if (choice == 0) {
            	    curs_set(1);
                registration();
            } else if (choice == 1) {
            	    curs_set(1);
                login();
            } else if (choice == 2) {
                break;
            }
            initscr();
            bkgd(COLOR_PAIR(1));
            keypad(stdscr, TRUE);
        }
    }
    endwin();
    return 0;
}
