//
// Created by user on 02.12.2025.
//

#include "Library.h"
#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

Library::Library(vector<Book> books, vector<User>& users, const string &dataFile) :
        books(std::move(books)), users(users), dataFile("../data/library_data.txt") {
    loadFromFile();
}
void Library::BorrowBook(const string& userName, const string &isbn) {
    Book* book = findBookByISBN(isbn);
    User* user = findUserByName(userName);
    if (book == nullptr || user == nullptr) {
        throw runtime_error("Не удалось найти книгу или пользователя");
    }
    user->addBook(isbn);
    book->BorrowBook(userName);
}
void Library::returnBook(const string &isbn) {
    Book* book = findBookByISBN(isbn);
    const string userBorrowedByName = book->getBorrowedBy();
    book->returnBook();
    User* user = findUserByName(userBorrowedByName);
    user->removeBook(isbn);
}
Book* Library::findBookByISBN(const string &isbn) {
    for (auto & book : books) {
        if (isbn == book.getIsbn()) {
            return &book;
        }
    }
    throw runtime_error("Книга не найдена");
}
User* Library::findUserByName(const string &userName) {
    for (auto & user : users) {
        if (user.getName() == userName) {
            return &user;
        }
    }
    throw runtime_error("Пользователь не найден");
}
void Library::displayAllBooks() const {
    cout << "ALL BOOKS" << endl;
    for (auto & book : books) {
        book.displayInfo();
    }
}
void Library::displayAllUsers() const {
    cout << "ALL USERS" << endl;
    for (auto & user : users) {
        user.displayProfile();
    }
}
void Library::saveToFile() const{
    ifstream file(dataFile);
    string line;
    string oldFile;
    while (true) {
        getline(file, line);
        if (line == "---USERS---\n") {
            break;
        }
    }
    while (getline(file, line)) {
        oldFile += line;
    }
    file.close();
    ofstream out(dataFile);
    if (!out.is_open())
        throw runtime_error("Не удалось открыть файл");
    for (auto & book : books) {
        out << "BOOK" << endl
        << "Title: " << book.getTitle() << endl
        << "Author: " << book.getAuthor() << endl
        << "Year" << book.getYear() << endl
        << "ISBN: " << book.getIsbn() << endl
        << "Available: " << book.getIsAvailable() << endl
        << "BorrowedBy: " << book.getBorrowedBy() << endl;
    }
    out << "---USERS---" << endl;
    for (auto & user : users) {
        out << endl << "USER" << endl
        << "Name: " << user.getName() << endl
        << "UserID: " << user.getUserId() << endl
        << "BorrowedBooks: ";
        for (int i = 0; i != user.getBorrowedBooks().size(); ++i) {
            if (i != user.getBorrowedBooks().size() - 1) {
                out << user.getBorrowedBooks()[i] << '|';
            }
            else {
                out << user.getBorrowedBooks()[i] << endl;
            }
        }
        out << "MaxBooks: " << user.getMaxBooksAllowed() << endl;
    }
    out.close();
}
void Library::loadFromFile() {
    system("chcp 65001");  // Настройка консоли на UTF-8
    ifstream file(dataFile);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл");
    }
    string line;
    while (getline(file, line)) {
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
}