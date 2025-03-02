#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void issuedBooks(){
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