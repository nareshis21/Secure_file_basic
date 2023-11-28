// mainModule.cpp
#include "encrypt/encryptModule.h"
#include "decrypt/decryptModule.h"
#include <iostream>
#include <string>
#include <cstdlib> // For system("clear")

using namespace std;

// Function to hash the password using a simple hash function
string hashPassword(const string& password) {
    hash<string> hasher;
    size_t hashValue = hasher(password);

    // Convert the hash value to a string
    stringstream ss;
    ss << hex << hashValue;
    return ss.str();
}

void printMenu() {
    cout << "\033[2J\033[H"; // Clear the screen
    cout << "\033[1;36m";    // Set text color to cyan
    cout << "***********************\n";
    cout << "   Secure File Manager \n";
    cout << "***********************\n";
    cout << "\033[0m"; // Reset text color
    cout << "Choose an option:\n";
    cout << "1. Encrypt or Decrypt a File\n";
    cout << "2. Exit\n";
}

int main() {
    string fileName;
    string password;
    int choice;

    while (true) {
        printMenu();

        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\033[2J\033[H"; // Clear the screen
            cout << "Enter the file name: ";
            cin >> fileName;

            cout << "Enter the password: ";
            cin >> password;

            cout << "Choose an operation:\n";
            cout << "1. Encrypt\n";
            cout << "2. Decrypt\n";
            cout << "3. Back to Main Menu\n";
            cout << "Enter your choice (1, 2, or 3): ";
            cin >> choice;

            // Hash the password to derive a stronger key
            string hashedKey = hashPassword(password);
            int key = 0;
            for (char ch : hashedKey) {
                key += static_cast<unsigned char>(ch);
            }

            switch (choice) {
            case 1:
                encryptFile(fileName, key);
                cout << "File encrypted successfully!\n";
                break;
            case 2:
                decryptFile("encrypted_" + fileName, key);
                cout << "File decrypted successfully!\n";
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                break;
            }
            break;
        }
        case 2:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter 1 or 2.\n";
            break;
        }

        cout << "Press Enter to continue...";
        cin.ignore(); // Ignore the newline character left in the buffer
        cin.get();    // Wait for Enter key
    }

    return 0;
}
