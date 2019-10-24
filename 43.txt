#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(long long num);
int main()
{
	long long temp, sum = 0;
	bool flag, the_end = true, ok;
	short** arr = new short* [9], * control = new short[9], *primes = new short[7];
	for (int i = 0, j = 2; i < 7; i++, j++) {
		for (; !is_prime(j); j++);
		primes[i] = j;
	}
	for (int i = 0; i < 9; i++) arr[i] = new short[10];
	for (int i = 0; i < 9; i++) {
		control[i] = i;
		for (int j = 0; j < 10; j++) {
			arr[i][j] = j;
		}
	}
	while(the_end) {
		flag = true;
		ok = true;
		for (int i = 0; i < 7 && ok; i++) {
			temp = 0;
			for (int j = i + 1, k = 0; k < 3; j++, k++) {
				temp *= 10;
				temp += arr[8][j];
			}
			if (temp % primes[i] != 0) ok = false;
		}
		if (ok) {
			temp = 0;
			for (int j = 0; j < 10; j++) {
				temp *= 10;
				temp += arr[8][j];
			}
			sum += temp;
		}
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
		for (int i = 0, j = 9; i < 10; i++, j--) {
			if (arr[8][i] != j)break;
			if (i == 9) the_end = false;
		}
	}
	cout << sum;
	for (int i = 0; i < 9; i++) delete[] arr[i];
	delete[] primes;
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