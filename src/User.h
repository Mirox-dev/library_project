//
// Created by user on 02.12.2025.
//

#ifndef LIBRARY_PROJECT_USER_H
#define LIBRARY_PROJECT_USER_H

#include <iostream>
#include <vector>

using namespace std;

class User {
    string name;    // фамилия пользователя
    string userId;    // уникальный ID (вида "USR_001")
    vector<string> BorrowedBooks;    // список ISBN выданных кни
    int maxBooksAllowed = 3;    // максимум книг, которые можно взять (умолчанию 3)
    public:
    User(string name, string userId, int maxBooksAllowed = 3);
    string getName() { return name; }
    string getUserId() { return userId; }
    vector<string> getBorrowedBooks() { return BorrowedBooks; }
    int getMaxBooksAllowed() const { return maxBooksAllowed; }
    bool canBorrowMore() const;    // можно ли взять ещё книгу
    void addBook(const string& isbn);    // добавить книгу в список взятых
    void removeBook(const string& isbn);    // убрать книгу из списка
    void displayProfile() const;    // вывести профиль пользователя
};


#endif //LIBRARY_PROJECT_USER_H