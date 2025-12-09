//
// Created by user on 02.12.2025.
//

#include "Book.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

Book::Book() {
    string line;
    cout << "Введите название книги: ";
    getline(cin, this->title);

    cout << "Введите автора книги: ";
    getline(cin, this->author);

    do {
        cout << "Введите год издания книги: ";
        getline(cin, line);
        if (istringstream iss(line); iss >> this->year && !(iss >> line) &&
            this->year >= 1450 && 2025 >= this->year) {
            break;
        }
        if (this->year <= 1450 && 2025 <= this->year) {
            cout << "Временные рамки не соотносятся!\n";
        }
        else {
            cout << "Неправильный ввод года!\n";
        }
    }while (true);

    cout << "Введите номер ISBN: ";
    getline(cin, this->isbn);
    cout << endl;
}

Book::Book(string title, string author, const int year, string isbn)
    : title(std::move(title)), author(std::move(author)),
      year(year), isbn(std::move(isbn)) {

    if (!(1450 <= year && year <= 2025)) {
        throw invalid_argument("Временные рамки не соотносятся!");
    }
}

void Book::borrowBook(const string& userName) {
    if (!isAvailable) {
        throw logic_error("Книга недоступна (уже выдана)");
    }
    borrowedBy = userName;
    isAvailable = false;
}

void Book::returnBook() {
    if (isAvailable) {
        throw logic_error("Книга уже возвращена");
    }
    borrowedBy = "";
    isAvailable = true;
}

void Book::displayInfo() const {
    cout << "\nBOOK" << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << year << endl;
    cout << "ISBN: " << isbn << endl;
    if (!isAvailable) {
        cout << "Available: " << "no" << endl;
        cout << "Book borrowed by: " << borrowedBy <<  endl;
    }
    else {
        cout << "Available: yes" << endl;
        cout << "Borrowed by: " << endl;
    }
}
