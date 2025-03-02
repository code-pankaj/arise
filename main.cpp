#include <bits/stdc++.h>
#include "admin/admin.cpp"
#include "users/faculty.cpp"
#include "users/student.cpp"
#include "users/librarian.cpp"

using namespace std;

class Details{
    private:
        string loginID = "admin";
        string loginPASS = "admin";
    public:
        bool credentialCheck();
};

bool Details::credentialCheck(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if(username == loginID && password == loginPASS){
        return true;
    }
    return false;
}

int main() {
    Details D1;
    while (true) {
        int option;

        cout << "Login as: " << endl;
        cout << "1. Admin" << endl;
        cout << "2. Librarian" << endl;
        cout << "3. Faculty" << endl;
        cout << "4. Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Please Choose An Option: ";
        cin >> option;

        if (option == 5) {
            return 0;
        }
        if (option >= 1 && option <= 4) {
            if(option == 1){
                if(D1.credentialCheck()){
                    adminDashboard();
                }
                else{
                    cout << "Wrong Credentials!!!" << endl;
                    return 0;
                }
            }
            else if(option == 2){
                librarianDashboard();
            }
            else if(option == 3){
                facultyDashboard();
            }
            else if(option == 4){
                studentDashboard();
            }
        } else {
            cout << "Please Choose a Correct Option." << endl;
        }
    }
    return 0;
}
