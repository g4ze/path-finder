#include "card_operations.h"
#include <iostream>
#include <string>

using namespace std;
double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        return 0.0; // Handle division by zero
    }
}

void recharge(string username) {
    double cid, amt, amount, x;
    int choice;
    std::cout << "Enter Card Id: ";
    std::cin >> cid;
    std::cout << "Enter Initial Balance: ";
    std::cin >> amt;
    std::cout << "Enter Recharge Amount: ";
    std::cout << "Total Balance: " << x << std::endl;
    do {
        std::cout << "\n1. Recharge Details\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "\nCard Id: " << cid << std::endl;
                std::cout << "Initial Balance: " << amt << std::endl;
                std::cout << "Recharge Amount: " << amount << std::endl;
                std::cout << "Total Balance: " << x << std::endl;
                break;
            case 2:
                std::cout << "Exiting...";
                break;
            default:
                std::cout << "Invalid choice. Please try again.";
        }
    } while (choice != 2);
}
