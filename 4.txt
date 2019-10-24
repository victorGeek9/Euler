#include <iostream>

using namespace std;
bool isPolindrom(int);
int main()
{
	int a = 999, b = 999, temp = 999, index = 0, arr[10000];
	bool polidrom = false;
	while (a > 0) {
		while (b > 0) {
			if (isPolindrom(a * b)) {
				arr[index] = a * b;
				index++;
			}
			b--;
		}
		b = --temp;
		a--;
	}
	int max = arr[0];
	for (int j = 1; arr[j] != 0; j++) {
		if (max < arr[j]) max = arr[j];
	}
	cout << max;
}
bool isPolindrom(int i) {
	int *p = new int[10], j = 0;
	for (; i != 0; j++) {
		p[j] = i % 10;
		i /= 10;
	}
	j--;
	while (i < j) {
		if (p[i] != p[j]) {
			delete[] p;
			return false;
		}
		i++;
		j--;
	}
	delete[] p;
	return true;
}
//999 999-1
//998 998-1
//997 997-1