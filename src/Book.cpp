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
    cout << "\nВведите название книги: ";
    getline(cin, this->title);

    cout << "\nВведите автора книги: ";
    getline(cin, this->author);

    do {
        cout << "\nВведите год издания книги: ";
        getline(cin, line);
        if (istringstream iss(line); iss >> this->year && !(iss >> line) &&
            this->year >= 1450 && 2025 >= this->year) {
            break;
            }
        if (this->year <= 1450 || 2025 <= this->year) {
            cout << "\nВременные рамки не соотносятся!";
        }
        else {
            cout << "\nНеправильный ввод года!";
        }
    }while (true);

    cout << "\nВведите номер ISBN: ";
    getline(cin, this->isbn);
    cout << endl;
}

Book::Book(string title, string author, const int year, string isbn)
    : title(std::move(title)), author(std::move(author)),
      year(year), isbn(std::move(isbn)) {

    if (!(1450 <= year && year <= 2025)) {
        throw invalid_argument("\nВременные рамки книги в файле не соотносятся!");
    }
}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
string Book::getIsbn() const { return isbn; }
bool Book::getIsAvailable() const { return isAvailable; }
string Book::getBorrowedBy() const { return borrowedBy; }

void Book::borrowBook(const string& userName) {
    if (!isAvailable) {
        throw logic_error("\nКнига недоступна (уже выдана)");
    }
    borrowedBy = userName;
    isAvailable = false;
}

void Book::returnBook() {
    if (isAvailable) {
        throw logic_error("\nКнига уже возвращена");
    }
    borrowedBy = "";
    isAvailable = true;
}

void Book::displayInfo() const {
    cout << "\nBOOK";
    cout << "\nTitle: " << title;
    cout << "\nAuthor: " << author;
    cout << "\nYear: " << year;
    cout << "\nISBN: " << isbn;
    if (!isAvailable) {
        cout << "\nAvailable: " << "no";
        cout << "\nBook borrowed by: " << borrowedBy;
    }
    else {
        cout << "\nAvailable: yes";
        cout << "\nBorrowed by: " << endl;
    }
}

