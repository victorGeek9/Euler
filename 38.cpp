#include <iostream>
using namespace std;
namespace {
	short* arr = new short[10];
}
bool is_pandigital(short*& arr);
void has_digits(long long num, short*& arr, int& amount);
int main()
{
	int result = 0, amount, index, mult = 0;
	long long temp;
	for (int i = 1; i < 100000; i++) {
		amount = 0;
		for (int j = 0; j < 10; j++) arr[j] = 0;
		for (index = 1; amount < 9; index++) {
			temp = (long long)i * (long long)index;
			has_digits(temp, arr, amount);
		}
		if (amount == 9 && index > 2) {
			if (is_pandigital(arr)) {
				result = i;
				mult = index - 1;
			}
		}
	}
	for (int i = 1; i <= mult; i++) cout << result * i;
	delete[] arr;
}

void has_digits(long long num, short*& arr, int& amount) {
	while (num != 0) {
		arr[num % 10]++;
		num /= 10;
		amount++;
	}
}
bool is_pandigital(short*& arr) {
	if (arr[0] != 0) return false;
	for (int i = 1; i < 10; i++) if (arr[i] != 1) return false;
	return true;
}

