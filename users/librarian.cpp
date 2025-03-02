#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void librarianDashboard();
void approveIssueRequest();
void viewIssuedBooks();

void librarianDashboard(){
    int option;
    cout << "1. Approve Book Requests" << endl;
    cout << "2. View Issued Books" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an Option: ";
    cin >> option;
    if(option == 3) return;
    
    switch(option){
        case 1: approveIssueRequest(); break;
        case 2: viewIssuedBooks(); break;
        default: cout << "Invalid option." << endl;
    }
}

// Librarian approves/rejects requests
void approveIssueRequest(){
    ifstream inFile("src/issueRequests.json");
    json issueRequests;
    if (inFile.is_open()) {
        inFile >> issueRequests;
        inFile.close();
    } else {
        cout << "No pending requests." << endl;
        return;
    }

    ifstream bookFile("src/books.json");
    json books;
    if (bookFile.is_open()) {
        bookFile >> books;
        bookFile.close();
    } else {
        cout << "Error: Unable to open books file." << endl;
        return;
    }

    json updatedRequests = json::array();
    json issuedBooks;
    ifstream issuedFile("src/issuedBooks.json");
    if (issuedFile.is_open()) {
        issuedFile >> issuedBooks;
        issuedFile.close();
    } else {
        issuedBooks = json::array();
    }

    for (auto& req : issueRequests) {
        cout << "Approve request? (y/n): " << endl;
        cout << "Book: " << req["bookName"] << ", Requested by: " << req["requestedBy"] << endl;
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            bool issued = false;
            for (auto& book : books) {
                if (book["bookName"] == req["bookName"] && book["authorName"] == req["authorName"] && book["category"] == req["category"]) {
                    if (book["quantity"].get<int>() > 0) {
                        book["quantity"] = book["quantity"].get<int>() - 1;
                        issuedBooks.push_back({
                            {"bookName", req["bookName"]},
                            {"authorName", req["authorName"]},
                            {"category", req["category"]},
                            {"issuedTo", req["requestedBy"]},
                            {"issuedOn", "2025-03-02"},
                            {"returnDate", "2025-03-30"}
                        });
                        issued = true;
                        break;
                    }
                }
            }
            if (!issued) {
                req["status"] = "Rejected (Out of Stock)";
                updatedRequests.push_back(req);
            }
        } else {
            req["status"] = "Rejected";
            updatedRequests.push_back(req);
        }
    }

    ofstream outFile("src/issuedBooks.json");
    outFile << setw(4) << issuedBooks << endl;
    outFile.close();

    ofstream bookOutFile("src/books.json");
    bookOutFile << setw(4) << books << endl;
    bookOutFile.close();

    ofstream reqOutFile("src/issueRequests.json");
    reqOutFile << setw(4) << updatedRequests << endl;
    reqOutFile.close();

    cout << "Requests processed." << endl;
}

// Librarian views issued books
void viewIssuedBooks(){
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
