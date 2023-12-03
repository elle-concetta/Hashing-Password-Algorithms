#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct UserInfo {
    string password;
    string hashedPassword;
};

int main() {
    unordered_map<string, UserInfo> userTable;
    // Read from the file, if there is any data
    ifstream infile("/Users/ellefassler/Desktop/Hashing-Password-Data/data.txt");

    if (!infile) {
        cout << "Unable to open file." << strerror(errno) << endl;
        exit(1);
    }

    // Reading data from file
    string id, pwd, hash_pwd;
    while (infile >> id >> pwd >> hash_pwd) {
        userTable[id] = {pwd, hash_pwd};
    }

    // User menu for account management
    int choice;
    cout << "ENTER YOUR CHOICE:" << endl;
    cout << "1. Create a New Account" << endl;
    cout << "2. Sign In" << endl;
    cout << "3. Change Password" << endl;
    cin >> choice;

    // Start timing the operation
    auto start = chrono::high_resolution_clock::now();

    if (choice == 1) {
        // Creating a new account
        cout << "Welcome! Enter Username: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> pwd;
        string hash = pwd;
        reverse(hash.begin(), hash.end());
        userTable[id] = {pwd, hash};
    }
    else if (choice == 2) {
        // Signing in to an existing account
        cout << "Enter Username: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> pwd;
        string hash = pwd;
        reverse(hash.begin(), hash.end());

        if (userTable.find(id) != userTable.end() && userTable[id].hashedPassword == hash) {
            cout << "Login successful." << endl;
        } else {
            cout << "Username or password is incorrect." << endl;
        }
    }
    else if (choice == 3) {
        // Changing the password for an existing account
        cout << "Enter Username: ";
        cin >> id;
        cout << "Enter Current Password: ";
        cin >> pwd;
        string hash = pwd;
        reverse(hash.begin(), hash.end());

        if (userTable.find(id) != userTable.end() && userTable[id].hashedPassword == hash) {
            cout << "Enter New Password: ";
            cin >> pwd;
            hash = pwd;
            reverse(hash.begin(), hash.end());
            userTable[id] = {pwd, hash};
            cout << "Password updated successfully." << endl;
        } else {
            cout << "Username or password is incorrect." << endl;
        }
    }

    // Stop timing the operation
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Writing updated data back to the file
    ofstream out("/Users/ellefassler/Desktop/Hashing-Password-Data/data.txt");
    for (const auto &pair : userTable) {
        out << pair.first << " " << pair.second.password << " " << pair.second.hashedPassword << endl;
    }

    // Displaying the time taken for the operation
    cout << "Operation Time: " << duration.count() << " microseconds" << endl;

    return 0;
}


