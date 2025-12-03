//
// Created by user on 02.12.2025.
//

#ifndef LIBRARY_PROJECT_BOOK_H
#define LIBRARY_PROJECT_BOOK_H


#include <iostream>
#include "User.h"

using namespace std;

class Book
{
private:
    string title;    // название книги
    string author;    // автор
    int year;    // год издания
    string isbn;    // уникальный номер isbn
    bool isAvailable;    // доступна ли книга для выдачи
    string borrowedBy;    // фамилия пользователя, взявшего книгу
public:
    Book(std::string  title,
         std::string  author,
         int year,
         std::string  isbn);    // конструктор
    std::string getTitle() const {return title;}
    std::string getAuthor() const {return author;}
    int getYear() const {return year;}
    std::string getIsbn() const {return isbn;}
    bool getIsAvailable() const {return isAvailable;}
    std::string getBorrowedBy() const {return borrowedBy;}

    void BorrowBook(const::string& userName);    // выдать книгу
    void returnBook();    // вернуть книгу
    void displayInfo() const;    // вывести информацию о книге в консоль
};

#endif //LIBRARY_PROJECT_BOOK_H
