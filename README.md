# library_project
# Система управления личной библиотекой

Консольное приложение для управления коллекцией книг с поддержкой регистрации пользователей, выдачи и возврата книг.

## Описание проекта

Приложение реализует систему управления библиотекой с использованием объектно-ориентированного программирования на C++. Демонстрирует практическое применение таких концепций ООП как инкапсуляция, работа с указателями и обработка исключений.

## Требования

- **C++17** или выше
- **CMake 4.0** или выше
- Компилятор: GCC, Clang или MSVC

## Инструкции по сборке

### Шаг 1: Клонирование репозитория
```bash
git clone <repository-url>
cd library_project
```

### Шаг 2: Создание папки для сборки
```bash
mkdir build
cd build
```

### Шаг 3: Генерирование файлов сборки
```bash
cmake .. 
```

### Шаг 4: Компиляция
```bash
make
```

### Шаг 5: Запуск приложения
```bash
./library_project
```

## Использование

При запуске приложения появляется интерактивное меню с 10 опциями:

```
=== БИБЛИОТЕКА ===
1. Посмотреть все книги
2. Посмотреть всех пользователей
3. Добавить новую книгу
4. Зарегистрировать пользователя
5. Выдать книгу пользователю
6. Принять книгу от пользователя
7. Поиск книги по ISBN
8. Просмотреть профиль пользователя
9. Сохранить данные в файл
10. Выход
```

### Примеры операций:

**Просмотр всех книг:**
- Выберите пункт 1 меню
- Отобразятся все книги с информацией о доступности

**Добавление новой книги:**
- Выберите пункт 3
- Введите название, автора, год издания (1450-2025) и ISBN

**Регистрация пользователя:**
- Выберите пункт 4
- Введите фамилию, ID пользователя и максимальное количество книг для одновременного взятия

**Выдача книги:**
- Выберите пункт 5
- Введите фамилию пользователя и ISBN книги
- Система проверит доступность и лимит книг

## Структура проекта

```
library_project/
├── src/
│   ├── Book.h              # Объявление класса Book
│   ├── Book.cpp            # Реализация класса Book
│   ├── User.h              # Объявление класса User
│   ├── User.cpp            # Реализация класса User
│   ├── Library.h           # Объявление класса Library
│   ├── Library.cpp         # Реализация класса Library
│   └── main.cpp            # Главный файл с интерфейсом
├── data/
│   └── library_data.txt    # Файл с сохранёнными данными
├── CMakeLists.txt          # Конфигурация CMake
├── .gitignore              # Исключения для Git
└── README.md               # Этот файл
```

## Реализованные компоненты

### Класс Book
- Хранение информации о книге (название, автор, год, ISBN)
- Отслеживание доступности книги
- Методы для выдачи и возврата книги
- Валидация года издания (1450-2025)

### Класс User
- Хранение данных пользователя (имя, ID, список книг)
- Управление максимальным количеством одновременно взятых книг
- Проверка возможности взять дополнительную книгу

### Класс Library
- Управление каталогом книг
- Управление списком пользователей
- Поиск книги по ISBN
- Поиск пользователя по фамилии
- Сохранение и загрузка данных из файла

## Особенности

- **Инкапсуляция:** все данные приватные, доступ через методы
- **Валидация:** проверка корректности ввода данных
- **Обработка ошибок:** использование исключений
- **Работа с файлами:** сохранение и загрузка состояния
- **Консольный интерфейс:** интерактивное меню с проверкой ввода

---

# library_project — Personal Library Management System

*[Русский](#выше) | English*

## Description

A console application for managing a book collection with user registration, book lending and returns. Demonstrates OOP principles in C++: encapsulation, exception handling, and file persistence.

## Requirements

- **C++17** or higher
- **CMake 4.0** or higher
- Compiler: GCC, Clang, or MSVC

## Build Instructions

```bash
git clone <repository-url>
cd library_project
mkdir build && cd build
cmake ..
make
./library_project
```

## Usage

```
=== LIBRARY ===
1. View all books
2. View all users
3. Add a new book
4. Register a user
5. Lend a book to a user
6. Return a book from a user
7. Search book by ISBN
8. View user profile
9. Save data to file
10. Exit
```

## Project Structure

```
library_project/
├── src/
│   ├── Book.h / Book.cpp       # Book class
│   ├── User.h / User.cpp       # User class
│   ├── Library.h / Library.cpp # Library class
│   └── main.cpp                # Entry point and menu
├── data/
│   └── library_data.txt        # Persistent storage
├── CMakeLists.txt
└── README.md
```

## Components

### Book
Stores title, author, publication year (1450–2025), ISBN, and availability status. Provides borrow/return methods.

### User
Stores name, ID, and list of borrowed books. Enforces a configurable borrow limit.

### Library
Central manager for the book catalog and user list. Supports search by ISBN/name, file save/load.
