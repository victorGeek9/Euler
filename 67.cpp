#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
	int lines, amount = 0, start, end, priv;
	ifstream file;
	file.open("temp6.txt");
	cin >> lines;
	for (int i = 1; i <= lines; i++) {
		amount += i;
	}
	start = amount - lines;
	end = amount - 1;
	short* arr = new short[amount];
	for (int i = 0; i < amount; i++) {
		file >> arr[i];
	}
	for (int i = 1; i < lines; i++) {
		priv = start - (lines - i);
		for (int j = start; j < end; j++) {
			if (arr[j] >= arr[j + 1]) {
				arr[priv] += arr[j];
			}
			else {
				arr[priv] += arr[j + 1];
			}
			priv++;
		}
		start -= (lines - i);
		end = start + lines - i - 1;
	}
	cout << arr[0];
	delete[] arr;
	return 0;
}