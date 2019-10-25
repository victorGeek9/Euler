#include <iostream>

using namespace std;

int main()
{
	int sum = 0, comp = 0;
	for (int i = 1; i <= 100; i++) sum += i;
	for (int i = 1; i <= 100; i++) {
		comp += i * i;
	}
	cout << sum *sum - comp;
}