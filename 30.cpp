#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
namespace {
	int result = 0;
}
int powers(short num);
int main() {
	int index = 10, *pow = new int[10];
	long long num = 1, sum = 0;
	short* arr = new short[11];
	for (int i = 0; i < 11; i++) arr[i] = 0;
	for (int i = 0; i < 10; i++) pow[i] = powers(i);
	while (arr[0] == 0) {
		arr[10]++;
		index = 10;
		for (; arr[index] > 9 && index > 0; index--) {
				sum -= pow[9];
				arr[index] = 0;
				arr[index - 1]++;
		}
		sum -= pow[arr[index] - 1];
		sum += pow[arr[index]];
		
		if (num == sum) {
			result += sum;
		}
		//cout << num << "  " << sum << endl;
		num++;
	}
	cout << result - 1;// without 1
	delete[] arr;
	delete[] pow;
}
int powers(short num) {
	switch (num) {
	case 0:return 0; break;
	case 1:return 1; break;
	case 2:return 32; break;
	case 3:return 243; break;
	case 4:return 1024; break;
	case 5:return 3125; break;
	case 6:return 7776; break;
	case 7:return 16807; break;
	case 8:return 32768; break;
	case 9:return 59049; break;
	}
}
