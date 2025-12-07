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
    isAvailable = false;
    }
void Book::returnBook() {
    if (isAvailable) {
        throw invalid_argument("Book is already returned");
    }
    borrowedBy = "";
    isAvailable = true;
}
void Book::displayInfo() const {
    cout << "BOOK" << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << year << endl;
    cout << "ISBN: " << isbn << endl;
    if (!isAvailable) {
        cout << "Available: " << "no" << endl;
        cout << "Book borrowed by: " << borrowedBy <<  endl;
    }
    else {
        cout << "Available: " << "yes" << endl;
        cout << "Borrowed by: " << endl;
        cout << "---Users---" << endl;
    }
}



