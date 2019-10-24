#include <iostream>
#include <vector>
using namespace std;
int main()
{
	bool flag, the_end;
	int count = 0;
	vector<long long> result;
	short* arr = new short[9];
	long long a, b, comp, sum = 0;
	for (a = 1; a <= 9876; a++) {
		for (int b = 1; b <= 9876; b++) {
			the_end = false;
			comp = a * b;
			for (int j = 0; j < 9; j++) {
				arr[j] = 0;
			}
			for (int i = a, k = a % 10; i != 0 && !the_end; i /= 10, k = i % 10) {
				for (int j = 0; j < 9; j++) {
					if (k == j + 1) arr[j]++;
				}
				if (k == 0) the_end = true;
			}
			for (int i = b, k = b % 10; i != 0 && !the_end; i /= 10, k = i % 10) {
				for (int j = 0; j < 9; j++) {
					if (k == j + 1) arr[j]++;
				}
				if (k == 0) the_end = true;
			}
			for (int i = comp, k = comp % 10; i != 0 && !the_end; i /= 10, k = i % 10) {
				for (int j = 0; j < 9; j++) {
					if (k == j + 1) arr[j]++;
				}
				if (k == 0) the_end = true;
			}
			flag = true;
			for (int j = 0; j < 9 && !the_end; j++) {
				if (arr[j] != 1) {
					flag = false;
				}
			}
			if (flag && !the_end) {
				for (int j = 0; j < count; j++) {
					if (comp == result[j]) flag = false;
				}
				if (flag && !the_end) {
					count++;
					result.push_back(comp);
					sum += comp;
					cout << a << " * " << b << " = " << comp << endl;
				}
			}
		}
	}
	cout << sum << endl << endl;
	delete[] arr;
}
