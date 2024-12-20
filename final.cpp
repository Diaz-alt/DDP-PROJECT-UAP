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
    mvprintw(12, 55, "Loading...");
        mvprintw(13, 45, "-----------------------------");
        mvprintw(14, 44, "|                             |");
        mvprintw(15, 45, "-----------------------------");

    for(int j = 0; j < 29; j++){
        attron(COLOR_PAIR(2));
        mvprintw(14, 45 + j, " ");
        refresh();
        Sleep(100);
    }
    Sleep(2000);
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

string user = "guest";

template <size_t Height, size_t Width>
void maze(const char (&maze)[Height][Width]) {
    clear();
    for (int y = 0; y < Height; y++) {
        for (int x = 0; x < Width; x++) {
            mvaddch(y, x, maze[y][x]);
        }
    }
    refresh();
}

template <size_t height, size_t width>
void movePlayer(const char (&maze)[height][width]) {
    int x = 1, y = 1;
    int key;

    while ((key = getch()) != 27) {
        mvaddch(y, x, ' ');

        switch (key) {
        case KEY_UP:
            if (y > 0 && (maze[y - 1][x] == ' ' || maze[y - 1][x] == 'X')) y--;
            break;
        case KEY_DOWN:
            if (y < height - 1 && (maze[y + 1][x] == ' ' || maze[y + 1][x] == 'X')) y++;
            break;
        case KEY_LEFT:
            if (x > 0 && (maze[y][x - 1] == ' ' || maze[y][x - 1] == 'X')) x--;
            break;
        case KEY_RIGHT:
            if (x < width - 1 && (maze[y][x + 1] == ' ' || maze[y][x + 1] == 'X')) x++;
            break;
        }
        mvaddch(y, x, 'O');
        refresh();

        if (maze[y][x] == 'X') {
            clear();
            mvprintw(height / 2, (width - 10) / 2, "Finished the maze");
            refresh();
            Sleep(2000);
            break;
        }
    }
    clear();
    mvprintw((height / 2) + 1, (width -9) / 2, "Please Wait...");
    mvprintw((height / 2) + 3, (width -9) / 2, "Back to Main Menu");
    refresh();
    Sleep(3000);
}

