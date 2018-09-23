#include "amortize.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Mortgage::Mortgage() : _interestP(0), _principal(0), _fixed(0), _year(0)
{

}

void Mortgage::SetInterestP(double i){
	_interestP = i;
}

void Mortgage::SetLoanAmount(double i){
	_principal = i;
}

void Mortgage::SetYear(int i){
	_year = i;
}

void Mortgage::SetFixed(){
	_fixed = CalculateFixed();
}


double Mortgage::CalculateFixed(){
	double fixed, c = _interestP/1200, n = _year*12;

	fixed = _principal*(c*pow(1+c, n))/(pow(1+c, n) - 1);

	return fixed;
}

void Mortgage::Schedule(){
	double interest = 0, principal = 0, interestTot = 0;
	int year = 1, month = 1;
	while(year != (_year+1))
	{
		cout << "Year " << year << endl;
		while(month != 13)
		{
			if(_principal != 0)
			{
			interest = _principal*_interestP/1200; // money paid in interest
			interestTot += interest;
			principal = _fixed - interest; // money paid in principal
			_principal -= principal;
			}

			cout << "Month " << month << endl;
			cout << "Principal $" << principal << setw(20) << "Interest $" << interest << endl;

			month++;
		}
		
		
		if(month == 13)
		{ // cycle through years
			year++;
			cout << endl;
			month -= 12;
		}
	}

	cout << "Total interest paid is $" << interestTot << "." << endl;
}



