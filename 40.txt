#include <iostream>
#include <string>
using namespace std;
int main()
{
	int result = 1, index;
	string s = "", temp;
	for (int i = 1; i <= 1000000; i++) {
		temp = "";
		index = -1;
		for (int j = i; j != 0; j /= 10, index++){
			temp += j % 10 + '0';
		}
		for (int j = i, k = index; j != 0; j /= 10, k--) {
			s += temp[k];
		}
	}
	for (int j = 1; j <= 1000000; j *= 10) {
		result *= s[j - 1] - '0';
	}
	cout << result;
}
