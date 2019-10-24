#include <iostream>
#include <vector>
using namespace std;
void display_arr(short*& arr);
void copy_arr(short*& arr, short*& arr1);
void num_to_arr(int num, short*& arr, vector<int>& v);
void compare(short*& arr, short*& arr1, int& counter);
bool is_prime(int num);
int main()
{
	bool flag = true;
	short* arr = new short[4], *temp1 = new short[4], * temp2 = new short[4], * temp3 = new short[4];
	int index = 0, var, counter;
	vector<int> v;
	for (int i = 1000; i < 10000; i++) {
		if (is_prime(i)) {
			v.push_back(i);
			index++;
		}
	}
	for (int i = 0; i < index && flag; i++) {
		num_to_arr(i, arr, v);
		for (int j = i + 1; j < index && flag; j++) {
			num_to_arr(j, temp1, v);
			copy_arr(temp1, temp2);
			compare(arr, temp1, counter);
			if (counter == 4) {
				for (int l = j + 1; l < index && flag; l++) {
					num_to_arr(l, temp1, v);
					copy_arr(temp1, temp3);
					compare(arr, temp1, counter);
					if (counter == 4 && v[l] - v[j] == v[j] - v[i] && v[i] != 1487) {
						flag = false;
					}
				}
			}
		}
	}
	display_arr(arr);
	display_arr(temp2);
	display_arr(temp3);
	delete[] arr;
	delete[] temp1;
	delete[] temp2;
	delete[] temp3;
}
void copy_arr(short*& arr, short*& arr1) {
	for (int k = 0; k < 4; k++) {
		arr1[k] = arr[k];
	}
}
void compare(short*& arr, short*& arr1, int& counter) {
	counter = 0;
	for (int k = 0; k < 4; k++) {
		for (int m = 0; m < 4; m++) {
			if (arr[k] == arr1[m]) {
				counter++;
				arr1[m] = -1;
				break;
			}
		}
	}
}
void num_to_arr(int num, short*& arr, vector<int>& v) {
	for (int k = 3, var = v[num]; var != 0; var /= 10, k--) {
		arr[k] = var % 10;
	}
}
bool is_prime(int num) {
	if (num % 2 == 0) return false;
	int temp = 3;
	while (temp < num) {
		if (num % temp == 0) return false;
		temp += 2;
	}
	return true;
}
void display_arr(short*& arr) {
	for (int i = 0; i < 4; i++) cout << arr[i];
}