//
// Created by user on 02.12.2025.
//

#include <windows.h>
#include "User.cpp"
#include "Book.cpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    system("chcp 65001");  // Настройка консоли на UTF-8
    ifstream file("../data/library_data.txt");
    if (!file.is_open()) {
        cout << "File could not be opened" << endl;
        return 1;
    }
    string line;
    vector<Book> books;
    vector<User> users;
    while (getline(file, line)){
        if (line == "BOOK") {
            string t, a, is, string_y;
            getline(file, line);
            t = line.substr(line.find(':') + 2);
            getline(file, line);
            a = line.substr(line.find(':') + 2);
            getline(file, line);
            string_y = line.substr(line.find(':') + 2);
            getline(file, line);
            is = line.substr(line.find(':') + 2);
            Book Newbook(t, a, stoi(string_y), is);
            books.push_back(Newbook);
        }
        if (line == "USER") {
            string n, id, maxBooks;
            getline(file, line);
            n = line.substr(line.find(':') + 2);
            getline(file, line);
            id = line.substr(line.find(':') + 2);
            getline(file, line);
            maxBooks = line.substr(line.find(':') + 2);
            User Newuser(n, id, stoi(maxBooks));
            users.push_back(Newuser);
        }
    }
    file.close();
    for (const auto & book : books) {
        book.displayInfo();
    }
    for (const auto & user : users) {
        user.displayProfile();
    }

    return 0;
}