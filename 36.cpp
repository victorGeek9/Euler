#include <iostream>
using namespace std;
bool is_polindrom_in_10(short*& arr, int num);
bool is_polindrom_in_2(short*& bin, int num);
namespace {
	short* arr = new short[6], * bin = new short[20];
	int arr_size = 6, bin_size = 20;
}
int main()
{
	int sum = 0;
	for (int i = 1; i < 1000000; i++) {
		if (is_polindrom_in_10(arr, i) && is_polindrom_in_2(bin, i)) {
			sum += i;
		}
	}
	cout << sum;
	delete[] arr;
	delete[] bin;
}
bool is_polindrom_in_10(short*& arr, int num) {
	int start = 6;
	bool result = true;
	for (int i = 0; i < arr_size; i++) {
		arr[i] = 0;
	}
	for (int i = arr_size - 1; num != 0; i--, start--) {
		arr[i] = num % 10;
		num /= 10;
	}
	for (int i = arr_size - 1; start < i && result; i--, start++) {
		if (arr[start] != arr[i]) {
			result = false;
		}
	}
	return result;
}
bool is_polindrom_in_2(short*& bin, int num){
	int start = bin_size;
	bool result = true;
	for (int i = 0; i < bin_size; i++) {
		bin[i] = 0;
	}
	for (int i = bin_size - 1; num != 0 && i >= 0; num /= 2, i--, start--) {
		bin[i] = num % 2;
	}
	for (int i = bin_size - 1; start < i && result; start++, i--) {
		if (bin[i] != bin[start]) {
			result = false;
		}
	}
	return result;
}