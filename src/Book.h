//
// Created by user on 02.12.2025.
//

#ifndef LIBRARY_PROJECT_BOOK_H
#define LIBRARY_PROJECT_BOOK_H

#include <string>

using std::string;

class Book {
    string title;           // Название книги
    string author;          // Автор
    int year{};             // Год издания
    string isbn;            // Уникальный номер ISBN
    bool isAvailable{true}; // Доступна ли книга для выдачи
    string borrowedBy;      // Фамилия пользователя, взявшего книгу

public:
    Book();                                    // Конструктор по умолчанию
    Book(string title, string author, int year, string isbn);

    // Геттеры
    [[nodiscard]] string getTitle() const { return title; }
    [[nodiscard]] string getAuthor() const { return author; }
    [[nodiscard]] int getYear() const { return year; }
    [[nodiscard]] string getIsbn() const { return isbn; }
    [[nodiscard]] bool getIsAvailable() const { return isAvailable; }
    [[nodiscard]] string getBorrowedBy() const { return borrowedBy; }

    void borrowBook(const string& userName);   // Выдать книгу
    void returnBook();                         // Вернуть книгу
    void displayInfo() const;                  // Вывести информацию о книге в консоль
};

#endif // LIBRARY_PROJECT_BOOK_H
