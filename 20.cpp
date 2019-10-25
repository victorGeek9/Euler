#include <iostream>
using namespace std;
void composition(short* a, short* b, int len_1, int len_2);
short* to_short_arr(int n);
short* factor(int n);
short* a;
int main()
{
	short* result = factor(100), sum = 0;
	for (int i = 0; i < 200; i++) sum += result[i];
	cout << sum;
	system("pause");
}
void composition(short* a, short* b, int len_1, int len_2) {
	short* result = new short[200], index;
	for (int i = 0; i < 200; i++)
		result[i] = 0;
	for (int i = len_1 - 1, k = 1; i >= 0; i--, k++) {
		index = 200 - k;
		for (int j = len_2 - 1; j >= 0; j--) {
			result[index] += a[i] * b[j];
			if (result[index] > 9) {
				result[index - 1] += result[index] / 10;
				result[index] %= 10;
			}
			index--;
		}
	}
	for(int i = 0; i < 200; i++){
		a[i] = result[i];
	}
	delete[] result;
}
short* factor(int n) {
	int temp = n;
	short* b;
	a = to_short_arr(n);
	b = to_short_arr(--n);
	composition(a, b, 200, 200);
	for (int i = 0; i < 200; i++) cout << a[i];
	cout << endl;
	for (--n; n > 1; n--) {
		delete[] b;
		b = to_short_arr(n);
		composition(a, b, 200, 200);
		for (int i = 0; i < 200; i++) cout << a[i];
		cout << endl;
	}
	return a;
}
short* to_short_arr(int n) {
	short* a = new short[200];
	for (int i = 199; i >= 0; i--) a[i] = 0;
	for (int i = 199; n != 0; n /= 10, i--) a[i] = n % 10;
	return a;
}

