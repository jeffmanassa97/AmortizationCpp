#include "amortize.hpp"
#include <iostream>
#include <iomanip>
using namespace std;


int main(){

	int year;
	double interest, principal;
    Mortgage amort;

    cout << "30-year or 15-year fixed mortgage? ";
    cin >> year;
    amort.SetYear(year);
    cout << "What is the loan amount? ";
    cin >> principal;
    amort.SetLoanAmount(principal);
    cout << "What is interest percent? ";
    cin >> interest;
    amort.SetInterestP(interest);
    amort.SetFixed();


    cout << endl << endl;
    cout << "Your fixed- monthly payment is $" << fixed << setprecision(2) << amort.CalculateFixed() << "." << endl;
    cout << endl << "Here is the amortization schedule." << endl << endl;
    amort.Schedule();
    cout << endl;
    
    
    
    return 0;
}
