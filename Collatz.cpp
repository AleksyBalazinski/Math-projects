#include <iostream>
#include <vector>

int collatz(unsigned int n)
{
	int length = 0;
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n = 3 * n + 1;
		}
		length++;
	}
	return length;
}
void show_seq(unsigned int n)
{
	int cnt = 0;
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n = 3 * n + 1;
		}
		cnt++;
		std::cout << "Wykonanie nr. " << cnt << " -> " << n << "\n";
	}
}

int pos(std::vector<unsigned long long> vec, unsigned long long elem)
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == elem) return i;
	}
}
int main()
{
	setlocale(LC_ALL, "polish");
	std::cout << "Najdłuższy ciąg Collatza\nRozpatrujemy ciągi dla wartości początkowych między 1 a: \n";
	int upper;
	std::cin >> upper;
	std::vector<unsigned long long> lengths;
	for (unsigned int number = 1; number <= upper; number++)
	{
		lengths.push_back(collatz(number));
	}
	//copy vector
	std::vector<unsigned long long> lengths_copy;
	for (unsigned int i = 0; i < lengths.size() - 1; i++)
	{
		lengths_copy.push_back(lengths[i]);
	}
	for (unsigned int i = 1; i < lengths.size(); i++)
	{
		if (lengths[0] < lengths[i]) lengths[0] = lengths[i];
	}
	int here_long_collatz = pos(lengths_copy, lengths[0]) + 1;
	std::cout << "Najdłuższy ciąg występuje dla liczby " << here_long_collatz
		<< "  - wówczas jego długość wynosi " << lengths[0] + 1 << "\n\n";
	std::cout << "Czy pokazać sekwencję (Y/N)?\n";
	char decision;
	std::cin >> decision;
	if (decision == 'Y' || decision == 'y')
	{
		std::cout << "\n\n";
		show_seq(here_long_collatz);
	}
	else
	{
		return 0;
	}
}
