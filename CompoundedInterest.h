#ifndef COMPOUNEDEDINTEREST_H
#define COMPOUNEDEDINTEREST_H

//defines class methods and attributes
class CompoundedInterest{

  public:
    bool isValidInput(double input); 
    void getValidInput(double& x);

    void displayInputData(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears);

    void getUserInput(double& initialInvestment, double& monthlyDeposit, double& annualInterest, int& numYears);
  
    int totalMonths(int numYears);
    
    void calculateInterest(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears);

    void displayOutputData(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears);

    void displayFormat(double monthlyDeposit);

  private:
    double initialInvestment = 0;
    double monthlyDeposit = 0;
    double annualInterest = 0;
    int numYears = 0;
    
};











#endif
