#include <iostream>
using namespace std;
int main()
{
	int max_amount = 1, amount, max_number = 2;
	long long start = 3, temp = 3;
	while (temp < 1000000) {
		amount = 1;
		while (temp > 1) {
			amount++;
			if (temp % 2 == 0) {
				temp /= 2;
			}
			else {
				temp *= 3;
				temp++;
			}
		}
		if (max_amount < amount) {
			max_amount = amount;
			max_number = start;
		}
		temp = ++start;
	}
	cout << max_number << "  " << amount;
}
