//
// Created by user on 02.12.2025.
//

#include <windows.h>
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <sstream>

#include "Library.h"

using namespace std;

void showMenu() {
    cout << "\n=== БИБЛИОТЕКА ===" << endl;
    cout << "1. Посмотреть все книги" << endl;
    cout << "2. Посмотреть всех пользователей" << endl;
    cout << "3. Добавить новую книгу" << endl;
    cout << "4. Зарегистрировать пользователя" << endl;
    cout << "5. Выдать книгу пользователю" << endl;
    cout << "6. Принять книгу от пользователя" << endl;
    cout << "7. Поиск книги по ISBN" << endl;
    cout << "8. Просмотреть профиль пользователя" << endl;
    cout << "9. Сохранить данные в файл" << endl;
    cout << "10. Выход" << endl;
    cout << "Ваш выбор: ";
}

int main() {
    system("chcp 65001");  // Настройка консоли на UTF-8

    Library library({}, {}, "../data/library_data.txt");

    try {
        string line;
        int choice;
        bool exit = false;
        do {
            showMenu();
            do {
                getline(cin, line);
                istringstream iss(line);
                iss >> choice;
                if (0 < choice && choice <= 10 && !(iss >> line)) {
                    break;
                }
                cout << "Неверный ввод! Введите ещё раз: ";
            } while (true);

            switch (choice) {
                case 1: {
                    library.displayAllBooks();
                    break;
                }
                case 2: {
                    library.displayAllUsers();
                    break;
                }
                case 3: {
                    Book newBook;
                    library.addBook(newBook);
                    break;
                }
                case 4: {
                    User newUser;
                    library.addUser(newUser);
                    break;
                }
                case 5: {
                    cout << "\nВведите фамилию пользователя: ";
                    string name;
                    do {
                        getline(cin, line);
                        istringstream iss(line);
                        if (iss >> name && !(iss >> line)) {
                            break;
                        }
                        cout << "Неверный ввод! Введите фамилию ещё раз: ";
                    }while (true);

                    cout << "Введите ISBN книги, которую хотите выдать: ";
                    string isbn;
                    do {
                        getline(cin, line);
                        if (istringstream iss(line); iss >> isbn && !(iss >> line)) {
                            break;
                        }
                        cout << "Неверный ввод! Введите ISBN ещё раз: ";
                    }while (true);

                    try {
                        library.borrowBook(name, isbn);
                        cout << " Книга успешно выдана!" << endl;
                    } catch (const exception& e) {
                        cout << " Ошибка: " << e.what() << endl;
                    }
                    break;
                }
                case 6: {
                    cout << "\nВведите ISBN книги, которую хотите сдать: ";
                    string isbn;
                    do {
                        getline(cin, line);
                        if (istringstream iss(line); iss >> isbn && !(iss >> line)) {
                            break;
                        }
                        cout << "Неверный ввод! Введите ISBN ещё раз: ";
                    }while (true);

                    try {
                        library.returnBook(isbn);
                        cout << " Книга успешно принята!" << endl;
                    } catch (const exception& e) {
                        cout << " Ошибка: " << e.what() << endl;
                    }
                    break;
                }
                case 7: {
                    cout << "\nВведите ISBN интересующей вас книги: ";
                    string isbn;
                    do {
                        getline(cin, line);
                        if (istringstream iss(line); iss >> isbn && !(iss >> line)) {
                            break;
                        }
                        cout << "Неверный ввод! Введите ISBN ещё раз: ";
                    }while (true);

                    try {
                        library.findBookByISBN(isbn)->displayInfo();
                    } catch (const exception& e) {
                        cout << " Ошибка: " << e.what() << endl;
                    }
                    break;
                }
                case 8: {
                    cout << "\nВведите фамилию пользователя: ";
                    string name;
                    do {
                        getline(cin, line);
                        if (istringstream iss(line); iss >> name && !(iss >> line)) {
                            break;
                        }
                        cout << "Неверный ввод! Введите фамилию ещё раз: ";
                    }while (true);

                    try {
                        library.findUserByName(name)->displayProfile();
                    } catch (const exception& e) {
                        cout << "Ошибка: " << e.what() << endl;
                    }
                    break;
                }
                case 9: {
                    try {
                        library.saveToFile();
                        cout << " Данные успешно сохранены!" << endl;
                    } catch (const exception& e) {
                        cout << " Ошибка сохранения: " << e.what() << endl;
                    }
                    break;
                }
                case 10: {
                    exit = true;
                    cout << "\n Exit" << endl;
                    break;
                }
            }
            cout << endl;
        } while (!exit);
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}