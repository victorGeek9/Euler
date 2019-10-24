#include <iostream>

using namespace std;

int main()
{
	int amount = 8, temp, i;
	for (i = 20; amount != 10001; i++) {
		for (temp = 2; temp < i; temp++) {
			if (i % temp == 0) break;
		}
		if (temp == i) amount++;
	}
	cout << --i;
}