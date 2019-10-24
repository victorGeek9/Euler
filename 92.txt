#include <iostream>
using namespace std;
int main()
{
	int board = 10000000, counter = 0, temp, pow;
	long long number;
	for (int i = 1; i < board; i++) {
		number = i;
		while (number != 89 && number != 1) {
			temp = 0;
			while (number != 0) {
				pow = number % 10;
				number /= 10;
				temp += pow * pow;
			}
			number = temp;
		}
		if (number == 89) counter++;
	}
	cout << counter;
}