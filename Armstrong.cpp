#include <iostream>
#include <cmath>
unsigned int get_nth_digit(unsigned int n, int number)
{
	number = number / pow(10, n - 1);
	return number % 10;
}
unsigned int length(int number)
{
	int length = 0;
	while (number / pow(10, length) >= 1) length++;
	return length;
}
bool is_armstrong(int number)
{
	int sum = 0;
	for (int i = 1; i <= length(number); i++)
	{
		sum += pow(get_nth_digit(i, number), length(number));
	}
	if (sum == number) return true;
	else return false;
}

int main()
{
	setlocale(LC_ALL, "polish");
	for (int num = 100; num <= 999; num++)
	{
		if (is_armstrong(num)) std::cout << num << " jest liczbą Armstronga\n";
	}
}
