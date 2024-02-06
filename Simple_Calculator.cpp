#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

double calculator(double prevResult, double num2, char operation) {
    double result;
    switch(operation) {
        case '+':
            result = prevResult + num2;
            break;
        case '-':
            result = prevResult - num2;
            break;
        case '*':
            result = prevResult * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = prevResult / num2;
            } else {
                cout << "Error! Cannot divide by zero." << endl;
                result = prevResult; // return previous result if division by zero
            }
            break;
        default:
            cout << "Error! Invalid operation." << endl;
            result = prevResult; // return previous result if invalid operation
    }
    return result;
}

int main() {
    cout << setw(32);
    cout << "Simple Calculator\n\n";
    double num1, num2, prevResult = 0;
    char operation, choice = true;

    while (choice != false) {
        if (prevResult != 0) {
            cout << "Enter the operation to perform ( +, -, *, /): ";
            cin >> operation;
        } else {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the operation to perform ( +, -, *, /): ";
            cin >> operation;
            prevResult = num1;
        }

        cout << "Enter the second number: ";
        cin >> num2;
        prevResult = calculator(prevResult, num2, operation);
        cout << "Result: " << prevResult << endl;
        cout << "\nType 'y' to continue calculating with " << prevResult << ", or type 'n' to start a new calculation: ";
        cin >> choice;
        
        if (choice == 'n') {
            choice = true ; 
            prevResult = 0; // Reset previous result for new calculation
        }
    }

    getch();
    return 0;
}
