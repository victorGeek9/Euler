#include <iostream>
#include <vector>
using namespace std;
bool is_prime(int num);
int main()
{
	bool flag = true;
	int index = 0, temp, result = 0, amount = 21, temp_amount;
	vector<int> v;
	v.push_back(2);
	for (int j = 3; j < 1000000; j += 2) {
		if (is_prime(j)) {
			v.push_back(j);
			index++;
		}
	}
	for (int i = index; v[i] > 953; i--) {
		for (int j = 0; j < i - 1; j++) {
			temp = 0;
			temp_amount = 0;
			for (int k = j; temp < v[i]; k++) {
				temp += v[k];
				temp_amount++;
			}
			if (temp == v[i] && amount < temp_amount) {
				result = temp;
				amount = temp_amount;
			}
		}
	}
	cout << result << "  " << amount;
}
bool is_prime(int num) {
	if (num % 2 == 0) return false;
	int temp = 3;
	while (temp < num) {
		if (num % temp == 0) return false;
		temp += 2;
	}
	return true;
}
