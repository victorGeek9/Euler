#include <iostream>
using namespace std;
bool is_circular_prime(short*& arr, int num);
namespace {
	short* arr = new short[6];
	int arr_size = 6;
}
int main()
{
	int counter = 1;
	for (int i = 3; i < 1000000; i++) {
		if (is_circular_prime(arr, i)) {
			counter++;
		}
	}
	cout << counter;
}
bool is_circular_prime(short*& arr, int num) {
	int start = arr_size, temp = num, dig;
	for (int i = 0; i < arr_size; i++) {
		arr[i] = 0;
	}
	for (int i = arr_size - 1; num != 0; i--, start--) {
		arr[i] = num % 10;
		if (arr[i] % 2 == 0) return false;
		num /= 10;
	}
	for (int j = 3; j <= temp - 2; j += 2) {
		if (temp % j == 0) return false;
	}
	for (int i = start + 1; i < arr_size; i++) {
		dig = arr[arr_size - 1];
		for (int j = arr_size - 1; j > start ; j--) {
			arr[j] = arr[j - 1];
		}
		arr[start] = dig;
		temp = 0;
		for (int j = arr_size - 1, k = 1; j >= start; j--, k *= 10) {
			temp += (arr[j] * k);
		}
		for (int j = 3; j <= temp - 2; j += 2) {
			if (temp % j == 0) return false;
		}
	}
	return true;
}
