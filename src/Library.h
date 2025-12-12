//
// Created by user on 02.12.2025.
//

#ifndef LIBRARY_PROJECT_LIBRARY_H
#define LIBRARY_PROJECT_LIBRARY_H

#include <vector>
#include "User.h"
#include "Book.h"


class Library {
    vector<Book> books;    // Массив всех книг
    vector<User> users;    // Массив всех пользователей
    string dataFile;       // Указание пути к файлу library_data.txt
public:
    Library(vector<Book> books, vector<User> users, string dataFile);    // Конструктор
    void addBook(const Book& book);    // Добавить книгу
    void addUser(const User& user);    // Добавить пользователя
    void borrowBook(const string& userName, const string& isbn);    // Взять книгу
    void returnBook(const string& isbn);    // Вернуть книгу
    Book* findBookByISBN(const string& isbn);    // Найти книгу по isbn
    User* findUserByName(const string& name);    // Найти пользователя по имени
    void displayAllBooks() const;    // Показать все книги
    void displayAllUsers() const;    // Показать всех пользователей
    void saveToFile() const;    // Загрузить все данные в файл
    void loadFromFile();    // Выгрузить все данные из файла
};


#endif //LIBRARY_PROJECT_LIBRARY_H
