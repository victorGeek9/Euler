#include <iostream>

using namespace std;

int main()
{
	int a = 1, b = 2, sum, temp;
	while (a <= 4000000) {
		if (b % 2 == 0) sum += b;
		temp = b;
		b += a;
		a = temp;
	}
	cout << sum;
}