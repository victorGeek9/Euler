#include <iostream>
#include <fstream>
using namespace std;
bool is_prime(int digit);
int main()
{
	long long sum = 0;
	for (int i = 2000000; i > 1; i--) {
		if (is_prime(i)) sum += i;
	}
	sum += 2;
	cout << sum;
}
bool is_prime(int digit) {
	if (digit % 2 == 0) return false;
	for (int i = 3; i < digit; i += 2) {
		if (digit % i == 0) return false;
	}
	return true;
}