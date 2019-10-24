#include <iostream>
#include <vector>
using namespace std;
namespace {
	vector<int> prime, first, second, thirth, fourth;
}
void select_ptr(vector<int>*& v, int num);
bool is_prime(int num);
int find_factors(int num, vector<int>* v);
int main()
{
	bool flag = true, loop, has_four_factors = false;
	int index = 0, number = 10, *temp = new int[4], board = 0, result = 0, board_temp;
	short amount1, amount2, amount3, amount4;
	vector<int>* ptr;
	for (int i = 2; i < 200000; i++) {
		if (is_prime(i)) {
			index++;
			prime.push_back(i);
			first.push_back(0);
			second.push_back(0);
			thirth.push_back(0);
			fourth.push_back(0);
		}
	}
	for (int i = 0; i < 4; i++, number++) {
		select_ptr(ptr, i);
		board_temp = find_factors(number, ptr);
		if (board < board_temp) board = board_temp;
	}
	for (int i = 0; flag && number < 200000; i++, number++) {
		amount1 = amount2 = amount3 = amount4 = 0;
		for (int j = 0; j <= board; j++) {
			if (first[j] != 0) amount1++;
			if (second[j] != 0) amount2++;
			if (thirth[j] != 0) amount3++;
			if (fourth[j] != 0) amount4++;
		}
		if (amount1 == amount2 && amount1  == amount3 && amount1 == amount4 && amount1 == 4) has_four_factors = true;
		if (has_four_factors) {
			loop = true;
			for (int j = 0; j <= board && loop; j++) {
				for (int k = 0; k < 4; k++) {
					select_ptr(ptr, k);
					temp[k] = (*ptr)[j];
				}
				for (int k = 0; k < 3 && loop; k++) {
					if (temp[k] != 0) {
						for (int m = k + 1; m < 4 && loop; m++) {
							if (temp[k] == temp[m]) loop = false;
						}
					}
				}
			}
			if (loop == true) {
				flag = false;
				result = number - 4;
			}
		}
		select_ptr(ptr, i);
		for (int i = 0; i < index; i++) (*ptr)[i] = 0;
		board_temp = find_factors(number, ptr);
		if (board < board_temp) board = board_temp;
	}
	cout << result;
	delete[] temp;
}
bool is_prime(int num) {
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	int temp = 3;
	while (temp < num) {
		if (num % temp == 0) return false;
		temp += 2;
	}
	return true;
}
int  find_factors(int num, vector<int>* v) {
	int i = 0;
	for (; num != 1; i++) {
		if (num % prime[i] == 0) {
			num /= prime[i];
			(*v)[i]++;
			i--;
		}
	}
	return i;
}
void select_ptr(vector<int>*& v, int num) {
	num %= 4;
	switch (num) {
	case 0: v = &first; break;
	case 1: v = &second; break;
	case 2: v = &thirth; break;
	case 3: v = &fourth; break;
	}
}