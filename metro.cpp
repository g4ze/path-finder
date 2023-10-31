#include <iostream>
#include "./math_operations.h"
#include <string>
#include <fstream>

using namespace std;

int main() {
    string username, password;
    int choice;

    while (true) {
        cout << "1. Login " << endl;
        cout << "2. Sign up" << endl;
        cout<< "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1: {
                string temp_username;
                cout << "Enter your username: ";
                cin >> temp_username;
                username = temp_username;
                break;
            }
            case 2: {
                ifstream inputFile("usernames.txt");
                if (!inputFile.is_open()) {
                    std::cerr << "Error opening the file." << std::endl;
                    return 1;
                }
                string fileContents((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
                inputFile.close();
                std::cout << "File Contents: " << std::endl;
                std::cout << fileContents << std::endl;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option (1-5)." << endl;
                continue;
        }
    }

    return 0;
}
