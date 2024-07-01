/*************************************************************
* File: Account.h                                            *
* Author: Victor Tran                                      *
* Date: 6/12/2024                                         *
* Description: Header file for the Account class, which      *
*              calculates investment growth with and without *
*              additional monthly deposits, and displays     *
*              year-end balances and earned interest.        *
*************************************************************/

#pragma once
#include <vector>

class Account {
public:
    Account();

    // Setters
    void setInitAmt(double amount);
    void setMDeposit(double deposit);
    void setAnnualInt(double annualInterest);
    void setNumYear(int numOfYear);
    void setNumMonths();
    void setVectorSize(int numsMonths);

    // Calculations
    void calcWithoutMonthlyDeposit();
    void calcWithMonthlyDeposit();

    // Display reports
    void displayYearlyReportWithoutDeposit() const;
    void displayYearlyReportWithDeposit() const;

private:
    double initialAmt;
    double mDeposit;
    double annualInt;
    int numYear;
    int numMonth;

    // Vectors to store financial data
    std::vector<double> openVectWithoutDeposit;
    std::vector<double> interestVectWithoutDeposit;
    std::vector<double> closeVectWithoutDeposit;

    std::vector<double> openVectWithDeposit;
    std::vector<double> totalVectWithDeposit;
    std::vector<double> interestVectWithDeposit;
    std::vector<double> closeVectWithDeposit;
};
