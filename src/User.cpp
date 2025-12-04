    //
// Created by user on 02.12.2025.
//

#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

User::User(string name, string userId, int maxBooksAllowed):
            name(std::move(name)), userId(std::move(userId)),
            maxBooksAllowed(maxBooksAllowed) {}

bool User::canBorrowMore() const {
    if (BorrowedBooks.size() < maxBooksAllowed) {
        cout << "Can borrow more books" << endl;
        return true;
    }
    cout << "Can't borrow more books." << endl;
    return false;
}

void User::addBook(const string& isbn) {
    if (canBorrowMore()) {
        BorrowedBooks.push_back(isbn);
    }
    else {
        throw invalid_argument("User can't borrow more books.");
    }
}
void User::removeBook(const string& isbn) {
    for (int i = 0; i < BorrowedBooks.size(); i++) {
        if (BorrowedBooks[i] == isbn) {
            BorrowedBooks.erase(BorrowedBooks.begin() + i);
            break;
        }
        if (i == BorrowedBooks.size() && isbn != BorrowedBooks[i]) {
            throw invalid_argument("User didn't take this book");
        }
    }
}
void User::displayProfile() const {
    cout << "USER" << endl;
    cout << "Name" << name << endl;
    cout << "UserId" << userId << endl;
    cout << "BorrowedBooks";
    for (int i = 0; i < BorrowedBooks.size(); i++) {
        if (i != BorrowedBooks.size() - 1) {
            cout << BorrowedBooks[i] << " | ";
        }
        else {
            cout << BorrowedBooks[i] << endl;
        }
    }
    cout << "MaxBooks: " << maxBooksAllowed << endl;
}


