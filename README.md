An application that includes three password hashing programs and a dataset generator program. If you'd like to run each application, only run one as its own project at a time, don't open all files as a single project.

### Generate Datasets
First, run the program to generate the datasets that you will use for the password hashing applications. This generates three different dataset files: ```data_100.txt, data_1000.txt, and data_10000.txt```.

When finished generating the dataset files, choose one and ```select all```, ```copy```, and then ```paste```, into one of the hashing password program ```data.txt``` files.

## Hashing Password Algorithms

### Hashing Password Data
This C++ program demonstrates a basic implementation of a password storage system using a hash function. It manages user accounts, allowing users to create new accounts, sign in, and change their passwords. The passwords are hashed for storage, initially using a reverse-hash method.

There's more detailed information in the ```README.md``` file for this application.

### Password Hash Table
This C++ program uses a hash table ```<unordered_map>``` to manage user accounts, including functionalities like creating a new account, signing in, and changing passwords. The password "hashing" is done by reversing the string.

### Password Hash Algorithm
This program uses the ```SHA-256``` hashing algorithm from ```OpenSSL``` for password hashing.

A secure user account management system that creates new user accounts, signs into existing accounts, and updates passwords. The program stores user data in a vector, where each field consists of a username, a password, and a hashed password.

The program measures and outputs the time taken for account operations clock by using the ```chrono``` library.

There's more detailed information in the ```README.md``` file for this application.
