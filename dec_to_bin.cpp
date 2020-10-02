/*This program converts a real number from decimal to binary representation*/
#include <iostream>

double power(double base, int exponent)
{
	double result{ 1 };
	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	if (exponent >= 1) return result;
	else if (exponent == 0) return 1;
	else return (1 / result);
}

void convert(double dec, int precision)
{
	int n{ 0 };

	for (int i = 0;; i++)
	{
		if (dec < power(2, i))
		{
			n = i - 1;
			break;
		}
	}

	for (int i = n; i >= -precision; i--)
	{
		if (dec >= pow(2, i))
		{
			std::cout << "1";
			dec -= pow(2, i);
		}
		else std::cout << "0";

		if (i == 0) std::cout << ".";
	}
}

int main()
{
	std::cout << "Enter a number in decimal\n";
	double decimal{ 0 };
	std::cin >> decimal;
	std::cout << "Set precision\n";
	int precision{ 0 };
	std::cin >> precision;
	std::cout << "\n" << decimal << " in binary is ";
	convert(decimal, precision);
}
