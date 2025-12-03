//
// Created by user on 02.12.2025.
//

#include "Book.h"
#include <iostream>
#include <ctime>

using namespace std;

Book::Book(string  title, string  author,
    const int year, string  isbn) : title(std::move(title)), author(std::move(author)),
                            year(year), isbn(std::move(isbn)), isAvailable(true) {
    const time_t t = time(nullptr);
    if (!(1450 <= year && year <= 1900 + localtime(&t)->tm_year)) {
        throw invalid_argument("Wrong year");
    }
    this->year = year;
}
void Book::BorrowBook(const std::string& userName) {
    if (!isAvailable) {
        throw invalid_argument("Book is not available");
    }
    borrowedBy = userName;
    }
void Book::returnBook() {
    if (isAvailable) {
        throw invalid_argument("Book is already returned");
    }
    borrowedBy = "";
    isAvailable = true;
}
void Book::displayInfo() const {
    cout << "===== Info about book =====" << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << year << endl;
    cout << "Isbn: " << isbn << endl;
    if (!isAvailable) {
        cout << "Book is not available to take" << endl;
        cout << "Book borrowed by: " << borrowedBy << endl;
    }
    else {
        cout << "Book is available to take" << endl;
    }
}



