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
    Book();                                                   // Конструктор для ручного добавления книги
    Book(string title, string author, int year, string isbn); // Конструктор для считывания из файла

    // Геттер-методы(nodiscard чтобы геттер метод ТОЧНО использовался, а не вызывался впустую)
    [[nodiscard]] string getTitle() const;
    [[nodiscard]] string getAuthor() const;
    [[nodiscard]] int getYear() const;
    [[nodiscard]] string getIsbn() const;
    [[nodiscard]] bool getIsAvailable() const;
    [[nodiscard]] string getBorrowedBy() const;

    void borrowBook(const string& userName);   // Выдать книгу
    void returnBook();                         // Вернуть книгу
    void displayInfo() const;                  // Вывести информацию о книге в консоль
};

#endif // LIBRARY_PROJECT_BOOK_H
