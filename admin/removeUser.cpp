#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void removeUserFromFile(const string& id) {
    // Open file for reading
    ifstream inFile("src/users.json");
    json users;

    // Check if file exists and is not empty
    if (inFile.is_open()) {
        inFile >> users;  // Parse the JSON data from the file
        inFile.close();
    } else {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    // Flag to check if user exists
    bool userExists = false;

    // Check if the user exists in the list
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it.value()["id"] == id) {
            // If found, remove the user
            users.erase(it);
            userExists = true;
            break;
        }
    }

    // If the user does not exist, display an error message
    if (!userExists) {
        cout << "Error: User not found." << endl;
        return;
    }

    // Open file for writing and save updated data
    ofstream outFile("src/users.json");
    outFile << setw(4) << users << endl;  // Pretty print with 4 spaces indentation
    outFile.close();
}