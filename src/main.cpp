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

// Консольное меню
void showMenu() {
    cout << "\n=== БИБЛИОТЕКА ===";
    cout << "\n1. Посмотреть все книги";
    cout << "\n2. Посмотреть всех пользователей";
    cout << "\n3. Добавить новую книгу";
    cout << "\n4. Зарегистрировать пользователя";
    cout << "\n5. Выдать книгу пользователю";
    cout << "\n6. Принять книгу от пользователя";
    cout << "\n7. Поиск книги по ISBN";
    cout << "\n8. Просмотреть профиль пользователя";
    cout << "\n9. Сохранить данные в файл";
    cout << "\n10. Выход";
    cout << "\nВаш выбор: ";
}

int main() {
    system("chcp 65001");  // Настройка консоли на UTF-8
    Library library({}, {}, "../data/library_data.txt");

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
            cout << "\nНеверный ввод! Введите ещё раз: ";
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
                cout << "\nВведите ID пользователя: ";
                string name;
                do {
                    getline(cin, line);
                    istringstream iss(line);
                    if (iss >> name && !(iss >> line)) {
                        break;
                    }
                    cout << "\nНеверный ввод! Введите ID ещё раз: ";
                }while (true);

                cout << "\nВведите ISBN книги, которую хотите выдать: ";
                string isbn;
                do {
                    getline(cin, line);
                    if (istringstream iss(line); iss >> isbn && !(iss >> line)) {
                        break;
                    }
                    cout << "\nНеверный ввод! Введите ISBN ещё раз: ";
                }while (true);

                try {
                    library.borrowBook(name, isbn);
                    cout << "\nКнига успешно выдана!" << endl;
                } catch (const exception& e) {
                    cout << "\nОшибка: " << e.what() << endl;
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
                    cout << "\nНеверный ввод! Введите ISBN ещё раз: ";
                }while (true);

                try {
                    library.returnBook(isbn);
                    cout << "\nКнига успешно принята!" << endl;
                } catch (const exception& e) {
                    cout << "\nОшибка: " << e.what() << endl;
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
                    cout << "\nНеверный ввод! Введите ISBN ещё раз: ";
                }while (true);

                try {
                    library.findBookByISBN(isbn)->displayInfo();
                } catch (const exception& e) {
                    cout << "\nОшибка: " << e.what() << endl;
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
                    cout << "\nНеверный ввод! Введите фамилию ещё раз: ";
                }while (true);

                try {
                    library.findUserByName(name)->displayProfile();
                } catch (const exception& e) {
                    cout << "\nОшибка: " << e.what() << endl;
                }
                break;
            }
            case 9: {
                library.saveToFile();
                cout << "\nДанные успешно сохранены!" << endl;
                break;
            }
            case 10: {
                exit = true;
                cout << "\nExit" << endl;
                break;
            }
        }
        cout << endl;
    } while (!exit);

    return 0;
}
