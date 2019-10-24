#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int amount = 7000;
int main()
{
	short* arr = new short[28123];
	int board = 28123, sum, index = 0, even, temp;
	int* abundant = new int[amount];
	long long result = 0;
	for (int i = 0; i < amount; i++) abundant[i] = 0;
	for (int i = 12; i < board; i++) {
		even = 2;
		sum = 0;
		if (i % 2 == 0) {
			even = 1;
		}
		for (int j = i - even; j > 0; j -= even) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum > i) {
			abundant[index] = i;
			index++;
		}
	}
	for (int i = 0; i <= board; i++) {
		result += i;
	}
	index = 0;
	for (; index < amount && abundant[index] != 0; index++);
	for (int i = 0; i < 28100; i++) {
		arr[i] = i + 24;
	}
	
	for (int i = 0; i < index; i++) {
		temp = abundant[i];
		for (int j = i; j < index; j++) {
			abundant[j] += temp;
			if (abundant[j] - 24 < 28100) {
				for (int h = abundant[j] - 24; h < 28100 && abundant[j] >= arr[h]; h++) {
					if (abundant[j] == arr[h]) {
						arr[h] = 0;
						result -= abundant[j];
					}
				}
			}
			abundant[j] -= temp;
		}
	}
	cout << result;
	delete[] abundant;
	delete[] arr;
	return 0;
}