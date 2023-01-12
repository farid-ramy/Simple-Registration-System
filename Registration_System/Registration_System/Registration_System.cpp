#include <iostream>
#include <fstream>
using namespace std;

void SignUp() {
    system("CLS"); 
    cout << "+-----------------------------+" << endl;
    cout << "|                             |" << endl;
    cout << "|           Sign Up           |" << endl;
    cout << "|           _______           |" << endl;
    cout << "|                             |" << endl;
    cout << "|  Enter UserName & Password  |" << endl;
    cout << "|                             |" << endl;
    cout << "+-----------------------------+" << endl;

    while (true) {
        cout << "-> UserName :  ";
        string username;
        cin >> username;
        cout << "-> Password :  ";
        string password;
        cin >> password;

        bool found = false;
        ifstream myFile("file.txt");

        string USERNAME, PASSWORD;

        if (myFile.is_open()) {   
            while (!myFile.eof()) {
                myFile >> USERNAME >> PASSWORD;
                if (username == USERNAME) {
                    found = true;
                    break;
                }
            }
            myFile.close();
        }

        if (found) {
            cout << endl << "< ERROR..UserName is Taken >" << endl << endl;
            continue;
        }
        else {
            fstream myFilee("file.txt",ios::app);
            myFilee << endl << username << " " << password;
            myFilee.close();
            cout << "< ADDED SUCCESSFULLY >" << endl;
            break;
        }
    }
 }


void SignIn() {
    system("CLS");
    cout << "+-----------------------------+" << endl;
    cout << "|                             |" << endl;
    cout << "|           Sign In           |" << endl;
    cout << "|           _______           |" << endl;
    cout << "|                             |" << endl;
    cout << "|  Enter UserName & Password  |" << endl;
    cout << "|                             |" << endl;
    cout << "+-----------------------------+" << endl;

    while (true) {
        cout << "-> UserName :  ";
        string username;
        cin >> username;
        cout << "-> Password :  ";
        string password;
        cin >> password;

        bool found = false;
        ifstream myFile("file.txt");

        string USERNAME, PASSWORD;

        if (myFile.is_open()) {
            while (!myFile.eof()) {
                myFile >> USERNAME >> PASSWORD;
                if (username == USERNAME && password == PASSWORD) {
                    found = true;
                    break;
                }
            }
            myFile.close();
        }

        if (!found) {
            cout << endl << "< WRONG USERNAME OR PASSWORD >" << endl << endl;
            continue;
        }
        else {
            cout << endl << "< SIGN IN SUCCESSFULLY >" << endl << endl;
            break;
        }
    }
}


int main()
{
    cout << "+-----------------------------+" << endl;
    cout << "|                             |" << endl;
    cout << "|        1. Sign Up           |" << endl;
    cout << "|        2. Sign In           |" << endl;
    cout << "|                             |" << endl;
    cout << "+-----------------------------+" << endl;
    int choice;
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "ERROR..INVALID CHOICE..Choose again: ";
        cin >> choice;
    }

    if (choice == 1)
        SignUp();
    else
        SignIn();
}
