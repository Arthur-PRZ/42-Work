# CPP Module 00 — Introduction to C++

## 📚 Description

**CPP00** is the first C++ module in the 42 curriculum.
It introduces the fundamentals of C++ and object-oriented programming through several small exercises.

This module covers:

* namespaces
* classes and objects
* member functions
* encapsulation
* standard input/output streams
* `std::string`
* basic C++ syntax
* user interaction
* object arrays
* formatted output
* timestamps and logging systems
* differences between C and C++

---

# 🛠️ Compilation

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

Run the executable:

```bash
./program
```

---

# 📘 Exercises

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

# ✅ What I Learned

This module helped me understand:

* the basics of C++
* object-oriented programming
* how to structure projects using classes
* standard input/output streams
* writing code following the C++98 standard

---

# ⚠️ Project Constraints

* Mandatory standard: **C++98**
* Compilation flags:

```bash
-Wall -Wextra -Werror
```

* Modern C++ features are forbidden.

---

# 👨‍💻 Author

Project developed as part of the 42 school curriculum.
