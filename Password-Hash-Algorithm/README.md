## Password Hash Algorithm
This program uses the ```SHA-256``` hashing algorithm from ```OpenSSL``` for password hashing.

A secure user account management system that creates new user accounts, signs into existing accounts, and updates passwords. The program stores user data in a vector, where each field consists of a username, a password, and a hashed password.

The program measures and outputs the time taken for account operations clock by using the ```chrono``` library.

## Installation and Setup
Install OpenSSL with macOS terminal command:
```console
brew install openssl
```
Then run this terminal command to find the exact path of your ```openssl library```:
```console
brew list openssl
```
Lastly, add the following at the end of your ```CMakeLists.txt``` file:
```console
include_directories(/opt/homebrew/Cellar/openssl@3/3.2.0/include/)

target_link_libraries(${Your_Project_Name} /opt/homebrew/Cellar/openssl@3/3.2.0/lib/libcrypto.3.dylib)
```
