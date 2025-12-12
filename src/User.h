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
    string userId;                  // Уникальный ID
    vector<string> borrowedBooks;   // Список ISBN выданных книг
    int maxBooksAllowed = 3;        // Максимум книг, которые можно взять (по умолчанию 3)
public:
    User();              // Конструктор для ручного добавления пользователя
    User(string name, string userId, int maxBooksAllowed, vector<string>& borrowedBooks); // Конструктор для считывания с файла

    // Геттер-методы

    [[nodiscard]] string getName() const;
    [[nodiscard]] string getUserId() const;
    [[nodiscard]] vector<string> getBorrowedBooks() const;
    [[nodiscard]] int getMaxBooksAllowed() const;

    [[nodiscard]] bool canBorrowMore() const;       // Можно ли взять ещё книгу
    void addBook(const string& isbn);               // Добавить книгу в список взятых
    void removeBook(const string& isbn);            // Убрать книгу из списка
    void displayProfile() const;                    // Вывести профиль пользователя
};

#endif // LIBRARY_PROJECT_USER_H
