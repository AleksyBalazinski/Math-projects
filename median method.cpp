#include <iostream>
#include <iomanip>
using namespace std;
class Number
{
public: 
	int numerator;
	int denumerator;
	double frac()
	{
		return (static_cast<double>(numerator) /static_cast<double>(denumerator));
	}
};

int main()
{
	double number, interval;
	cout << "Your number = ";
	cin >> number;
	int iterations;
	cout << "\nNumber of iterations: ";
	cin >> iterations;
	Number lower;
	Number upper;
	Number median;
	lower.numerator = 0;
	lower.denumerator = 1;
	upper.numerator = 1;
	upper.denumerator = 1;
	cout << "\nok\n";
	double fractional_part = number - floor(number);
	double whole_part = floor(number);
	for (int i = 0; i < iterations; i++)
	{
		median.numerator = lower.numerator + upper.numerator;
		median.denumerator = lower.denumerator + upper.denumerator;
		if (median.frac() >= fractional_part)
		{
			upper.numerator = median.numerator;
			upper.denumerator = median.denumerator;
			if (median.frac() == fractional_part) break;
		}
		else
		{
			lower.numerator = median.numerator;
			lower.denumerator = median.denumerator;
		}
	}
	cout << "approximation = " << setprecision(20) << (median.numerator + median.denumerator * whole_part)
		<< "/" << setprecision(20) << median.denumerator << setprecision(20) <<
		" = " << median.frac() + whole_part;
}
