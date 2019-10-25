#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	bool flag;
	int counter = 1, index;
	short** arr = new short* [9], * control = new short[9], * result = new short[10];
	for (int i = 0; i < 9; i++) arr[i] = new short[10];
	for (int i = 0; i < 9; i++) {
		control[i] = i;
		for (int j = 0; j < 10; j++) {
			arr[i][j] = j;
		}
	}
	for (; counter != 1000000;) {
		flag = true;
		for (int i = 8; i >= 0 && flag; i--) {
			if (control[i] == 9) {
				control[i] = i;
			}
			else {
				control[i]++;
				swap(arr[i][control[i]], arr[i][i]);
				for (int j = i; j <= 8; j++) {
					for (int k = 0; k < 10; k++) {
						arr[j][k] = arr[i][k];
					}
				}
				flag = false;
			}
		}
		++counter;
		if (counter == 1000000) {
			for (int i = 0; i < 10; i++) result[i] = arr[8][i];
		}
	}
	for (int i = 0; i < 10; i++) cout << result[i];
	for (int i = 0; i < 9; i++) delete[] arr[i];
	delete[] result;
	delete[] control;
	delete[] arr;
}