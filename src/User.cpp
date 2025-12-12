//
// Created by user on 02.12.2025.
//

#include <iostream>
#include <sstream>
#include "User.h"

using namespace std;

User::User() {
    char choice;
    string line;
    bool exit = false;
    do {
        cout << "Введите фамилию пользователя: ";
        getline(cin, line);
        if (stringstream ss(line); ss >> this->name && !(ss >> line)) {
            break;
        }
        cout << "Неверный ввод имени!\n";
    }while (true);
    do {
        cout << "Введите ID пользователя: ";
        getline(cin, line);
        if (stringstream ss(line); ss >> this->userId && !(ss >> line)) {
            break;
        }
        cout << "Неверный ввод userID!\n";
    }while (true);
    do {
        do {
            cout << "Хотите изменить максимальное количество книг, которое может взять пользователь? (y/n): ";
            getline(cin, line);
            if (stringstream ss(line); ss >> choice && !(ss >> line)) {
                break;
            }
            cout << "Неверный ввод выбора!\n";
        }while (true);

        switch (choice) {
            case 'y':
                do {
                    cout << "Введите максимальное количество книг: ";
                    getline(cin, line);
                    if (istringstream iss(line); iss >> this->maxBooksAllowed && !(iss >> line)) {
                        break;
                    }
                    cout << "Неверный ввод количества книг!\n";
                }while (true);
                exit = true;
                break;
            case 'n':
                cout << "По умолчанию максимальное количество книг равно 3." << endl;
                this->maxBooksAllowed = 3;
                exit = true;
                break;
            default:
                cout << "Неверный ввод. Допустимые ответы: 'y' или 'n'\n";
        }
    }while (!exit);
}

User::User(string name, string userId, int maxBooksAllowed, vector<string>& borrowedBooks)
    : name(std::move(name)), userId(std::move(userId)), borrowedBooks(borrowedBooks), maxBooksAllowed(maxBooksAllowed) {}

bool User::canBorrowMore() const {
    return borrowedBooks.size() < maxBooksAllowed;
}

void User::addBook(const string& isbn) {
    if (canBorrowMore()) {
        borrowedBooks.push_back(isbn);
    } else {
        throw logic_error("Пользователь достиг лимита книг.");
    }
}

void User::removeBook(const string& isbn) {
    for (auto i = 0; i < borrowedBooks.size(); ++i) {
        if (borrowedBooks[i] == isbn) {
            borrowedBooks.erase(borrowedBooks.begin() + i);
            return;
        }
    }
    throw logic_error("Пользователь не брал книгу с таким ISBN.");
}

void User::displayProfile() const {
    cout << "\nUSER" << endl;
    cout << "Name: " << name << endl;
    cout << "UserId: " << userId << endl;
    cout << "BorrowedBooks: ";
    for (int i = 0; i < borrowedBooks.size(); i++) {
        if (i != borrowedBooks.size() - 1) {
            cout << borrowedBooks[i] << " | ";
        }
        else {
            cout << borrowedBooks[i] << endl;
        }
    }
    cout << "MaxBooks: " << maxBooksAllowed << endl;
}
