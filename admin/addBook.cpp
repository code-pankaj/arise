#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void addBookToFile(const string& bookName, const string& authorName, const string& category, int quantity) {
    // Open file for reading
    ifstream inFile("src/books.json");
    json books;

    // Check if file exists and is not empty
    if (inFile.is_open()) {
        inFile >> books;  // Parse the JSON data from the file
        inFile.close();
    } else {
        // If file does not exist, initialize an empty JSON array
        books = json::array();
    }

    // Flag to check if book exists
    bool bookExists = false;

    // Check if the book already exists in the list
    for (auto& book : books) {
        if (book["bookName"] == bookName && book["authorName"] == authorName && book["category"] == category) {
            // If found, increase the quantity
            book["quantity"] = book["quantity"].get<int>() + quantity;
            bookExists = true;
            break;
        }
    }

    // If the book does not exist, create a new entry
    if (!bookExists) {
        json newBook = {
            {"bookName", bookName},
            {"authorName", authorName},
            {"category", category},
            {"quantity", quantity}
        };
        books.push_back(newBook);
    }

    // Open file for writing and save updated data
    ofstream outFile("src/books.json");
    outFile << setw(4) << books << endl;  // Pretty print with 4 spaces indentation
    outFile.close();
}
