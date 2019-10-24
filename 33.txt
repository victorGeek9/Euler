#include <iostream>
#include <cmath>
using namespace std;
int main() {
	bool flag;
	double a, b;
	int* numerator = new int[2], * denumerator = new int[2], result_num = 1, result_denum = 1;
	for (int i = 12; i < 100; i++) {
		if (i % 10 != 0) {
			denumerator[0] = i % 10;
			denumerator[1] = i / 10;
			for (int j = i - 1; j > 10; j--) {
				a = (double)j / i;
				numerator[0] = j % 10;
				numerator[1] = j / 10;
				flag = true;
				for (int k = 0; k < 2 && flag; k++) {
					for (int m = 0; m < 2 && flag; m++) {
						if (numerator[k] == denumerator[m]) {
							if (k == 0) {
								if (m == 0) {
									b = (double)numerator[1] / denumerator[1];
									if (a == b) flag = false;
								}
								else {
									b = (double)numerator[1] / denumerator[0];
									if (a == b) flag = false;
								}
							}
							else {
								if (m == 0) {
									b = (double)numerator[0] / denumerator[1];
									if (a == b) flag = false;
								}
								else {
									b = (double)numerator[0] / denumerator[0];
									if (a == b) flag = false;
								}
							}
						}
					}
				}
				if (!flag) {
					cout << j << " / " << i << endl;
					result_num *= i;
					result_denum *= j;
				}
			}
		}
	}
	cout << result_num << " / " << result_denum << endl << (double)result_num / result_denum;
	delete[] numerator;
	delete[] denumerator;
}