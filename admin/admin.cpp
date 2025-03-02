#include <bits/stdc++.h>
#include "addBook.cpp"
#include "removeBook.cpp"
#include "addUser.cpp"
#include "removeUser.cpp"
#include "listUsers.cpp"
#include "listBooks.cpp"
#include "issuedBooks.cpp"

using namespace std;

void adminDashboard();
void addBook();
void removeBook();
void addUser();
void removeUser();

void adminDashboard(){
    int option;
    cout << "1. Add Book" << endl;
    cout << "2. Remove Book" << endl;
    cout << "3. List Users" << endl;
    cout << "4. List Books" << endl;
    cout << "5. Issued Books" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an Option : ";
    cin >> option;
    if(option == 6){
        return;
    }
    if(option >= 1 && option <= 5){
        if(option == 1){
            addBook();
        }else if(option == 2){
            removeBook();
        }else if(option == 3){
            listUsers();
        }else if(option == 4){
            listBooks();
        }else if(option == 5){
            issuedBooks();
        }
    }
    else{
        cout << "Please choose a valid option." << endl;
    }
}

void addBook(){
    string bookName, authorName, category;
    int quantity;
    cout << "Enter Book Name : ";
    cin >> bookName;
    cout << "Enter Author Name : ";
    cin >> authorName;
    cout << "Enter Category : ";
    cin >> category;
    cout << "Enter Quantity : ";
    cin >> quantity;
    addBookToFile(bookName, authorName, category, quantity);
}

void removeBook(){
    string bookName;
    cout << "Enter Book Name : ";
    cin >> bookName;
    removeBookFromFile(bookName);
}

void addUser(){
    string name, id, role;
    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter ID : ";
    cin >> id;
    cout << "Enter Role : ";
    cin >> role;
    addUserToFile(name, id, role);
}

void removeUser(){
    string id;
    cout << "Enter ID : ";
    cin >> id;
    removeUserFromFile(id);
}
