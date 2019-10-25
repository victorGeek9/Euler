#include <iostream>
#include <cmath>
using namespace std;
void compos(short* arr1, short* arr2, int arr_size1, int arr_size2, short* result);
namespace {
	short* result = new short[100];
	int result_amount = 100;
}
int main()
{
	long long start, counter = 50;
	int index;
	short* arr = new short[result_amount], * temp = new short[result_amount], * temp_result = new short[result_amount];
	for (int i = 0; i < result_amount; i++) arr[i] = temp_result[i] = temp[i] = 0;
	start = 1ll << 50;
	for (int i = result_amount - 1; start != 0; start /= 10, i--) arr[i] = temp[i] = start % 10;
	for (int i = 1; counter < 6000000; i++) {
		compos(arr, temp, result_amount, result_amount, result);
		for (int i = result_amount - 10; i < result_amount; i++) arr[i] = temp[i] = result[i];
		counter *= 2;
	}
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	index = counter;
	counter = 50;
	start = 1ll << 50;
	for (int i = 0; i < result_amount; i++) arr[i] = temp[i] = 0;
	for (int i = result_amount - 1; start != 0; start /= 10, i--) arr[i] = temp[i] = start % 10;
	for (int i = 1; counter < 800000; i++) {
		compos(arr, temp, result_amount, result_amount, temp_result);
		for (int i = result_amount - 10; i < result_amount; i++) arr[i] = temp[i] = temp_result[i];
		counter *= 2;
	}
	compos(arr, result, result_amount, result_amount, temp_result);
	index += counter;
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	counter = 50;
	start = 1ll << 50;
	for (int i = 0; i < result_amount; i++) arr[i] = temp[i] = 0;
	for (int i = result_amount - 1; start != 0; start /= 10, i--) arr[i] = temp[i] = start % 10;
	for (int i = 1; counter < 400000; i++) {
		compos(arr, temp, result_amount, result_amount, result);
		for (int i = result_amount - 10; i < result_amount; i++) arr[i] = temp[i] = result[i];
		counter *= 2;
	}
	compos(arr, temp_result, result_amount, result_amount, result);
	index += counter;
	counter = 50;
	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////
	start = 1ll << 50;
	for (int i = 0; i < result_amount; i++) arr[i] = temp[i] = 0;
	for (int i = result_amount - 1; start != 0; start /= 10, i--) arr[i] = temp[i] = start % 10;
	for (int i = 1; counter < 25000; i++) {
		compos(arr, temp, result_amount, result_amount, temp_result);
		for (int i = result_amount - 10; i < result_amount; i++) arr[i] = temp[i] = temp_result[i];
		counter *= 2;
	}
	compos(arr, result, result_amount, result_amount, temp_result);
	index += counter;
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	start = 1ll << 50;
	for (int i = 0; i < result_amount; i++) {
		temp[i] = 0;
		arr[i] = temp_result[i];
	}
	for (int i = result_amount - 1; start != 0; start /= 10, i--) temp[i] = start % 10;
	for (int i = 1; index < 7830450; i++) {
		compos(arr, temp, result_amount, result_amount, temp_result);
		for (int i = result_amount - 10; i < result_amount; i++) arr[i] = temp_result[i];
		index += 50;
	}
	start = 1ll << 7;
	for (int i = 0; i < result_amount; i++) {
		temp[i] = 0;
	}
	for (int i = result_amount - 1; start != 0; i--, start /= 10) temp[i] = start % 10;
	compos(arr, temp, result_amount, result_amount, result);
	start = 28433;
	for (int i = 0; i < result_amount; i++) temp[i] = 0;
	for (int i = result_amount - 1; start != 0; start /= 10, i--) temp[i] = start % 10;
	compos(result, temp, result_amount, result_amount, temp_result);
	temp_result[result_amount - 1]++;
	for (int i = result_amount - 10; i < result_amount; i++) cout << temp_result[i];
	delete[] arr;
	delete[] temp;
	delete[] result;
	delete[] temp_result;
}
void compos(short* arr1, short* arr2, int arr_size1, int arr_size2, short* result) {
	short* ptr1, * ptr2;
	int max, min, start1, start2, temp;
	if (arr_size1 > arr_size2) {
		ptr1 = arr1;
		ptr2 = arr2;
		max = arr_size1;
		min = arr_size2;
		for (start2 = 0; arr1[start2] == 0; start2++);
		for (start1 = 0; arr2[start1] == 0; start1++);
	}
	else {
		ptr1 = arr2;
		ptr2 = arr1;
		max = arr_size2;
		min = arr_size1;
		for (start2 = 0; arr2[start2] == 0; start2++);
		for (start1 = 0; arr1[start1] == 0; start1++);
	}
	max--;
	min--;
	for (int i = 0; i < result_amount; i++) result[i] = 0;
	for (int i = min, index = result_amount - 1; i >= start1; i--, index--) {
		temp = index;
		for (int j = max; j >= start2; j--, temp--) {
			result[temp] += ptr2[i] * ptr1[j];
			if (result[temp] > 9) {
				result[temp - 1] += result[temp] / 10;
				result[temp] %= 10;
			}
		}
	}
}
