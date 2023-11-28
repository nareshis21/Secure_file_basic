#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void decryptFile(const string& fileName, int key) {
    ifstream inputFile(fileName, ios::in);

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    string content;
    char ch;
    while (inputFile.get(ch)) {
        content += ch;
    }

    inputFile.close();

    for (char& character : content) {
        character -= key;
    }

    ofstream outputFile("decrypted_" + fileName, ios::out);

    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing: decrypted_" << fileName << endl;
        return;
    }

    outputFile << content;
    outputFile.close();

    cout << "File decrypted successfully!" << endl;
}
