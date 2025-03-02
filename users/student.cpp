#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void studentDashboard();
void studentIssueBook();
void studentReturnBook();
void studentViewIssuedBooks();

void studentDashboard() {
    int option;
    cout << "1. Issue Book" << endl;
    cout << "2. Return Book" << endl;
    cout << "3. View Issued Books" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an Option : ";
    cin >> option;
    if (option == 4) {
        return;
    }
    if (option >= 1 && option <= 3) {
        if (option == 1) {
            studentIssueBook();
        } else if (option == 2) {
            studentReturnBook();
        } else if (option == 3) {
            studentViewIssuedBooks();
        }
    } else {
        cout << "Please choose a valid option." << endl;
    }
}

void studentIssueBook() {
    string bookName, authorName, category, issuedTo, issuedOn, returnDate;
    cout << "Enter Book Name : ";
    cin >> bookName;
    cout << "Enter Author Name : ";
    cin >> authorName;
    cout << "Enter Category : ";
    cin >> category;
    cout << "Enter Issued To : ";
    cin >> issuedTo;
    cout << "Enter Issued On : ";
    cin >> issuedOn;
    cout << "Enter Return Date : ";
    cin >> returnDate;

    ifstream inFile("src/books.json");
    json books;

    if (inFile.is_open()) {
        inFile >> books;
        inFile.close();
    } else {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    bool bookFound = false;
    for (auto& book : books) {
        if (book["bookName"] == bookName && book["authorName"] == authorName && book["category"] == category) {
            if (book["quantity"].get<int>() > 0) {
                book["quantity"] = book["quantity"].get<int>() - 1;
                bookFound = true;
                break;
            } else {
                cout << "Error: Book not available." << endl;
                return;
            }
        }
    }

    if (!bookFound) {
        cout << "Error: Book not found." << endl;
        return;
    }

    ifstream issuedBooksFile("src/issuedBooks.json");
    json issuedBooks;

    if (issuedBooksFile.is_open()) {
        issuedBooksFile >> issuedBooks;
        issuedBooksFile.close();
    } else {
        issuedBooks = json::array();
    }

    json newIssuedBook = {
        {"bookName", bookName},
        {"authorName", authorName},
        {"category", category},
        {"issuedTo", issuedTo},
        {"issuedOn", issuedOn},
        {"returnDate", returnDate}
    };

    issuedBooks.push_back(newIssuedBook);

    ofstream outFile("src/issuedBooks.json");
    outFile << setw(4) << issuedBooks << endl;
    outFile.close();

    ofstream outBookFile("src/books.json");
    outBookFile << setw(4) << books << endl;
    outBookFile.close();

    cout << "Book issued successfully." << endl;
}

void studentReturnBook() {
    string bookName, authorName, category;
    cout << "Enter Book Name : ";
    cin >> bookName;
    cout << "Enter Author Name : ";
    cin >> authorName;
    cout << "Enter Category : ";
    cin >> category;

    ifstream inFile("src/issuedBooks.json");
    json issuedBooks;

    if (inFile.is_open()) {
        inFile >> issuedBooks;
        inFile.close();
    } else {
        cout << "Error: Unable to open file." << endl;
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
        cout << "Error: Book not found." << endl;
        return;
    }

    ifstream booksFile("src/books.json");
    json books;

    if (booksFile.is_open()) {
        booksFile >> books;
        booksFile.close();
    } else {
        cout << "Error: Unable to open file." << endl;
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

void studentViewIssuedBooks() {
    ifstream inFile("src/issuedBooks.json");
    json issuedBooks;

    if (inFile.is_open()) {
        inFile >> issuedBooks;
        inFile.close();
    } else {
        cout << "Error: Unable to open file." << endl;
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
