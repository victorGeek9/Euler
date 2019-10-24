#include <iostream>
using namespace std;
void sum(short* a, short* b, int a_size, int b_size);
short* previous = new short[1000], *result = new short[1000], *temp = new short[1000];
int main() {
	int index = 2;
	for (int i = 0; i < 1000; i++) {
		previous[i] = result[i] = temp[i] = 0;
	}
	result[999] = previous[999] = 1;
	while (result[0] == 0) {
		for (int i = 0; i < 1000; i++) {
			temp[i] = result[i];
		}
		sum(temp, previous, 1000, 1000);
		index++;
		for (int i = 0; i < 1000; i++) {
			previous[i] = temp[i];
		}
	}
	for (int i = 0; i < 1000; i++) {
		cout << result[i];
	}
	cout << endl << index;
	delete[] temp;
	delete[] previous;
	delete[] result;
}
void sum(short* a, short* b, int a_size, int b_size) {
	int index;
	for (int i = 0; i < 1000; i++) result[i] = 0;
	a_size--;
	b_size--;
	for (index = 999; b_size >= 0; a_size--, b_size--, index--) {
		result[index] += a[a_size] + b[b_size];
		if (result[index] > 9) {
			result[index - 1] += result[index] / 10;
			result[index] %= 10;
		}
	}
	for (; a_size >= 0; index--, a_size--) {
		result[index] += a[a_size];
		if (result[index] > 9) {
			result[index - 1] += result[index] / 10;
			result[index] %= 10;
		}
	}
}
