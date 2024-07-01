/*************************************************************
* File: main.cpp                                             *
* Author: Victor Tran                                      *
* Date: 6/12/2024                                        *
* Description: This program calculates investment growth     *
*              with and without additional monthly deposits, *
*              based on user input for initial investment,   *
*              monthly deposit amount, annual interest rate, *
*              and number of years. It displays year-end    *
*              balances and earned interest for each year.   *
*************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;

void getValidInput(const string& prompt, double& value) {
    cout << prompt;
    while (!(cin >> value) || value < 0) {
        cout << "Invalid input. Please enter a positive number." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << prompt;
    }
}

void getValidInput(const string& prompt, int& value) {
    cout << prompt;
    while (!(cin >> value) || value < 0) {
        cout << "Invalid input. Please enter a positive number." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << prompt;
    }
}

int main() {
    Account account;
    double initialAmt, mDeposit, annualInt;
    int numYear;

    // Get user input
    getValidInput("Enter Initial Investment Amount: $", initialAmt);
    getValidInput("Enter Monthly Deposit: $", mDeposit);
    getValidInput("Enter Annual Interest Rate (percentage): %", annualInt);
    getValidInput("Enter Number of Years: ", numYear);

    // Display input values
    cout << "\nInitial Investment Amount: $" << initialAmt << endl;
    cout << "Monthly Deposit: $" << mDeposit << endl;
    cout << "Annual Interest: %" << annualInt << endl;
    cout << "Number of Years: " << numYear << endl;
    cout << "Press any key to continue..." << endl;
    cin.ignore();
    cin.get();

    // Set values in account
    account.setInitAmt(initialAmt);
    account.setMDeposit(mDeposit);
    account.setAnnualInt(annualInt);
    account.setNumYear(numYear);

    // Calculate results
    account.calcWithoutMonthlyDeposit();
    account.calcWithMonthlyDeposit();

    // Display results
    account.displayYearlyReportWithoutDeposit();
    account.displayYearlyReportWithDeposit();

    return 0;
}
