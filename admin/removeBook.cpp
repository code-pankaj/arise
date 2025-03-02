#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void removeBookFromFile(const string& bookName) {
    // Open file for reading
    ifstream inFile("src/books.json");
    json books;

    // Check if file exists and is not empty
    if (inFile.is_open()) {
        inFile >> books;  // Parse the JSON data from the file
        inFile.close();
    } else {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    // Flag to check if book exists
    bool bookExists = false;

    // Check if the book exists in the list
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it.value()["bookName"] == bookName) {
            // If found, remove the book
            books.erase(it);
            bookExists = true;
            break;
        }
    }

    // If the book does not exist, display an error message
    if (!bookExists) {
        cout << "Error: Book not found." << endl;
        return;
    }

    // Open file for writing and save updated data
    ofstream outFile("src/books.json");
    outFile << setw(4) << books << endl;  // Pretty print with 4 spaces indentation
    outFile.close();
}