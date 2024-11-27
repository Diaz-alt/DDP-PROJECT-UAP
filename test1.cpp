#include <ncurses/ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

#define USER_FILE "user_data.txt"

void loading_screen() {
    const std::string loading_text = "Memuat, harap tunggu...";
    for (size_t i = 0; i < loading_text.length(); ++i) {
        mvaddch(10, i + 10, loading_text[i]);
        refresh();
        usleep(100000); 
    }
    sleep(2); 
}

bool register_user() {
    std::string username, password;

    echo();  
    mvprintw(5, 10, "Masukkan nickname: ");
    refresh();
    char uname[50];
    scanw("%s", uname);
    username = std::string(uname);

    mvprintw(7, 10, "Masukkan password: ");
    refresh();
    noecho();  
    char pass[50];
    scanw("%s", pass);
    password = std::string(pass);

    std::ofstream user_file(USER_FILE, std::ios::app);
    if (user_file.is_open()) {
        user_file << username << " " << password << "\n";
        user_file.close();
        return true;
    } else {
        return false;
    }
}

bool login_user() {
    std::string username, password;
    std::string file_username, file_password;

    echo();  
    mvprintw(5, 10, "Masukkan username: ");
    refresh();
    char uname[50];
    scanw("%s", uname);
    username = std::string(uname);

    mvprintw(7, 10, "Masukkan password: ");
    refresh();
    noecho();  
    char pass[50];
    scanw("%s", pass);
    password = std::string(pass);

    std::ifstream user_file(USER_FILE);
    if (user_file.is_open()) {
        while (user_file >> file_username >> file_password) {
            if (file_username == username && file_password == password) {
                user_file.close();
                return true;
            }
        }
        user_file.close();
    }
    return false;
}

void main_menu() {
    int choice;

    while (true) {
        clear();
        mvprintw(3, 10, "Selamat datang di Game SOS!");
        mvprintw(4, 10, "=========================");
        mvprintw(6, 10, "1. Registrasi");
        mvprintw(7, 10, "2. Login");
        mvprintw(8, 10, "3. Exit");
        mvprintw(10, 10, "Masukkan pilihan opsi (1-3): ");
        refresh();

        choice = getch();

        if (choice == '1') {
            if (register_user()) {
                mvprintw(12, 10, "Registrasi berhasil! Tekan enter untuk melanjutkan...");
                refresh();
                getch();
            } else {
                mvprintw(12, 10, "Gagal menyimpan data pengguna! Tekan enter untuk mencoba lagi...");
                refresh();
                getch();
            }
       } else if (choice == '2') {
                if (login_user()) {
                    mvprintw(12, 10, "Login berhasil! Tekan enter untuk melanjutkan...");
                    refresh();
                    getch();
                    loading_screen();  
                    return;  
                } else {
                    mvprintw(12, 10, "Login gagal! Tekan enter untuk mencoba lagi...");
                    refresh();
                    getch();
                }
       } else if (choice == '3') {
                mvprintw(12, 10, "Terima kasih telah bermain! Tekan enter untuk keluar...");
                refresh();
                getch();
                endwin();  
                exit(0);
       } else {
                mvprintw(12, 10, "Pilihan tidak valid! Tekan enter untuk mencoba lagi...");
                refresh();
                getch();
        }
    }
}

int main() {
    initscr();          
    cbreak();           
    noecho();           
    curs_set(0);       

    main_menu();       

    endwin();         
    return 0;
}
