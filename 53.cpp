#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
namespace {
	short* result = new short[200], * templ = new short[200], *arr = new short[3];
	const int result_amount = 199;
}
void compos(short*& arr1, short*& arr2, int arr_size1, int arr_size2, short*& result);
void fraction(short*& arr, int num, int arr_size, short*& result);
int main()
{
	bool flag = false;
	int temp, counter = 0, board;
	for (int i = 0; i <= result_amount; i++) {
		result[i] =  templ[i] = 0;
	}
	templ[result_amount] = 1;
	for (int i = 3; i <= 100; i++) {
		temp = ((double)i / 2) + 0.5;
		board = 1000000;
		for (int j = temp; j < i && board >= 1000000; j++) {
			flag = false;
			for (int i = 0; i <= result_amount; i++) {
				templ[i] = 0;
			}
			templ[result_amount] = 1;
			for (int k = j + 1; k <= i; k++) {
				for (int in = 0; in < 3; in++) arr[in] = 0;
				for (int in = 2, var = k; var > 0; in--, var /= 10) {
					arr[in] = var % 10;
				}
				compos(templ, arr, result_amount + 1, 3, result);
				for (int i = 0; i <= result_amount; i++) {
					templ[i] = result[i];
					result[i] = 0;
				}
			}
			for (int k = i - j; k > 1; k--) {
				fraction(templ, k, result_amount + 1, result);
				for (int i = 0; i <= result_amount; i++) {
					templ[i] = result[i];
					result[i] = 0;
				}
			}
			for (int i = 0; i < 193 && !flag; i++) {
				if (templ[i] != 0) flag = true;
			}
			if (flag) {
				if (j == temp && i % 2 == 0) {
					counter++;
				}
				else {
					counter += 2;
				}
			}
			else {
				if (templ[193] == 0) {
					board = 0;
				}
				else {
					board = 0;
					for (int k = 193; k <= result_amount; k++) {
						board *= 10;
						board += templ[k];
					}
					if (board >= 1000000) {
						if (j == temp && i % 2 == 0) {
							counter++;
						}
						else {
							counter += 2;
						}
					}
				}
			}
		}
	}
	cout << counter;
	delete[] arr;
	delete[] templ;
	delete[] result;
}
void fraction(short*& arr, int num, int arr_size, short*& result) {
	short* arr_temp = new short[arr_size];
	for (int i = 0; i < arr_size; i++) arr_temp[i] = 0;
	int index = 0, temp = 0, templ = 0;
	for (; arr[index] == 0; index++);
	for (int i = index; i < arr_size; i++) {
		for (int j = i; temp < num && j < arr_size; j++, i++) {
			temp *= 10;
			temp += arr[j];
			arr_temp[templ] = 0;
			templ++;
		}
		i--;
		templ--;
		arr_temp[templ] = temp / num;
		temp %= num;
		templ++;
	}
	templ--;
	for (int i = result_amount; templ >= 0; i--, templ--) {
		result[i] = arr_temp[templ];
	}
	delete[] arr_temp;
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