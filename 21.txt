#include <iostream>
#include <string>
using namespace std;
int sum_divisors(int num);
void display_divisors(int num);
int main() {
	int result;
	short* amicable = new short[100], index = 0, temp;
	bool next_itr;
	for (int i = 0; i < 100; i++) amicable[i] = 0;
	for (int i = 8; i < 10000; i++) {
		next_itr = false;
		for (int j = 0; j < 100 && amicable[j] != 0; j++) {
			if (i == amicable[j]) {
				next_itr = true;
				break;
			}
		}
		if (next_itr) continue;
		temp = sum_divisors(i);
		if (i == sum_divisors(temp) && temp != i) {
			cout << i << "  " << temp << endl;
			display_divisors(i);
			display_divisors(temp);
			amicable[index] = i;
			amicable[++index] = temp;
			index++;
		}
	}
	result = amicable[0];
	for (int j = 1; j < 100 && amicable[j] != 0; j++) {
		result += amicable[j];
	}
	cout << result;
	delete[] amicable;
}
int sum_divisors(int num) {
	int result = 1;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) result += i;
	}
	return result;
}
void display_divisors(int num){
	for (int i = 2; i < num; i++) {
		if (num % i == 0) cout << i << "  ";
	}
	cout << endl;
}