#include <iostream>
#include <vector>
using namespace std;
int find_pentagonal(int num);
int main()
{
	bool flag = true;
	int sum, dif, a, b, result;
	vector<int> v;
	for (int i = 1; i <= 20000; i++) {
		v.push_back(find_pentagonal(i));
	}
	for (int i = 2; i < 20000 - 1 && flag; i++) {
		for (int j = i + 1; j < 20000 && flag; j++) {
			sum = v[i - 1] + v[j - 1];
			dif = v[j - 1] - v[i - 1];
			for (int k = j + 1; k <= 20000 && flag && sum >= v[k - 1]; k++) {
				if (sum == v[k - 1]) {
					for (int m = j - 1; m > 0 && flag && dif <= v[m - 1]; m--) {
						if (dif == v[m - 1]) {
							flag = false;
							a = v[i - 1];
							b = v[j - 1];
						}
					}
				}
			}
		}
	}
	cout << a << " " << b;
	result = b - a;
	cout << endl << result;
}
int find_pentagonal(int num) {
	return num * (3 * num - 1) / 2;
}