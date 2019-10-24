#include <iostream>
using namespace std;
namespace {
	short* arr = new short[10], *temp = new short[10];
}
bool is_pandigital(int num, short*& arr);
bool compare(int num, short*& arr, short*& arr2, int x);
void has_digits(int num, short*& arr);
int main()
{
	bool flag = false, comparator;
	int result, index;

	for (int j = 11; !flag; j++) {
		if (is_pandigital(j, arr)) {
			comparator = true;
			for (index = 2; index < 7 && comparator; index++) {
				if (!compare(j, arr, temp, index)) {
					comparator = false;
				}
			}
			if (index == 7) {
				flag = true;
				result = j;
			}
		}
	}
	cout << result;
	delete[] arr;
	delete[] temp;
}

void has_digits(int num, short*& arr) {
	for (int i = 0; i < 10; i++) arr[i] = 0;
	while (num != 0) {
		arr[num % 10]++;
		num /= 10;
	}
}
bool is_pandigital(int num, short*& arr) {
	has_digits(num, arr);
	for (int i = 0; i < 10; i++) if (arr[i] > 1) return false;
	return true;
}
bool compare(int num, short*& arr, short*& arr2, int x) {
	num *= x;
	has_digits(num, arr2);
	for (int i = 0; i < 10; i++) if (arr[i] != arr2[i]) return false;
	return true;
}
