
class Mortgage{

private:

	double _interestP, _principal, _fixed;
	int _year;

public:
    
    Mortgage();
	void SetInterestP(double);
	void SetLoanAmount(double);
	void SetYear(int);
	void SetFixed();
	double CalculateFixed();
	void Schedule();
    
};