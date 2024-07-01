#include "Account.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Constructor implementation
Account::Account()
    : initialAmt(0), mDeposit(0), annualInt(0), numYear(0), numMonth(0) {}

// Setters
void Account::setInitAmt(double amount) {
    initialAmt = amount;
}

void Account::setMDeposit(double deposit) {
    mDeposit = deposit;
}

void Account::setAnnualInt(double annualInterest) {
    annualInt = annualInterest;
}

void Account::setNumYear(int numOfYear) {
    numYear = numOfYear;
    setNumMonths();
}

void Account::setNumMonths() {
    numMonth = numYear * 12;
    setVectorSize(numMonth);
}

void Account::setVectorSize(int numsMonths) {
    openVectWithoutDeposit.resize(numsMonths);
    interestVectWithoutDeposit.resize(numsMonths);
    closeVectWithoutDeposit.resize(numsMonths);
    openVectWithDeposit.resize(numsMonths);
    totalVectWithDeposit.resize(numsMonths);
    interestVectWithDeposit.resize(numsMonths);
    closeVectWithDeposit.resize(numsMonths);
}

void Account::calcWithoutMonthlyDeposit() {
    double tempOpen = initialAmt;
    for (int i = 0; i < numMonth; ++i) {
        double tempInt = tempOpen * (annualInt / 100.0 / 12.0);
        double tempClose = tempOpen + tempInt;

        openVectWithoutDeposit.at(i) = tempOpen;
        interestVectWithoutDeposit.at(i) = tempInt;
        closeVectWithoutDeposit.at(i) = tempClose;

        tempOpen = tempClose;
    }
}

void Account::calcWithMonthlyDeposit() {
    double tempOpen = initialAmt;
    for (int i = 0; i < numMonth; ++i) {
        double tempTotal = tempOpen + mDeposit;
        double tempInt = tempTotal * (annualInt / 100.0 / 12.0);
        double tempClose = tempTotal + tempInt;

        openVectWithDeposit.at(i) = tempOpen;
        totalVectWithDeposit.at(i) = tempTotal;
        interestVectWithDeposit.at(i) = tempInt;
        closeVectWithDeposit.at(i) = tempClose;

        tempOpen = tempClose;
    }
}

void Account::displayYearlyReportWithoutDeposit() const {
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "Year    Year End Balance    Year End Earned Interest" << endl;

    double cumulativeInterest = 0;
    for (int year = 1; year <= numYear; ++year) {
        double yearEndInterest = 0;
        for (int month = 0; month < 12; ++month) {
            yearEndInterest += interestVectWithoutDeposit.at((year - 1) * 12 + month);
        }
        cumulativeInterest += yearEndInterest;
        double yearEndBalance = closeVectWithoutDeposit.at(year * 12 - 1);

        cout << year << "    $ " << fixed << setprecision(2) << round(yearEndBalance * 100) / 100 << "    $ " << round(yearEndInterest * 100) / 100 << endl;
    }
}

void Account::displayYearlyReportWithDeposit() const {
    cout << "\nBalance and Interest With Additional Monthly Deposits" << endl;
    cout << "Year    Year End Balance    Year End Earned Interest" << endl;

    double cumulativeInterest = 0;
    for (int year = 1; year <= numYear; ++year) {
        double yearEndInterest = 0;
        for (int month = 0; month < 12; ++month) {
            yearEndInterest += interestVectWithDeposit.at((year - 1) * 12 + month);
        }
        cumulativeInterest += yearEndInterest;
        double yearEndBalance = closeVectWithDeposit.at(year * 12 - 1);

        cout << year << "    $ " << fixed << setprecision(2) << round(yearEndBalance * 100) / 100 << "    $ " << round(yearEndInterest * 100) / 100 << endl;
    }
}
