#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(long long num);
int main()
{
	bool flag, the_end;
	int max = 0;
	long long temp;
	short** arr = new short* [9], * control = new short[9];
	for (int i = 0; i < 9; i++) arr[i] = new short[9];
	for (int i = 2; i < 10; i++) {
		for (int i = 0; i < 9; i++) {
			control[i] = i + 1;
			for (int j = 0; j < 9; j++) {
				arr[i][j] = j + 1;
			}
		}
		flag = true;
		while (flag) {
			temp = 0;
			for (int k = 0, m = 0; k < i; k++) {
				if (control[k] == i) m++;
				if (m == i) flag = false;
				temp *= 10;
				temp += arr[i - 1][k];
			}
			if (is_prime(temp)) {
				max = temp;
			}
			the_end = true;
			for (int j = i - 2; j >= 0 && the_end; j--) {
				if (control[j] == i) {
					control[j] = j + 1;
				}
				else {
					swap(arr[j][j], arr[j][control[j]]);
					control[j]++;
					the_end = false;
					for (int m = j; m < i; m++) {
						for (int k = 0; k < 9; k++) {
							arr[m][k] = arr[j][k];
						}
					}
				}	
			}
		}
	}
	cout << max;
	for (int i = 0; i < 9; i++) delete[] arr[i];
	delete[] control;
	delete[] arr;
}
bool is_prime(long long num) {
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	for (int i = 3; i < num; i += 2) {
		if (num % i == 0) return false;
	}
	return true;
}