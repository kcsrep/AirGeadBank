#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "CompoundedInterest.h"
using namespace std;

//checks if the value is a positive real number
bool CompoundedInterest::isValidInput(double input) {
    if (isnan(input) || input < 0) {
        return false;
    }
    return true;
}

// will continue to get user input if the input is invalid and calls the isValidInput to verify a valid input
void CompoundedInterest::getValidInput(double& x){
  while (!isValidInput(x)){
    cout<<"Invalid input. Enter a valid input: ";
    cin>>x;
    }
}

//gets the user input and calls the getValidInput function to check if the input is valid
void CompoundedInterest::getUserInput(double& initialInvestment, double& monthlyDeposit, double& annualInterest, int& numYears){
  
  cout<<"Enter initial investment amount: "; 
  cin>>initialInvestment;
  getValidInput(initialInvestment);

  
  cout<<"Enter monthly deposit: ";
  cin>>monthlyDeposit;
  getValidInput(initialInvestment);



  cout<<"Enter annual interest rate: ";
  cin>>annualInterest;
  getValidInput(initialInvestment);


  cout<<"Enter number of years: ";
  cin>>numYears;
  getValidInput(initialInvestment);

}

//displays the input data with users input and without user input
void CompoundedInterest::displayInputData(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears){

  string _continue;
  //displays data with users input
  if(initialInvestment > 0 || monthlyDeposit > 0 || annualInterest > 0 || numYears > 0){

    cout<<setfill('*') << setw(30)<< " "<<endl;
    cout<<setfill('*')<<setw(20)<<" Data Input "<<""
    <<setfill('*')<<setw(9)<<""<<endl;
    cout<<"Initial Investmet Amount:   $"<<initialInvestment<<endl;
    cout<<"Monthly Deposit:   $"<<monthlyDeposit<<endl;
    cout<<"Annual Interest:   $"<<annualInterest<<endl;
    cout<<"Number of Years:   $"<<numYears<<endl;
    cout<<"Press Any Key To Continue . . .\n";
    cin>>_continue;
  }

  //displays data without user input
  else{
    cout<<setfill('*') << setw(30)<< " "<<endl;
    cout<<setfill('*')<<setw(20)<<" Data Input "<<""
    <<setfill('*')<<setw(9)<<""<<endl;
    cout<<"Initial Investmet Amount:\n"
    <<"Monthly Deposit:\n"
    <<"Annual Interest:\n"
    <<"Number of Years:\n"
    <<"Press Any Key To Continue . . .\n";
    cin>>_continue;
    cout<< endl<<"Input data\n";
  }
}

//calculates the total months in the investment
int CompoundedInterest::totalMonths(int numYears){
  int numMonths = numYears * 12;
  return numMonths;
}

//calculates the closing balance and year earned interest
void CompoundedInterest::calculateInterest(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears){


  //initializes variables
  double interest = 0 ;
  double closingBalance = 0;
  double openingBalance = 0;
  double yearEarnedInterest = 0;
  double total = 0.0;

  //calculate the interest
  interest = (initialInvestment + monthlyDeposit) * ((annualInterest/ double(12)));

  //sets the opening balance to the initial investment
  openingBalance = initialInvestment;

  //sets the closing balance to the opening balance
  closingBalance = openingBalance;

  //loops for the total amount of years
  for(int i = 0; i  <numYears; i++){

    //resets the value of the yearly earned interest
    yearEarnedInterest = 0;

    //loops for the total amount of months
    for(int j = 0; j < 12; j++){

      //sets the opening balance to the closing balance
      openingBalance = closingBalance;

      //adds the deposit to the opening to find the current total
      total = openingBalance + monthlyDeposit;

      //calculates the current interest
      interest = (openingBalance + monthlyDeposit) * ((annualInterest/ double(12)));

      //updates the current closing balance      
      closingBalance = openingBalance + monthlyDeposit + interest; 

      //calculates the year earned interest
      yearEarnedInterest = yearEarnedInterest + interest;
    }

    //displays the closing balance and yearly earned interest
    cout<< endl << fixed <<setprecision(2) << i+1 << "\t\t\t\t\t\t\t" << closingBalance << "\t\t\t\t\t\t\t\t" << yearEarnedInterest <<endl;
  }
}

//displays the format of the table
void CompoundedInterest::displayFormat(double monthlyDeposit){

  //checks if the monthly deposit is greater than 0 and outputs the table
  if (monthlyDeposit > 0){
    cout <<"           Balance and Interest With Additional Monthly Deposits" << endl;
    cout << setfill( '`') << setw(80) << "" << endl;
    cout << setfill('_')<< setw(80) << "" << endl;
    cout<< "Year           "
    << "       Year End Balance        "
    << "        Year End Earned Interest" << endl;
    cout << setfill('_')<< setw(80) << "" << endl;
  }

  //checks if the monthly deposit is 0 and outputs the table
  else{
    cout <<"           Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << setfill( '`') << setw(80) << "" << endl;
    cout << setfill('_')<< setw(80) << "" << endl;
    cout<< "Year           "
    << "       Year End Balance        "
    << "        Year End Earned Interest" << endl;
    cout << setfill('_')<< setw(80) << "" << endl;
  }



}
