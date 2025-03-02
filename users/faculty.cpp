#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void facultyDashboard();
void facultyRequestBook();
void facultyReturnBook();
void facultyViewIssuedBooks();

void facultyDashboard(){
    int option;
    cout << "1. Request Book" << endl;
    cout << "2. Return Book" << endl;
    cout << "3. View Issued Books" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an Option: ";
    cin >> option;
    if(option == 4) return;
    
    switch(option){
        case 1: facultyRequestBook(); break;
        case 2: facultyReturnBook(); break;
        case 3: facultyViewIssuedBooks(); break;
        default: cout << "Please choose a valid option." << endl;
    }
}

// Faculty requests a book instead of issuing directly
void facultyRequestBook(){
    string bookName, authorName, category, facultyName;
    cout << "Enter Book Name: ";
    cin >> bookName;
    cout << "Enter Author Name: ";
    cin >> authorName;
    cout << "Enter Category: ";
    cin >> category;
    cout << "Enter Your Name: ";
    cin >> facultyName;

    ifstream inFile("src/books.json");
    json books;

    if (inFile.is_open()) {
        inFile >> books;
        inFile.close();
    } else {
        cout << "Error: Unable to open books file." << endl;
        return;
    }

    bool bookExists = false;
    for (auto& book : books) {
        if (book["bookName"] == bookName && book["authorName"] == authorName && book["category"] == category) {
            bookExists = true;
            break;
        }
    }

    if (!bookExists) {
        cout << "Error: Book not found in library." << endl;
        return;
    }

    ifstream reqFile("src/issueRequests.json");
    json issueRequests;

    if (reqFile.is_open()) {
        reqFile >> issueRequests;
        reqFile.close();
    } else {
        issueRequests = json::array();
    }

    json newRequest = {
        {"bookName", bookName},
        {"authorName", authorName},
        {"category", category},
        {"requestedBy", facultyName},
        {"status", "Pending"}
    };

    issueRequests.push_back(newRequest);

    ofstream outFile("src/issueRequests.json");
    outFile << setw(4) << issueRequests << endl;
    outFile.close();

    cout << "Book request submitted. Waiting for approval." << endl;
}

// Faculty returns a book
void facultyReturnBook(){
    string bookName, authorName, category;
    cout << "Enter Book Name: ";
    cin >> bookName;
    cout << "Enter Author Name: ";
    cin >> authorName;
    cout << "Enter Category: ";
    cin >> category;

    ifstream inFile("src/issuedBooks.json");
    json issuedBooks;

    if (inFile.is_open()) {
        inFile >> issuedBooks;
        inFile.close();
    } else {
        cout << "Error: Unable to open issued books file." << endl;
        return;
    }

    bool bookFound = false;
    for (auto it = issuedBooks.begin(); it != issuedBooks.end(); ++it) {
        if (it.value()["bookName"] == bookName && it.value()["authorName"] == authorName && it.value()["category"] == category) {
            issuedBooks.erase(it);
            bookFound = true;
            break;
        }
    }

    if (!bookFound) {
        cout << "Error: Book not found in issued records." << endl;
        return;
    }

    ifstream booksFile("src/books.json");
    json books;

    if (booksFile.is_open()) {
        booksFile >> books;
        booksFile.close();
    } else {
        cout << "Error: Unable to open books file." << endl;
        return;
    }

    for (auto& book : books) {
        if (book["bookName"] == bookName && book["authorName"] == authorName && book["category"] == category) {
            book["quantity"] = book["quantity"].get<int>() + 1;
            break;
        }
    }

    ofstream outFile("src/issuedBooks.json");
    outFile << setw(4) << issuedBooks << endl;
    outFile.close();

    ofstream outBookFile("src/books.json");
    outBookFile << setw(4) << books << endl;
    outBookFile.close();

    cout << "Book returned successfully." << endl;
}

// Faculty views issued books
void facultyViewIssuedBooks(){
    ifstream inFile("src/issuedBooks.json");
    json issuedBooks;

    if (inFile.is_open()) {
        inFile >> issuedBooks;
        inFile.close();
    } else {
        cout << "Error: Unable to open issued books file." << endl;
        return;
    }

    cout << "List of Issued Books:" << endl;
    cout << "--------------------------------" << endl;
    for (auto& issuedBook : issuedBooks) {
        cout << "Book Name: " << issuedBook["bookName"] << endl;
        cout << "Author Name: " << issuedBook["authorName"] << endl;
        cout << "Category: " << issuedBook["category"] << endl;
        cout << "Issued To: " << issuedBook["issuedTo"] << endl;
        cout << "Issued On: " << issuedBook["issuedOn"] << endl;
        cout << "Return Date: " << issuedBook["returnDate"] << endl;
        cout << "--------------------------------" << endl;
    }
}
