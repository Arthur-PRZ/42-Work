# 📘 CPP Module 00 — Introduction to C++

##  Introduction

**CPP00** is the first C++ module in the 42 curriculum.
It introduces the fundamentals of C++ and object-oriented programming through several small exercises.

---

#  Compilation

```bash
make
```

Run the executable:

```bash
./"program_name"
```

---

# Exercises

## ex00 — Megaphone

The program displays all given arguments in uppercase.

### Example

```bash
$ ./megaphone "hello world"
HELLO WORLD
```

### Concepts used

* `argc` / `argv`
* `toupper()`
* `std::cout`

---

## ex01 — My Awesome PhoneBook

A simple command-line phonebook application that allows the user to store and search contacts.

### Features

* add a contact
* search contacts
* display saved information

### Example commands

```txt
ADD
SEARCH
EXIT
```

### Concepts used

* classes
* objects
* object arrays
* encapsulation
* user interaction

---

## ex02 — The Job Of Your Dreams

A small banking system simulation using classes and formatted logs.

### Concepts used

* member functions
* timestamps
* formatted output
* object-oriented logic

### Example output

```txt
[20240101_120000] index:0;amount:42;created
```

---


# Project Constraints

* Mandatory standard: **C++98**
* Compilation flags:

```bash
-Wall -Wextra -Werror
```

* Modern C++ features are forbidden.

---

# Author

Made by [Arthur-PRZ](https://github.com/Arthur-PRZ).
