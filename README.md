# 📚 Library Management System (C++)

A simple **Command Line Interface (CLI)** based Library Management System written in **C++**.
This project demonstrates core C++ programming concepts such as **classes, vectors, file handling, and object-oriented design**.

The system allows users to manage books in a library through a menu-driven interface.

---

## 🚀 Features

* ➕ Add new books
* 📖 Show all books
* 🔍 Search for a book
* 📥 Borrow a book
* 📤 Return a book
* ✏️ Update book details
* ❌ Delete books
* 💾 Persistent storage using file handling

All book records are stored in a file (`books_list.txt`) so data is preserved even after the program exits.

---

## 🧠 Concepts Used

This project demonstrates the following **C++ concepts**:

* Object Oriented Programming (OOP)
* Classes and Objects
* STL `vector`
* File Handling (`ifstream`, `ofstream`)
* Loops and Conditional Statements
* Menu-driven CLI applications
* Basic Data Management

---

## 📂 Project Structure

```
Library_Management_System/
│
├── library_management_system.cpp   # Main source code
├── library_management_system.h     # Class declarations
├── books_list.txt                  # Data storage file
├── Makefile                        # Build automation
├── README.md                       # Project documentation
└── task.txt                        # Development notes
```

---

## ⚙️ Requirements

* Linux / macOS / Windows
* C++ Compiler (GCC / G++)
* Make

Recommended compiler version:

```
g++ (GCC) 9+
```

---

## 🛠 Build and Run

### Compile the project

```
make
```

### Run the program

```
make run
```

or

```
./library_management_system
```

### Clean build files

```
make clean
```

---

## 🖥 Example Menu

```
1 Add Book
2 Show Books
3 Borrow Book
4 Return Book
5 Search Book
6 Delete Book
7 Update Book
8 Exit
```

---

## 📘 Example Book Record

```
101 CppPrimer Lippman 5
102 CleanCode Martin 3
```

Format:

```
BookID  BookName  AuthorName  Quantity
```

---

## 🎯 Future Improvements

Possible improvements for this project:

* Sort books by name or ID
* Search books by author
* Improve input validation
* Add user authentication
* Convert to GUI application
* Store data using a database (SQLite)

---

## 👨‍💻 Author

**Bineesh**

C++ enthusiast interested in **system programming and backend development**.

---

## 📄 License

This project is open source and available under the **MIT License**.
