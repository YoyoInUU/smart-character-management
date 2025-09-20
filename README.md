# Smart Character Management

A simple C++ demo project that demonstrates the use of **smart pointers** (`shared_ptr` and `unique_ptr`) for managing character objects in a simulated game environment.

## 💡 Features

- `Character` class with health, healing, and damage logic
- Simulation modules:
  - Attack and heal with `shared_ptr`
  - Attack and heal with `unique_ptr`
- Demonstrates ownership, reference counting, and move semantics
- Clean modular design using header/source files
- Simple Makefile for easy compilation

## 📁 Project Structure
```
smart-character-management-main/
├── character.h                # Character class declaration
├── character.cpp              # Character class implementation
├── modules.h                  # Module function declarations
├── modules.cpp                # Module function implementations
├── main.cpp                   # Program entry point
├── Makefile                   # Build configuration
└── README.md                  # This file
```

## 🛠️ Build Instructions

### Prerequisites

- A C++ compiler that supports C++17 (e.g., g++)

### To build:

```bash
make
```

### To run:
```bash
./main
```

### To clean build files:
```bash
make clean
```

## 📚 Learning Goals

1. Understand the differences between `shared_ptr` and `unique_ptr`.
2. Learn proper memory management in modern C++.
3. Explore object ownership transfer and scope-based resource control.

## 📄 License

This project is for educational purposes. Feel free to use and modify as needed.

---

**Author**: Yoyo Chang  
**Last Updated**: September 2025  
**C++ Standard**: C++17