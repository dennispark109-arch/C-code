#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to hold our data
struct Contact {
    string name;
    string phone;
};

// Function Prototypes
void addContact();
void viewContacts();
void searchContact();

const string FILE_NAME = "database.txt";

int main() {
    int choice;

    while (true) {
        cout << "\n--- WINDOWS OFFLINE DATABASE (C++) ---" << endl;
        cout << "1. Add New Contact" << endl;
        cout << "2. View All Contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: return 0;
            default: cout << "Invalid selection!" << endl;
        }
    }
    return 0;
}

void addContact() {
    Contact c;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, c.name);
    cout << "Enter Phone: ";
    getline(cin, c.phone);

    // Using fstream to append to file
    ofstream outFile(FILE_NAME, ios::app);
    if (outFile.is_open()) {
        outFile << c.name << "|" << c.phone << endl;
        outFile.close();
        cout << "Data saved successfully to " << FILE_NAME << endl;
    } else {
        cout << "Error: Could not open file!" << endl;
    }
}

void viewContacts() {
    ifstream inFile(FILE_NAME);
    string line;
    cout << "\n--- Contact List ---" << endl;
    cout << left << setw(20) << "Name" << " | " << "Phone" << endl;
    cout << "------------------------------------" << endl;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            size_t delimiterPos = line.find('|');
            if (delimiterPos != string::npos) {
                string name = line.substr(0, delimiterPos);
                string phone = line.substr(delimiterPos + 1);
                cout << left << setw(20) << name << " | " << phone << endl;
            }
        }
        inFile.close();
    } else {
        cout << "No data found. Create a contact first." << endl;
    }
}

void searchContact() {
    string query;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, query);

    ifstream inFile(FILE_NAME);
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find(query) != string::npos) {
            cout << "Found: " << line << endl;
            found = true;
        }
    }
    if (!found) cout << "No matches found." << endl;
    inFile.close();
}
