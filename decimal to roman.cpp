#include <iostream>
#include <vector>

std::string dec_to_rom(unsigned int number)
{
	std::vector<std::pair<unsigned int, std::string>> roman
	{
		{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
		{40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
	};
	std::string result;
	for (auto elem : roman)
	{
		while (number >= elem.first)
		{
			result += elem.second;
			number -= elem.first;
		}
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "polish");
	std::cout << "Podaj liczbę: ";
	int number;
	std::cin >> number;
	std::cout << "\n" << number << " napisana w liczbach rzymskich to: " << dec_to_rom(number);
}
