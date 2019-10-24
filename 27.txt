#include <iostream>
#include <vector>
using namespace std;
bool is_prime(int n);
int find_answer(const int& a, const int& b, const int& n);
int main()
{
	bool flag;
	int counter = 0, counter_temp, temp, result = 0;
	for (int i = -999; i < 1000; i++) {
		for (int j = -999; j <= 1000; j++) {
			counter_temp = 0;
			flag = true;
			for (int n = 0; flag; n++) {
				temp = find_answer(i, j, n);
			
				if (is_prime(temp)) {
					counter_temp++;
				}
				else {
					flag = false;
				}
			}
			if (counter < counter_temp) {
				counter = counter_temp;
				result = i * j;
			}
		}
	}
	cout << result;
}
bool is_prime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i < n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}
int find_answer(const int& a, const int& b, const int& n) {
	return (n * n) + (n * a) + b;
}