#include <iostream>
#include <fstream>
#include <string>

using namespace std;

unsigned int simpleHash(const string& str) {
    unsigned int hash = 0;
    for (char ch : str) {
        // Combine the character into the hash value
        hash = 31 * hash + ch;
    }
    return hash; // Return the resulting hash
}

// Generate a dataset file with user data
void generateDataset(const string& filename, int numEntries) {
    ofstream file(filename); // Open a file for writing
    if (!file) {
        cerr << "Error creating file: " << filename << endl;
        return;
    }

    // Generate user data for the specified number of entries
    for (int i = 0; i < numEntries; ++i) {
        string username = "user" + to_string(i);
        string password = "password" + to_string(i);
        // Hash the password
        unsigned int hashed = simpleHash(password);
        // Write the username, password, and hashed password to the file
        file << username << " " << password << " " << hashed << "\n";
    }
    file.close(); // Close the file after writing
}

int main() {
    // Generate three datasets with different sizes
    generateDataset("/usr/local/Generate-Dataset/data_100.txt", 100); // Dataset with 100 entries
    generateDataset("/usr/local/Generate-Dataset/data_1000.txt", 1000); // Dataset with 1000 entries
    generateDataset("/usr/local/Generate-Dataset/data_10000.txt", 10000); // Dataset with 10000 entries

    // Datasets have been generated
    cout << "Datasets generated successfully." << endl;

    return 0;
}