const char easy[13][15] = {
    {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
    {'|', 'O', ' ', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|'},
    {'|', '|', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', '|', ' ', '|'},
    {'|', ' ', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', '|', '|', ' ', '|', ' ', '|'},
    {'|', '|', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', ' ', '|', 'X', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', '|'},
    {'|', ' ', ' ', ' ', '|', '|', '|', ' ', ' ', '|', '|', '|', '|', ' ', '|'},
    {'|', ' ', '|', '|', '|', '|', '|', '|', ' ', '|', '|', '|', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
    {'P', 'r', 'e', 's', 's', ' ', 'E', 's', 'c', '=', 'B', 'a', 'c', 'k', '*'}
};

const char medium[21][20] = {
    {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
    {'|', 'O', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'X', '|'},
    {'|', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', ' ', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', '|'},
    {'|', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', '|'},
    {'|', '|', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', '|'},
    {'|', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', '|', ' ', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', '|', '|', ' ', ' ', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', ' ', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', '|', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
    {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
    {'P', 'r', 'e', 's', 's', ' ', 'E', 's', 'c', '=', 'B', 'a', 'c', 'k', '*', ' ', ' ', ' ', ' ', ' '}
};

const char hard[21][30] = {
    {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
    {'|', 'O', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', ' ', '|', 'X', '|'},
    {'|', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '|', '|', '|', '|'},
    {'|', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', '|', '|', ' ', ' ', ' ', ' ', '|', '|'},
    {'|', '|', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', '|', '|', ' ', '|'},
    {'|', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', ' ', '|', '|', ' ', '|', ' ', '|', '|', ' ', '|', ' ', '|', ' ', ' ', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', '|', '|', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', '|', '|', '|', ' ', '|', '|'},
    {'|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', ' ', '|', ' ', '|', '|', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', '|', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|'},
    {'|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', ' ', '|', '|', '|', '|', '|', ' ', '|', '|', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|'},
    {'|', '|', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', '|', '|', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|'},
    {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
    {'P', 'r', 'e', 's', 's', ' ', 'E', 's', 'c', '=', 'B', 'a', 'c', 'k', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

void gamemode(){
    system("cls");
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    const char* options[] = { "Easy", "Normal", "Hard", "Cancel"};
    int choice = 0;
    int key;
    while (true) {
        clear();
        for (int i = 0; i < 4; i++) {
            if (i == choice)
                attron(A_REVERSE);
            mvprintw(7 + i, 12, options[i]);
            attroff(A_REVERSE);
        }
        key = getch();
        
        if (key == KEY_DOWN) {
            choice = (choice + 1) % 4;
        } else if (key == KEY_UP) {
            choice = (choice + 3) % 4;
        } else if (key == 10) {
            if(choice == 0){
                noecho();
                curs_set(1);
                curs_set(0);
                maze(easy);
            movePlayer(easy);
            break;
            } else if(choice == 1) {
                noecho();
                curs_set(1);
                curs_set(0);
                maze(medium);
            movePlayer(medium);
            break;
            } else if(choice == 2) {
                noecho();
                curs_set(1);
            	curs_set(0);
                maze(hard);
            movePlayer(hard);
            break;
            } else if(choice == 3) {
                system("cls");
                KOOR(20, 9);    cout << "==============";
                KOOR(20, 10);   cout << "Please wait...";
                KOOR(20, 11);   cout << "==============";
                Sleep(2000);
                system("cls");
                break;
            }
            curs_set(0);
            noecho();
        }
    }
}

void registration() {
	curs_set(1);
    ifstream fileread("user.txt");
    ofstream file("user.txt", ios::app);
    string username;
    string line;
    int cek = 0;
    system("cls");
	RegisART();
    KOOR(20, 13); cout << "Enter a username to register : ";
    cin >> username;
    if(fileread.is_open()){
        while(getline(fileread, line)){
            if(line == username){
            cek = 1;
            break;
            }
        }
    }
    fileread.close();
    if(cek==1){
        KOOR(20, 15); cout << "Username already registered";
        KOOR(20, 16); cout << "Registration failed!";
    } else {
        if(file.is_open()){
            file << username << endl;
            KOOR(20, 15); cout << "Registration successful!";
        }
        file.close();
    }
    KOOR(20,17);cout << "Please wait...";
    Sleep(5000);
}

void login() {
	curs_set(1);
    ifstream fileread("user.txt");
    string username, line;
    bool login_success = false;
    system("cls");
    LoginART();
    KOOR(20, 13); cout << "Enter your username : ";
    cin >> username;

    if (fileread.is_open()) {
        while (getline(fileread, line)) {
            if (line == username) {
                login_success = true;
                user = username;
                break;
            }
        }
        fileread.close();
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

    const char* options[] = { "Play", "Register", "Login", "Exit" };
    int choice = 0;
    int key;

    while (true) {
        clear();
        mvprintw(5, 10, ("Welcome, " + user + "!").c_str());
        for (int i = 0; i < 4; i++) {
            if (i == choice)
                attron(A_REVERSE);
            mvprintw(7 + i, 12, options[i]);
            attroff(A_REVERSE);
        }
        key = getch();

        if (key == KEY_DOWN) {
            choice = (choice + 1) % 4;
        } else if (key == KEY_UP) {
            choice = (choice + 3) % 4;
        } else if (key == 10) {
            endwin();
            if(choice == 0){
                    gamemode();
            } else if(choice == 1) {
            	    curs_set(0);
                    noecho();
                registration();
            } else if(choice == 2) {
            	    curs_set(0);
                    noecho();
                login();
            } else if(choice == 3) {
                system("cls");
                KOOR(20, 10); cout << "Thank you!";
                Sleep(3000);
                system("cls");
                break;
            }
            initscr();
            curs_set(0);
            noecho();
            bkgd(COLOR_PAIR(1));
            keypad(stdscr, TRUE);
        }
    }
    endwin();
    return 0;
}
