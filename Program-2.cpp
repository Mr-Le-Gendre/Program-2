// Program-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inFile("SalaryData.txt");  // User inputs: Reading from file "SalaryData.txt"
    ofstream outFile("SalaryOut.txt");

    if (!inFile) {
        cout << "Error: Can't open input file 'Salary_Data.txt'" << endl;
        return 1;
    }

    string firstName, lastName;  // User inputs: First Name, Last Name
    double currentSalary, payIncrease, updatedSalary;  // Supplied constants: Current Salary, Pay Increase

    // Processing notes:
    // 1. Open input file for reading, and display error if can't be opened.
    // 2. Read data from the input file and calculate updated salary.
    // 3. Display updated salary for each employee.
    // 4. Write employee's name and updated salary to output file.
    // 5. Close both input and output files.

    while (inFile >> lastName >> firstName >> currentSalary >> payIncrease) {
        updatedSalary = currentSalary * (1 + payIncrease / 100);

        cout << "Updated Salary for " << firstName << " " << lastName
            << ": $" << fixed << setprecision(2) << updatedSalary << endl;

        outFile << firstName << " " << lastName << " " << updatedSalary << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}

