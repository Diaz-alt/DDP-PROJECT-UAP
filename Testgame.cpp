#include <ncurses/ncurses.h>
#include <unistd.h>
#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;

const int rows = 12;
const int cols = 15;

char labirin[rows][cols] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#','#'},
    {'#', 'S', ' ', ' ', '#', ' ', '#', ' ', '#', '#','#', '#', '#', '#','#'},
    {'#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#','#', '#', '#', '#','#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#','#', '#', '#', '#','#'},
    {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#','#', ' ', ' ', ' ','#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#','#', ' ', '#', ' ','#'},
    {'#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#','#', ' ', '#', 'E','#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', ' ',' ', ' ', '#', '#','#'},
    {'#', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', '#','#', '#', '#', ' ','#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#','#', '#', '#', ' ','#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ','#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#','#'}
};

int playerRow = 1, playerCol = 1;

void KOOR(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printLabirin() {
    system("cls");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == playerRow && j == playerCol)
                cout << "P ";
            else
                cout << labirin[i][j] << " ";
        }
        cout << endl;
    }
}

void movePlayer(char direction) {
    int newRow = playerRow;
    int newCol = playerCol;

    if (direction == 'w') newRow--;
    else if (direction == 's') newRow++;
    else if (direction == 'a') newCol--;
    else if (direction == 'd') newCol++;

    if (labirin[newRow][newCol] == ' ' || labirin[newRow][newCol] == 'E') {
        playerRow = newRow;
        playerCol = newCol;
    }
}

void Hello(){
    cout << "\e[33m";
    KOOR(33, 10); cout <<    " ____  ____   ________   _____      _____        ___    ";
    Sleep(100);
    KOOR(33, 11); cout <<    "|_   ||   _| |_   __  | |_   _|    |_   _|     .'   `.  ";
    Sleep(100);
    KOOR(33, 12); cout <<   "  | |__| |     | |_ \\_|   | |        | |      /  .-.  \\
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

void easy() {
    cout << "=== Labirin Mode Easy ===" << endl;
    cout << "Gunakan WASD untuk bergerak dan cari jalan ke E!" << endl;

    while (true) {
        printLabirin();
        char input = getch();
        movePlayer(input);

        if (labirin[playerRow][playerCol] == 'E') {
            printLabirin();
            cout << "Selamat! Anda berhasil menyelesaikan labirin!" << endl;
            break;
        }
    }
}

void normal(){

}

void hard(){

}

void gamemode(){
    system("cls");
    const char* options[] = { "Easy", "Normal", "Hard", "Cancel"};
    curs_set(0);
    noecho();
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
            endwin();
            if(choice == 0){
                curs_set(0);
                noecho();
                easy();
            } else if(choice == 1) {
                curs_set(0);
                noecho();
                normal();
            } else if(choice == 2) {
                curs_set(0);
                noecho();
                hard();
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
    ifstream fileread("user.txt",ios::app);
    ofstream file("user.txt", ios::app);
    string username;
    string line;
    int cek;
    system("cls");
    RegisART();
    KOOR(20, 13); cout << "Enter a username to register : ";
    cin >> username;
    if(fileread.is_open()){
        while(getline(fileread, line)){
            cek=1;
            break;
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
