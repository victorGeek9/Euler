#include <iostream>
using namespace std;
int factor(int num);
int main()
{
	int number, temp, sum = 0;
	for (int i = 11; i < 100000; i++) {
		temp = i;
		number = 0;
		while (temp != 0) {
			number += factor(temp % 10);
			temp /= 10;
		}
		if (number == i) sum += i;
	}
	cout << sum;
}
int factor(int num) {
	int result = 1;
	while (num != 0) {
		result *= num;
		num--;
	}
	return result;
}