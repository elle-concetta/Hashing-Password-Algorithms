#include"bits/stdc++.h"
#include <cerrno>
#include <cstring>

using namespace std;

#define MAX_ENTRIES 10000

int main()
{
    // Create a 2D array which stores the data
    // Col1 stores User ID, Col2 stores password, Col3 stores hash value of password
    string data [MAX_ENTRIES][3];

    // Read from the file, if there is any data
    ifstream infile("/Users/ellefassler/Desktop/Hashing-Password-Data/data.txt");
    if(!infile) {
        cout << "Unable to open file." << strerror(errno) << endl;
        exit(1);
    }
    string id,pwd,hash_pwd;
    // ctr stores the number of entries

    int ctr = 0;

    // Store data from file in the matrix
    while(infile>>id>>pwd>>hash_pwd)
    {
        data[ctr][0] = id;
        data[ctr][1] = pwd;
        data[ctr][2] = hash_pwd;
        ctr++;
    }

    // Menu for user
    int choice;
    cout<<"ENTER YOUR CHOICE:"<<endl;
    cout<<"1. Create a New Account"<<endl;
    cout<<"2. Sign In"<<endl;
    cout<<"3. Change Password"<<endl;
    cin>>choice;

    auto start = chrono::high_resolution_clock::now();

    // Create new account
    if(choice == 1)
    {
        cout<<"Welcome!"<<endl;
        cout<<"Enter Username: "<<endl;
        cin>>data[ctr][0];
        cout<<"Enter Password: "<<endl;
        cin>>data[ctr][1];

        // Reverse the password and store it as hash
        string hash = data[ctr][1];
        reverse(hash.begin(), hash.end());
        data[ctr][2]=hash;
        ctr++;
    }

    // Login
    else if(choice == 2)
    {
        string user_id, password;
        cout<<"Enter Username"<<endl;
        cin>>user_id;
        cout<<"Enter Password"<<endl;
        cin>>password;

        for(int i=0;i<ctr;i++)
        {
            // If password matching with corresponding hash is successful, login is successful
            if(data[i][0]==user_id)
            {
                string hash = password;
                reverse(hash.begin(), hash.end());
                if(hash == data[i][2])
                    cout<<"Login successful.";
                else
                    cout<<"Username or password is incorrect.";
            }
        }
    }

    // Password update
    else if(choice == 3)
    {
        string user_id, password;
        cout<<"Enter Username"<<endl;
        cin>>user_id;
        cout<<"Enter Current Password"<<endl;
        cin>>password;

        for(int i=0;i<ctr;i++)
        {
            if(data[i][0]==user_id)
            {
                string hash = password;
                reverse(hash.begin(), hash.end());

                // If password is correct, ask for a new password and update it
                if(hash == data[i][2])
                {
                    string new_password, new_hash;
                    cout<<"Enter New Password"<<endl;
                    cin>>new_password;
                    data[i][1] = new_password;
                    new_hash = new_password;
                    reverse(new_hash.begin(), new_hash.end());
                    data[i][2] = new_hash;
                }
                else
                    cout<<"Username or password is incorrect.";
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Save all the data in the file
    ofstream out("/Users/ellefassler/Desktop/Hashing-Password-Data/data.txt");
    for (int i = 0; i < ctr; ++i) {
        out << data[i][0] << " " << data[i][1] << " " << data[i][2] << endl;
    }

    cout << "Operation Time: " << duration.count() << " microseconds" << endl;

    return 0;
}

