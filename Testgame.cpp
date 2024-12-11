#include <iostream>
#include <conio.h>
using namespace std;

const int rows = 10;
const int cols = 10;

char labirin[rows][cols] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'S', ' ', ' ', '#', ' ', '#', ' ', 'E', '#'},
    {'#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#'},
    {'#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int playerRow = 1, playerCol = 1;

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

int main() {
    cout << "=== Labirin Mode Medium ===" << endl;
    cout << "Gunakan WASD untuk bergerak dan cari jalan ke E!\n";

    while (true) {
        printLabirin();
        char input = _getch();
        movePlayer(input);

        if (labirin[playerRow][playerCol] == 'E') {
            printLabirin();
            cout << "Selamat! Anda berhasil menyelesaikan labirin!" << endl;
            break;
        }
    }

    return 0;
}
