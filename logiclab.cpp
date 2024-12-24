// LogicLab: An interactive program to perform logical operations 
// and explore truth tables with advanced features and clean design!
#include <iostream>
#include <cmath>
using namespace std;
void showMenu();
int getInput(const string& varName);
void performOperation(int A, int B, int choice);
void displayTruthTable(int A, int B);

int main() {
    int A, B, choice;
    cout << "WELCOME TO THE TRUTH TABLE PROGRAM!\n\n";

    A = getInput("A");
    B = getInput("B");

    do {
        //get the user's choice
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice >= 1 && choice <= 5) {
            performOperation(A, B, choice);
        } else if (choice != 0) {
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }

    } while (choice != 0);
    cout << "Thanks for using the program! Goodbye! :)\n";
    return 0; }

void showMenu() {
    cout << "\nSelect the logical operation to perform:\n";
    cout << "1. AND (A AND B)\n";
    cout << "2. OR (A OR B)\n";
    cout << "3. NOT (on A)\n";
    cout << "4. NOT (on B)\n";
    cout << "5. Truth Table\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int getInput(const string& varName) { // get a valid input (0 or 1) for A or B
    int value;
    do {
        cout << "Enter " << varName << " (0 or 1): ";
        cin >> value;

        if (cin.fail() || (value != 0 && value != 1)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter 0 or 1.\n";
        } else {
            break;
        }
    } while (true);

    return value;
}


void performOperation(int A, int B, int choice) { // perform toperation
    switch (choice) {
        case 1:
            cout << "Result of A AND B: " << (A && B) << endl;
            break;
        case 2:
            cout << "Result of A OR B: " << (A || B) << endl;
            break;
        case 3:
            cout << "Result of NOT A: " << (!A) << endl;
            break;
        case 4:
            cout << "Result of NOT B: " << (!B) << endl;
            break;
        case 5:
            displayTruthTable(A, B);
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
    }
}
//truth table
void displayTruthTable(int A, int B) {
    cout << "\nTruth Table:\n";
    cout << "A\tB\tA AND B\tA OR B\tNOT A\tNOT B\n";
    int values[2] = {0, 1};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int a = values[i];
            int b = values[j];
            cout << a << "\t" << b << "\t" << (a && b) << "\t" << (a || b) << "\t" << (!a) << "\t" << (!b) << endl;
        }
    }
}












