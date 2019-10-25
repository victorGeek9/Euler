#include <iostream>
#include <cmath>
using namespace std;
bool is_polindrom(short*& num);
void num_to_arr(int num, short*& arr);
void sum(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short*& result);
namespace {
	short* templ = new short[30];
	const int result_amount = 29;
}
int main() {
	bool flag;
	short counter = 0, *temp = new short[30], *arr = new short[30], *num = new short[30], index;
	for (int i = 1; i < 10000; i++) {
		flag = true;
		num_to_arr(i, num);
		for (int j = 1; flag && j <= 50; j++) {
			for (int i = 0; i <= result_amount; i++) {
				temp[i] = num[i];
			}
			for (int k = 0; k <= result_amount; k++) arr[k] = 0;
			for (index = 0; temp[index] == 0; index++);
			for (int k = result_amount; index <= result_amount; k--, index++) {
				num[k] = temp[index];
			}
			sum(temp, num, result_amount + 1, result_amount + 1, arr);
			for (int i = 0; i <= result_amount; i++) {
				num[i] = arr[i];
			}
			if (is_polindrom(num)) {
				flag = false;
			}
		}
		if (flag == true) {
			counter++;
		}
	}
	cout << counter;
	delete[] arr;
}
bool is_polindrom(short*& num) {
	int index = 0;
	for (; num[index] == 0; index++);
	for (int i = 29; i > index; i--, index++) {
		if (num[i] != num[index]) {
			return false;
		}
	}
	return true;
}
void sum(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short*& result) {
	int index = result_amount, min, max;
	short* max_arr, * min_arr;
	for (int i = 0; i <= result_amount; i++) templ[i] = 0;
	if (arr_size1 < arr_size2) {
		min = arr_size1;
		max = arr_size2;
		max_arr = arr2;
		min_arr = arr1;
	}
	else {
		min = arr_size2;
		max = arr_size1;
		max_arr = arr1;
		min_arr = arr2;
	}
	min--;
	max--;
	for (; min >= 0; index--, min--, max--) {
		templ[index] += max_arr[max] + min_arr[min];
		if (templ[index] > 9) {
			templ[index - 1] += templ[index] / 10;
			templ[index] %= 10;
		}
	}
	for (; max >= 0; index--, max--) {
		templ[index] += max_arr[max];
		if (templ[index] > 9) {
			templ[index - 1] += templ[index] / 10;
			templ[index] %= 10;
		}
	}
	if (templ[index] > 9) {
		templ[index - 1] += templ[index] / 10;
		templ[index] %= 10;
	}
	for (int i = 0; i <= result_amount; i++) result[i] = templ[i];
}
void num_to_arr(int num, short*& arr) {
	for (int i = 0; i <= result_amount; i++) arr[i] = 0;
	for (int i = result_amount; num != 0; i--, num /= 10) {
		arr[i] = num % 10;
	}
}