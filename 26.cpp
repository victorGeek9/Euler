#include <iostream>
#include <cmath>
using namespace std;
int division(int num);
int main()
{
	int max = 0, result = 0, temp;
	for (int i = 1; i < 1000; i++) {
		temp = division(i);
		if (temp > max) {
			max = temp;
			result = i;
		}
	}
	cout << result;
}
int division(int num) {
	while (num % 2 == 0) num /= 2;
	while (num % 5 == 0) num /= 5;
	if (num == 1) return 0;
	int temp, counter = 0;
	short* arr = new short[1000], index = 998;
	for (int i = 0; i < 1000; i++) arr[i] = 0;
	arr[index] = 1;
	bool flag = true;
	while (flag) {
		temp = 0;
		for (int i = index; i < 1000; i++) {
			temp *= 10;
			temp += arr[i];
			temp %= num;
		}
		counter++;
		if (temp == 1) {
			flag = false;
		}
		else {
			arr[index] = 0;
			index--;
			arr[index] = 1;
		}
	}
	delete[] arr;
	return counter;
}