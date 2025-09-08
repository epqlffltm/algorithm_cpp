#include<iostream>
#include<cstdlib>
#include<ctime>

int main(void)
{
	srand(time(NULL));
	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 10;

	int max = 0;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	a > b ? max = a : max = b;
	max = (max > c ? max : c);

	std::cout << "max = " << max << std::endl;

	return 0;
}