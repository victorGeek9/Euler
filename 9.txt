#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int a = 1, b = 2, c = 997, temp, left = a*a + b*b, right = c * c;
	for (int i = 1; left != right && a < b; i++, c--) {
		temp = c;
		a = i;
		for (int j = i + 1; left != right && b < c; j++, c--) {
			b = j;
			left = a * a + b * b;
			right = c * c;
		}
		c = --temp;
	}
	c = 1000 - a - b;
	cout << a << " " << b << " " << c << "    " << left << " = " << right << endl;
	cout << a * b * c;
}