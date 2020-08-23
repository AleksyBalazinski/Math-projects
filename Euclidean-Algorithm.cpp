#include <iostream>

int ea(int x, int y)
{
	int m = floor(x / y);
	int r = x - m * y;
	if (r != 0)
	{
		ea(y, r);
	}
	else
	{
		return y;
	}
}

int main()
{
	std::cout << "First number?\n";
	unsigned int a, b;
	std::cin >> a;
	std::cout << "Second number?\n";
	std::cin >> b;
	if (a < b)
	{
		int q = 0;
		q = a;
		a = b;
		b = q;
	}
	std::cout << "Greatest common divisor of " << a << " and " << b << " = " << ea(a, b);
}
