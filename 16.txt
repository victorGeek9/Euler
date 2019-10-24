#include <iostream>
#include <cmath>
using namespace std;
short* composition(short* a, short* b, int len_1, int len_2);
int main()
{
	int index = 349, sum = 0;
	long long power = pow(2, 50);
	short *arr = new short[16], *result = new short[350], *temp = new short[350];
	for (int i = 0; i < 350; i++) {
		result[i] = 0;
	}
	for (int i = 15; i >= 0; i--, index--) {
		arr[i] = power % 10;
		result[index] = arr[i];
		power /= 10;
	}
	for (int i = 1; i < 20; i++) {
		for (index = 0; result[index] == 0; index++) {}
		for (int j = index, t = 0; j < 350; j++, t++) {
			temp[t] = result[j];
		}
		result = composition(temp, arr, 350 - index, 16);
	}
	for (int i = 0; i < 350; i++) {
		sum += result[i];
	}
	cout << sum;
	delete[] arr;
}
short* composition(short* a, short* b, int len_1, int len_2) {
	short *result = new short[350], index;
	for (int i = 0; i < 350; i++)
		result[i] = 0;
	for (int i = len_1 - 1, k = 1; i >= 0; i--, k++) {
		index = 350 - k;
		for (int j = len_2 - 1; j >= 0; j--) {
			result[index] += a[i] * b[j];
			if (result[index] > 9) {
				result[index - 1] += result[index] / 10;
				result[index] %= 10;
			}
			index--;
		}
	}
	return result;
}
//2^50 = 1125899906842624
// (2^50)^20