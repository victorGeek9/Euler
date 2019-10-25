#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	long long digit = 1;
	int divisors = 0;
	for (short i = 2; divisors < 500; i++) {
		digit += i;
		divisors = 0;
		for (int j = 1; j <= digit; j++) {
			if (digit % j == 0) divisors++;
		}
	}
	cout << digit << " " << divisors << endl;
}