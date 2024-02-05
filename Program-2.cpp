// Program-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inFile("SalaryData.txt");
    ofstream outFile("SalaryOut.txt");

    if (!inFile) {
        cout << "Error: Can't open input file 'Salary_Data.txt'" << endl;
        return 1;
    }

    string firstName, lastName;
    double currentSalary, payIncrease, updatedSalary;

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
