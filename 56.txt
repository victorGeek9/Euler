#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
namespace {
	short* result = new short[201], * templ = new short[201], *arr = new short[2];
	const int result_amount = 200;
}
void compos(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short*& result);
int main()
{
	int sum = 0, temp;
	for (int i = 2; i < 100; i++) {
		for (int ind = 0; ind <= result_amount; ind++) templ[ind] = 0;
		for (int j = 0; j < 2; j++) arr[j] = 0;
		for (int j = 1, var = i, ind = result_amount; j >= 0 && var != 0; j--, var /= 10, ind--) {
			arr[j] = var % 10;
			templ[ind] = arr[j];
		}
		for (int j = 2; j < 100; j++) {
			temp = 0;
			for (int ind = 0; ind <= result_amount; ind++) result[ind] = 0;
			compos(templ, arr, result_amount + 1, 2, result);
			for (int ind = 0; ind <= result_amount; ind++) {
				templ[ind] = result[ind];
				temp += templ[ind];
			}
			if (temp > sum) sum = temp;
		}
	}
	cout << sum;
	delete[] arr;
	delete[] templ;
	delete[] result;
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