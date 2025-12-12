//
// Created by user on 02.12.2025.
//

#include <iostream>
#include <sstream>
#include <string>
#include "User.h"

using namespace std;

User::User() {
    char choice;
    string line;
    bool exit = false;
    do {
        cout << "\nВведите фамилию пользователя: ";
        getline(cin, line);
        if (stringstream ss(line); ss >> this->name && !(ss >> line)) {
            break;
        }
        cout << "\nНеверный ввод имени!";
    }while (true);
    do {
        cout << "\nВведите ID пользователя: ";
        getline(cin, line);
        if (stringstream ss(line); ss >> this->userId && !(ss >> line)) {
            break;
        }
        cout << "\nНеверный ввод userID!\n";
    }while (true);
    do {
        do {
            cout << "\nХотите изменить максимальное количество книг, которое может взять пользователь? (y/n): ";
            getline(cin, line);
            if (stringstream ss(line); ss >> choice && !(ss >> line)) {
                break;
            }
            cout << "\nНеверный ввод выбора!";
        }while (true);

        switch (choice) {
            case 'y':
                do {
                    cout << "\nВведите максимальное количество книг: ";
                    getline(cin, line);
                    if (istringstream iss(line); iss >> this->maxBooksAllowed && !(iss >> line)) {
                        break;
                    }
                    cout << "\nНеверный ввод количества книг!";
                }while (true);
                exit = true;
                break;
            case 'n':
                cout << "\nПо умолчанию максимальное количество книг равно 3." << endl;
                this->maxBooksAllowed = 3;
                exit = true;
                break;
            default:
                cout << "\nНеверный ввод. Допустимые ответы: 'y' или 'n'\n";
        }
    }while (!exit);
}

User::User(string name, string userId, int maxBooksAllowed, vector<string>& borrowedBooks)
    : name(std::move(name)), userId(std::move(userId)), borrowedBooks(borrowedBooks), maxBooksAllowed(maxBooksAllowed) {}

string User::getName() const { return name; }
string User::getUserId() const { return userId; }
vector<string> User::getBorrowedBooks() const { return borrowedBooks; }
int User::getMaxBooksAllowed() const { return maxBooksAllowed; }


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
    cout << "\nUSER";
    cout << "\nName: " << name;
    cout << "\nUserId: " << userId;
    cout << "\nBorrowedBooks: ";
    for (int i = 0; i < borrowedBooks.size(); i++) {
        if (i != borrowedBooks.size() - 1) {
            cout << borrowedBooks[i] << " | ";
        }
        else {
            cout << borrowedBooks[i];
        }
    }
    cout << "\nMaxBooks: " << maxBooksAllowed << endl;
}
