#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int max = 0, temp, result = 0;
	short* arr = new short[1000];
	for (int i = 0; i < 1000; i++) {
		arr[i] = 0;
	}
	for (int i = 5; i <= 998; i++) {
		for (int j = 4; j < 998 && i > j; j++) {
			for (int k = 3; ((i * i) >= (j * j + k * k)) && ((i + j + k) <= 1000); k++) {
				if (i * i == (j * j + k * k)) {
					temp = i + j + k - 1;
					arr[temp]++;
				}
			}
		}
	}
	for (int i = 0; i < 1000; i++) {
		if (arr[i] > max) {
			max = arr[i];
			result = i + 1;
		}
	}
	cout << result;
	delete[] arr;
}