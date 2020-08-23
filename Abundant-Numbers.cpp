#include <iostream>

int main()
{
	setlocale(LC_ALL, "polish");
	std::cout << "Wprowadź górną granicę: ";
	unsigned int limit = 0;
	std::cin >> limit;
	unsigned int abundance = 1; //it's always geq than 1
	for (unsigned int n = 1; n <= limit; n++)
	{
		abundance = 1;
		for (unsigned int i = 2; i < n; i++)
		{
			if (n % i == 0) abundance += i;
		}
		if (abundance > n) 
		{ 
			std::cout << n << " jest liczbą obfitą.\n"; 
			std::cout << "Dla " << n << " obfitość wynosi " << abundance - n << "\n";
		}

	}
}
