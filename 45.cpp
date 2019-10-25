#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
long long pentagonal(int num);
long long triangle(int num);
long long hexagonal(int num);
int main()
{
	long long result = 0, triang, pentag = 0, hexag = 0;
	int index1 = 166, index2 = 144;
	for (int i = 286; !result; i++) {
		triang = triangle(i);
		for (int j = index1 - 1; pentag < triang; j++, index1++) {
			pentag = pentagonal(j);
		}
		if (pentag == triang) {
			for (int j = index2 - 1; hexag < triang; j++, index2++) {
				hexag = hexagonal(j);
			}
			if (hexag == triang) result = hexag;
		}
	}
	cout << result;
}
long long triangle(int num) {
	long long result;
	result = num * (num + 1LL) / 2LL;
	return result;
}
long long pentagonal(int num) {
	long long result;
	result = num * (3LL * num - 1LL) / 2LL;
	return result;
}
long long hexagonal(int num) {
	long long result;
	result = num * (2LL * num - 1LL);
	return result;
}