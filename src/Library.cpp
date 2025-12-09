//
// Created by user on 02.12.2025.
//

#include "Library.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <sstream>

using namespace std;

Library::Library(vector<Book> books, vector<User> users, string  dataFile)
    : books(std::move(books)), users(std::move(users)), dataFile(std::move(dataFile)) {
    loadFromFile();
}

void Library::addBook(const Book& book) {
    books.push_back(book);
    cout << "Книга добавлена в библиотеку!" << endl;
}

void Library::addUser(const User& user) {
    users.push_back(user);
    cout << "Пользователь зарегистрирован!" << endl;
}

void Library::borrowBook(const string& userName, const string& isbn) {
    Book* book = findBookByISBN(isbn);
    User* user = findUserByName(userName);
    user->addBook(isbn);
    book->borrowBook(userName);
    cout << "Книга '" << isbn << "' выдана пользователю '" << userName << "'" << endl;
}

void Library::returnBook(const string& isbn) {
    Book* book = findBookByISBN(isbn);
    const string userName = book->getBorrowedBy();
    book->returnBook();
    User* user = findUserByName(userName);
    user->removeBook(isbn);

    cout << "Книга '" << isbn << "' возвращена пользователем '" << userName << "'" << endl;
}

Book* Library::findBookByISBN(const string& isbn) {
    for (auto& book : books) {
        if (book.getIsbn() == isbn) {
            return &book;
        }
    }
    throw logic_error("Книга с ISBN '" + isbn + "' не найдена");
}

User* Library::findUserByName(const string& name) {
    for (auto& user : users) {
        if (user.getName() == name) {
            return &user;
        }
    }
    throw logic_error("Пользователь '" + name + "' не найден");
}

void Library::displayAllBooks() const {
    cout << "\n=== ВСЕ КНИГИ ===" << endl;
    if (books.empty()) {
        cout << "Книг нет" << endl;
    } else {
        for (const auto& book : books) {
            book.displayInfo();
        }
    }
}

void Library::displayAllUsers() const {
    cout << "\n=== ВСЕ ПОЛЬЗОВАТЕЛИ ===" << endl;
    if (users.empty()) {
        cout << "Пользователей нет" << endl;
    } else {
        for (const auto& user : users) {
            user.displayProfile();
        }
    }
}

void Library::saveToFile() const {
    ofstream out(dataFile);
    if (!out.is_open()) {
        cout << "Не удаётся открыть файл для записи, создаётся новый файл";
    }

    // Сохранение книг
    for (const auto& book : books) {
        out << "BOOK" << endl;
        out << "Title: " << book.getTitle() << endl;
        out << "Author: " << book.getAuthor() << endl;
        out << "Year: " << book.getYear() << endl;
        out << "ISBN: " << book.getIsbn() << endl;
        out << "Available: " << book.getIsAvailable() << endl;
        out << "BorrowedBy: " << book.getBorrowedBy() << endl << endl;
    }

    // Сохранение пользователей
    out << "---USERS---" << endl;
    for (const auto& user : users) {
        out << "USER" << endl;
        out << "Name: " << user.getName() << endl;
        out << "UserID: " << user.getUserId() << endl;
        out << "MaxBooks: " << user.getMaxBooksAllowed() << endl;

        const auto& borrowedBooks = user.getBorrowedBooks();
        if (!borrowedBooks.empty()) {
            out << "BorrowedBooks: ";
            for (size_t i = 0; i < borrowedBooks.size(); ++i) {
                out << borrowedBooks[i];
                if (i < borrowedBooks.size() - 1) out << " | ";
            }
            out << endl;
        } else {
            out << "BorrowedBooks: " << endl;
        }
        out << endl;
    }
    out.close();
    cout << "Данные сохранены в файл: " << dataFile << endl;
}

void Library::loadFromFile() {
    ifstream file(dataFile);
    if (!file.is_open()) {
        cout << "Файл не найден, создаётся пустой файл: " << dataFile << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line == "BOOK") {
            string title, author, string_year, isbn;
            bool available;
            string borrowedBy;
            getline(file, line); title = line.substr(line.find(':') + 2);
            getline(file, line); author = line.substr(line.find(':') + 2);
            getline(file, line); string_year = line.substr(line.find(':') + 2);
            getline(file, line); isbn = line.substr(line.find(':') + 2);
            getline(file, line); available = line.substr(line.find(':') + 2) == "true";
            getline(file, line); borrowedBy = line.substr(line.find(':') + 2);

            Book newBook(title, author, stoi(string_year), isbn);
            if (!available) {
                newBook.borrowBook(borrowedBy);
            }
            books.push_back(newBook);
        }
        else if (line == "USER") {
            string name, userId, maxBooksStr;
            stringstream allID;
            vector<string> borrowedBooks;
            getline(file, line); name = line.substr(line.find(':') + 2);
            getline(file, line); userId = line.substr(line.find(':') + 2);
            getline (file, line);
            allID = stringstream(line.substr(line.find(':') + 2));
            while (getline(allID, line, '|')) {
                borrowedBooks.push_back(line);
            }
            getline(file, line); maxBooksStr = line.substr(line.find(':') + 2);
            User newUser(name, userId, stoi(maxBooksStr), borrowedBooks);
            users.push_back(newUser);
        }
    }
    file.close();
}
