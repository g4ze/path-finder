#include <iostream>
#include "./math_operations.h"

using namespace std;

int main() {
    int choice;
    double num1, num2;

    while (true) {
        cout << "Menu: " << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        double result;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                break;
            case 2:
                result = subtract(num1, num2);
                break;
            case 3:
                result = multiply(num1, num2);
                break;
            case 4:
                result = divide(num1, num2);
                break;
            default:
                cout << "Invalid choice. Please enter a valid option (1-5)." << endl;
                continue;
        }

        cout << "Result: " << result << endl;
    }

    return 0;
}
