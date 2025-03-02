# 📚 Library Management System  

An advanced **Library Management System** with full-fledged functionality for **students, faculty, librarians, and admins**. This system efficiently manages books, users, issued books, and requests, ensuring seamless book tracking and management.  

## 🚀 Features  

### 🏛️ Admin  
- **Add Books** 📖  
- **Remove Books** ❌  
- **Add Users** 👥  
- **Remove Users** 🚫  
- **List Books & Users** 📑  
- **View Issued Books** 🔍  

### 👨‍🏫 Faculty & 📚 Student  
- **Issue Books** 📝  
- **Return Books** 📤  
- **View Issued Books** 📜  

### 📖 Librarian  
- **Approve/Deny Book Issue Requests** ✅❌  
- **Manage Issued Books** 🔄  

## 📂 Project Structure  

```
.
├── admin/              # Admin functionalities  
│   ├── addBook.cpp  
│   ├── addUser.cpp  
│   ├── admin.cpp  
│   ├── issuedBooks.cpp  
│   ├── listBooks.cpp  
│   ├── listUsers.cpp  
│   ├── removeBook.cpp  
│   └── removeUser.cpp  
├── users/              # User functionalities (Student, Faculty, Librarian)  
│   ├── faculty.cpp  
│   ├── librarian.cpp  
│   └── student.cpp  
├── src/                # Data storage (JSON files)  
│   ├── books.json  
│   ├── issuedBooks.json  
│   ├── issueRequests.json  
│   └── users.json  
├── .gitignore          # Git ignored files  
├── main.cpp            # Entry point  
├── readme.md           # Project Documentation  
└── .vscode/            # VSCode settings  
```

## 🛠️ Installation & Setup  

1. **Clone the repository**  
   ```sh
   git clone https://github.com/your-username/library-management-system.git
   cd library-management-system
   ```

2. **Compile the project**  
   ```sh
   g++ main.cpp admin/*.cpp users/*.cpp -o librarySystem -std=c++17
   ```

3. **Run the system**  
   ```sh
   ./librarySystem
   ```

## 📌 JSON Data Structure  

### 📘 `books.json`  
```json
[
  {
    "bookName": "C++ Primer",
    "authorName": "Stanley B. Lippman",
    "category": "Programming",
    "quantity": 5
  }
]
```

### 📜 `issuedBooks.json`  
```json
[
  {
    "bookName": "C++ Primer",
    "authorName": "Stanley B. Lippman",
    "category": "Programming",
    "issuedTo": "student123",
    "issuedOn": "2025-03-02",
    "returnDate": "2025-03-16"
  }
]
```

## 🏗️ Future Enhancements  
- 🔐 **User authentication system**  
- 🌐 **Web-based UI**  
- 📊 **Detailed analytics and reports**  
- ✉️ **Email notifications for due books**  

## 🤝 Contributing  
Want to contribute? Feel free to fork, create an issue, or submit a pull request.  

## 📜 License  
This project is **open-source** and available under the **MIT License**.  

