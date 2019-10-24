#include <iostream>
#include <cmath>
using namespace std;
void sum(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short*& result);
void comp(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short*& result);
namespace {
	short* result = new short[5010], *templ = new short[5010];
	short* temp = new short[5001];
	const int result_amount = 5009;
	const int temp_amount = 5000;
}
int main()
{
	short* arr = new short[result_amount + 1];
	short* temp1 = new short[temp_amount + 1];
	for (int i = 0; i <= result_amount; i++) result[i] = 0;
	result[result_amount] = 1;
	for (int j = 0; j <= temp_amount; j++) {
		temp[j] = temp1[j] = 0;
	}
	for (int i = 2, val = i; i <= 1000; i++, val = i) {
		for (int j = 0; j <= temp_amount; j++) {
			temp[j] = temp1[j] = 0;
		}
		for (int j = temp_amount; val != 0; j--) {
			temp[j] = temp1[j] = val % 10;
			val /= 10;
		}
		
		val = i;
		for (; val > 1; val--) {
			for (int j = 0; j <= result_amount; j++) arr[j] = 0;
			comp(temp1, temp, temp_amount + 1, temp_amount + 1, arr);
			for (int j = temp_amount; j >= 0; j--) {
				temp1[j] = arr[j + result_amount - temp_amount];
			}
		}
		
		sum(result, arr, result_amount + 1, result_amount + 1, result);
	}
	for (int i = 0; i <= result_amount; i++) cout << result[i];
	cout << endl << endl << "result:  ";
	for (int i = result_amount - 9; i <= result_amount; i++) cout << result[i];
	delete[] result;
	delete[] temp;
	delete[] temp1;
	delete[] arr;
	delete[] templ;
}
void sum(short*  &arr1, short* &arr2, int arr_size1, int arr_size2, short*& result) {
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
void comp(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short* &result) {
	int index, min, max, start1, start2;
	short* max_arr, *min_arr;
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
