#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

#define MAX_ENTRIES 10000

string hashPassword(const string& pwd) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, pwd.c_str(), pwd.size());
    SHA256_Final(hash, &sha256);

    stringstream ss;
    for (unsigned char i : hash) {
        ss << hex << setw(2) << setfill('0') << (int) i;
    }
    return ss.str();
}

int main() {
    vector<array<string, 3>> data(MAX_ENTRIES);
    // Read from the file, if there is any data
    ifstream infile("/usr/local/data.txt");
    if (!infile) {
        cout << "Unable to open file: " << strerror(errno) << endl;
        exit(1);
    }

    // Reading data from file
    string id, pwd, hash_pwd;
    int ctr = 0;
    while (infile >> id >> pwd >> hash_pwd && ctr < MAX_ENTRIES) {
        data[ctr][0] = id;
        data[ctr][1] = pwd;
        data[ctr][2] = hash_pwd;
        ctr++;
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
        string hash = hashPassword(pwd);
        if (ctr < MAX_ENTRIES) {
            data[ctr++] = {id, pwd, hash};
        }
    } else if (choice == 2) {
        // Signing in to an existing account
        cout << "Enter Username: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> pwd;
        string hash = hashPassword(pwd);

        bool loginSuccess = false;
        for (int i = 0; i < ctr; ++i) {
            if (data[i][0] == id && data[i][2] == hash) {
                cout << "Login successful." << endl;
                loginSuccess = true;
                break;
            }
        }
        if (!loginSuccess) {
            cout << "Username or password is incorrect." << endl;
        }
    } else if (choice == 3) {
        // Changing the password for an existing account
        cout << "Enter Username: ";
        cin >> id;
        cout << "Enter Current Password: ";
        cin >> pwd;
        string hash = hashPassword(pwd);

        for (int i = 0; i < ctr; ++i) {
            if (data[i][0] == id && data[i][2] == hash) {
                cout << "Enter New Password: ";
                cin >> pwd;
                data[i][1] = pwd;
                data[i][2] = hashPassword(pwd);
                cout << "Password updated successfully." << endl;
                break;
            }
        }
    }

    // Stop timing the operation
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Writing updated data back to the file
    ofstream out("/usr/local/data.txt");
    for (int i = 0; i < ctr; ++i) {
        out << data[i][0] << " " << data[i][1] << " " << data[i][2] << endl;
    }

    // Displaying the time taken for the operation
    cout << "Operation Time: " << duration.count() << " microseconds" << endl;

    return 0;
}
