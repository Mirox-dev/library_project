//
// Created by user on 02.12.2025.
//

#ifndef LIBRARY_PROJECT_USER_H
#define LIBRARY_PROJECT_USER_H

#include <iostream>
#include <vector>

using namespace std;

class User {
    string name;                    // Фамилия пользователя
    string userId;                  // Уникальный ID (вида "USR_001")
    vector<string> borrowedBooks;   // Список ISBN выданных книг
    int maxBooksAllowed = 3;        // Максимум книг, которые можно взять (по умолчанию 3)
public:
    User();
    User(string name, string userId, int maxBooksAllowed, vector<string>& borrowedBooks);

    [[nodiscard]] string getName() const { return name; }
    [[nodiscard]] string getUserId() const { return userId; }
    [[nodiscard]] vector<string> getBorrowedBooks() const { return borrowedBooks; }
    [[nodiscard]] int getMaxBooksAllowed() const { return maxBooksAllowed; }

    [[nodiscard]] bool canBorrowMore() const;       // Можно ли взять ещё книгу
    void addBook(const string& isbn);               // Добавить книгу в список взятых
    void removeBook(const string& isbn);            // Убрать книгу из списка
    void displayProfile() const;                    // Вывести профиль пользователя
};

#endif // LIBRARY_PROJECT_USER_H
