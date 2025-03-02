#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void addUserToFile(const string& name, const string& id, const string& role) {
    // Open file for reading
    ifstream inFile("src/users.json");
    json users;

    // Check if file exists and is not empty
    if (inFile.is_open()) {
        inFile >> users;  // Parse the JSON data from the file
        inFile.close();
    } else {
        // If file does not exist, initialize an empty JSON array
        users = json::array();
    }

    // Flag to check if user exists
    bool userExists = false;

    // Check if the user already exists in the list
    for (auto& user : users) {
        if (user["id"] == id) {
            userExists = true;
            break;
        }
    }

    // If the user does not exist, create a new entry
    if (!userExists) {
        json newUser = {
            {"name", name},
            {"id", id},
            {"role", role}
        };
        users.push_back(newUser);
    }

    // Open file for writing and save updated data
    ofstream outFile("src/users.json");
    outFile << setw(4) << users << endl;  // Pretty print with 4 spaces indentation
    outFile.close();
}