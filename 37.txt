#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
bool is_prime(int num);
int to_arr(short*& arr, int num);
int main()
{
	bool flag;
	short* arr = new short[12];
	int counter = 0, sum = 0, temp;
	for (int i = 11; counter < 11 && i <= 800000; i++) {
		if (!is_prime(i)) continue;
		temp = i / 10;
		flag = true;
		while (temp != 0 && flag) {
			if (!is_prime(temp)) flag = false;
			temp /= 10;
		}
		for (int j = to_arr(arr, i) + 1; j < 12 && flag; j++) {
			temp = 0;
			for (int k = 11, m = 1; k >= j && flag; k--, m *= 10) {
				temp += arr[k] * m;
			}
			if (!is_prime(temp)) flag = false;
		}
		if (flag) {
			counter++;
			sum += i;
		}
	}
	cout << counter << "  :  " << sum;
}
bool is_prime(int num) {
	if (num == 2) return true;
	if (num % 2 == 0)  return false;
	if (num == 1) return false;
	for( int i = num - 2; i > 1; i -= 2){
		if (num % i == 0) return false;
	}
	return true;
}
int to_arr(short*& arr, int num){
	int start = 12;
	for (int i = 0; i < 11; i++) {
		arr[i] = 0;
	}
	for (int j = 11; num != 0; j--, start--, num /= 10) {
		arr[j] = num % 10;
	}
	return start;
}
