#include <ncurses/ncurses.h>
#include <unistd.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Koor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ArtRegister() {
    Koor(20, 5);  cout << "#####   ######  ##### ####  #### ###### ###### #####   ";
    Koor(20, 6);  cout << " ## ##   ##  # ##  ##  ##  ##  # # ## #  ##  #  ## ##  ";
    Koor(20, 7);  cout << " ## ##   ##    ##      ##  ###     ##    ##     ## ##  ";
    Koor(20, 8);  cout << " ####    ###   ## ###  ##   ###    ##    ###    ####   ";
    Koor(20, 9);  cout << " ## #    ##    ##  ##  ##    ###   ##    ##     ## #   ";
    Koor(20, 10); cout << " ## ##   ##  # ##  ##  ##  #  ##   ##    ##  #  ## ##  ";
    Koor(20, 11); cout << "### ### ######  ####  #### ####   ####  ###### ### ### ";
}

void ArtLogin() {
    Koor(20, 5);  cout << "####    ####   ##### #### ### ### ";
    Koor(20, 6);  cout << " ##    ##  ## ##  ##  ##   ##  #  ";
    Koor(20, 7);  cout << " ##    ##  ## ##      ##   ### #  ";
    Koor(20, 8);  cout << " ##    ##  ## ## ###  ##   # # #  ";
    Koor(20, 9);  cout << " ##  # ##  ## ##  ##  ##   # ###  ";
    Koor(20, 10); cout << " ## ## ##  ## ##  ##  ##   #  ##  ";
    Koor(20, 11); cout << "######  ####   ####  #### ###  #  ";
}


void registration() {
    ofstream file("userdata.txt", ios::app);
    string username;
    system("cls");
	ArtRegister();
    Koor(20, 13); cout << "Register username : ";
    std::cin >> username;
    if (file.is_open()) {
        file << username << endl;
        Koor(20,15);cout << "Registration successful!";
    } else {
        Koor(20,15);cout << "Registration failed!";
    }
    file.close();
    Koor(20,17);cout << "Please wait";
    Sleep(4000);
}

void login() {
    ifstream file("userdata.txt");
    string username, line;
    bool login_success = false;
    system("cls");
	ArtLogin();
    Koor(20, 13); cout << "Enter username : ";
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
        Koor(20,15);cout << "Login successful!";
    } else {
        Koor(20,15);cout << "Username not found";
    }
    Koor(20,17);cout << "Please wait";
    Sleep(4000);
}

int main() {
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
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
                registration();
            } else if (choice == 1) {
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
