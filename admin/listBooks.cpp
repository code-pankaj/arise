#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void listBooks(){
    ifstream inFile("src/books.json");
    json books;

    if (inFile.is_open()) {
        inFile >> books;
        inFile.close();
    } else {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    cout << "List of Books:" << endl;
    cout << "--------------------------------" << endl;
    for (auto& book : books) {
        cout << "Book Name: " << book["bookName"] << endl;
        cout << "Author Name: " << book["authorName"] << endl;
        cout << "Category: " << book["category"] << endl;
        cout << "Quantity: " << book["quantity"] << endl;
        cout << "--------------------------------" << endl;
    }
}