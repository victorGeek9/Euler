#include <iostream>
#include <cmath>
using namespace std;
void sum(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short*& result);
void compos(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short*& result);
short compare(short*& arr1, short*& arr2, int arr_size1, int arr_size2);
namespace {
	short*** result = new short**[99], *templ = new short[203];
	const int result_amount = 202;
}
int main()
{
	int counter = 99, temp;
	bool flag;
	for (int i = 0; i < 99; i++) {
		result[i] = new short*[100];
	}
	for (int i = 0; i < 99; i++) {
		result[i][0] = new short[3];
		for (int j = 1; j <= 99; j++) {
			result[i][j] = new short [result_amount + 1];
		}
	}
	for (int i = 0, number = 2; i < 99; ++i, number = i + 2) {
		for (int index = 2; index >= 0; index--) {
			result[i][0][index] = number % 10;
			number /= 10;
		}
	}
	for (int i = 0; i < 99; ++i) {
		for (int j = 1; j < 100; j++) {
			for (int k = 0; k <= result_amount; k++) {
				result[i][j][k] = 0;
			}
		}
	}
	for (int i = 2; i <= 100; i++) {
		compos(result[i - 2][0], result[i - 2][0], 3, 3, result[i - 2][1]);
	}
	for (int i = 3; i <= 100; i++) {
		for (int j = 2; j <= 100; ++j) {
			compos(result[j - 2][0], result[j - 2][i - 2], 3, result_amount + 1, result[j - 2][i - 1]);
		}
	}
	for (int i = 1; i < 99; i++) {
		for (int j = 1; j < 100; j++) {
			counter++;
			flag = false;
			for (int k = i - 1; k >= 0 && !flag; k--) {
				temp = 1;
				for (int m = 1; m < 100 && temp == 1; m++) {
					temp = compare(result[i][j], result[k][m], result_amount + 1, result_amount + 1);
					if (temp == 0) {
						counter--;
						cout << i + 2 << " ^ " << j + 1 << " = " << k + 2 << " ^ " << m + 1 << endl;
						flag = true;
					}
				}
			}
		}
	}
	cout << counter;
	for (int i = 0; i < 99; i++) {
		for (int j = 0; j <= 99; j++) {
			delete[] result[i][j];
		}
	}
	for (int j = 0; j < 99; j++) {
		delete[] result[j];
	}
	delete[] result;
	delete[] templ;
	return 0;
}
/*
arr1 < arr2  :: -1
arr1 > arr2  ::  1
arr1 == arr2 ::  0
*/
short compare(short*& arr1, short*& arr2, int arr_size1, int arr_size2) {
	int start1, start2, end;
	for (start1 = 0; arr1[start1] == 0; start1++);
	for (start2 = 0; arr2[start2] == 0; start2++);
	if (arr_size1 - start1 < arr_size2 - start2) {
		return -1;
	}
	else {
		if (arr_size1 - start1 > arr_size2 - start2) {
			return 1;
		}
		else {
			end = arr_size1 - start1;
			for (int i = 0; i < end; i++, start1++, start2++) {
				if (arr1[start1] < arr2[start2]) {
					return -1;
				}
				else {
					if (arr1[start1] > arr2[start2]) {
						return 1;
					}
				}
			}
			return 0;
		}
	}
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
void compos(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short*& result) {
	int index, min, max, start1, start2;
	short* max_arr, * min_arr;
	for (start1 = 0; arr1[start1] == 0; start1++);
	for (start2 = 0; arr2[start2] == 0; start2++);
	if (arr_size1 - start1 < arr_size2 - start2) {
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
		swap(start1, start2);
	}
	min--;
	max--;
	for (int i = 0; min >= start1; i++, min--) {
		for (int j = max, index = result_amount - i; j >= start2; j--, index--) {
			result[index] += (max_arr[j] * min_arr[min]);
			if (result[index] > 9) {
				result[index - 1] += result[index] / 10;
				result[index] %= 10;
			}
		}
	}
}