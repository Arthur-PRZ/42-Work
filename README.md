# 🔵 C++ Modules

A series of 10 modules (00→09) from 42, designed to introduce **Object-Oriented Programming** in C++.

---

## Introduction

The C++ modules are a progressive series of projects covering the core concepts of **C++ and OOP**.  
Each module focuses on specific notions, building on the previous ones.

### Key Concepts

- **Classes & Objects** — encapsulation, constructors, destructors
- **Access specifiers** — `public`, `private`, `protected`
- **Inheritance** — single, multiple, and virtual inheritance
- **Polymorphism** — virtual functions and method overriding
- **Templates** — generic programming with function and class templates
- **Exceptions** — error handling with `try`, `catch`, `throw`
- **Operator overloading** — redefining operators for custom types
- **STL containers** — `vector`, `map`, `stack`, `list`...
- **Orthodox Canonical Form** — default constructor, copy constructor, assignment operator, destructor
- **Type casting** — `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`

---

## Usage

### Compilation

Each module can be compiled using its Makefile or directly with `c++` :

```bash
# With Makefile
make        # Compile the module
make clean  # Remove object files
make fclean # Remove object files and binary
make re     # Full recompilation

# Directly with c++
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o "program_name"
```

### Running

```bash
./"program_name"
```

---

## Modules Overview

| Module | Topics |
|---|---|
| `00` | Namespaces, classes, member functions, stdio streams |
| `01` | Memory allocation, references, pointers to members, file streams |
| `02` | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form |
| `03` | Inheritance |
| `04` | Subtype polymorphism, abstract classes, interfaces |
| `05` | Repetition and exceptions |
| `06` | C++ type casting |
| `07` | C++ templates |
| `08` | Templated containers, iterators, algorithms |
| `09` | STL containers |

---

## Author

Made by [Arthur-PRZ](https://github.com/Arthur-PRZ)
