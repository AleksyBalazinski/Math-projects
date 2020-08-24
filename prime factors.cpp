#include <iostream>

int main()
{
	setlocale(LC_ALL, "polish");
	std::cout << "Podaj liczbę: ";
	int liczba = 0;
	std::cin >> liczba;
	std::cout << "Czynniki pierwsze liczby\n" << liczba << ":";
	if (liczba % 2 == 0)
	{
		std::cout << "2\n";
		liczba /= 2;
	}
	int counter = 0;
	for (int i = 3; i * i < liczba; i += 2)
	{
		if (liczba % i == 0)
		{
			counter++;
			std::cout << i << "\n";
			liczba /= i;
		}
	}
	if (counter == 0) std::cout << liczba;
}
