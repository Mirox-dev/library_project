//
// Created by user on 02.12.2025.
//

#ifndef LIBRARY_PROJECT_LIBRARY_H
#define LIBRARY_PROJECT_LIBRARY_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Book.h"


class Library {
    vector<Book> books;
    vector<User> users;
    string dataFile;
    public:
    Library(vector<Book> books, vector<User> users, const string &dataFile);
    void addBook(const Book& book) {books.push_back(book);}
    void addUser(const User& user) {users.push_back(user);}
    void BorrowBook(const string& userName, const string& isbn);
    void returnBook(const string& isbn);
    Book* findBookByISBN(const string& isbn);
    User* findUserByName(const string& name);
    void displayAllBooks() const;
    void displayAllUsers() const;
    void saveToFile() const;
    void loadFromFile();
};


#endif //LIBRARY_PROJECT_LIBRARY_H