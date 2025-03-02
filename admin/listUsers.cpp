#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;    

void listUsers(){
    ifstream inFile("src/users.json");
    json users;

    if (inFile.is_open()) {
        inFile >> users;
        inFile.close();
    } else {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    cout << "List of Users:" << endl;
    cout << "--------------------------------" << endl;
    for (auto& user : users) {
        cout << "Name: " << user["name"] << endl;
        cout << "ID: " << user["id"] << endl;
        cout << "Role: " << user["role"] << endl;
        cout << "--------------------------------" << endl;
    }
}