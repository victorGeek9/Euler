#include <iostream>
using namespace std;
int main()
{
	int increase = 2, result = 1, number = 1;
	for (int i = 1; increase <= 1000; i++) {
		number += increase;
		result += number;
		cout << number << endl;
		if (i % 4 == 0) {
			increase += 2;
		}
	}
	cout << result;
	return 0;
}
