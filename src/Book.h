//
// Created by user on 02.12.2025.
//

#ifndef LIBRARY_PROJECT_BOOK_H
#define LIBRARY_PROJECT_BOOK_H


#include <iostream>

using namespace std;

class Book
{
    string title;    // название книги
    string author;    // автор
    int year;    // год издания
    string isbn;    // уникальный номер isbn
    bool isAvailable;    // доступна ли книга для выдачи
    string borrowedBy;    // фамилия пользователя, взявшего книгу

public:
    Book(string  title,
         string  author,
         int year,
         string  isbn);    // конструктор
    [[nodiscard]] string getTitle() const { return title; }
    [[nodiscard]] string getAuthor() const { return author; }
    [[nodiscard]] int getYear() const { return year; }
    [[nodiscard]] string getIsbn() const { return isbn; }
    [[nodiscard]] bool getIsAvailable() const { return isAvailable; }
     [[nodiscard]] string getBorrowedBy() const { return borrowedBy; }

    void BorrowBook(const::string& userName);    // выдать книгу
    void returnBook();    // вернуть книгу
    void displayInfo() const;    // вывести информацию о книге в консоль
};

#endif //LIBRARY_PROJECT_BOOK_H
