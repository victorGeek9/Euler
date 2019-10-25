#include <iostream>
using namespace std;
bool is_prime(int num);
int main()
{
	bool flag = true, ok;
	int temp, sq, result = 0;
	for (int i = 9; flag; i += 2) {
		if (!is_prime(i)) {
			ok = true;
			for (int j = 1, sq = 2 * j * j; ok && sq < i; ++j, sq = 2 * j * j) {
				temp = i - sq;
				if (is_prime(temp)) ok = false;
			}
			if (ok) {
				result = i;
				flag = false;
			}
		}
	}
	cout << result;
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
