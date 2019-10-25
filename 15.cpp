#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int grid = 20;
	long long** arr = new long long* [grid];
	for (int i = 0; i < grid; i++) {
		arr[i] = new long long[grid];
	}
	arr[0][0] = 2;
	for (int i = 1; i < grid; i++) {
		arr[0][i] = arr[0][i - 1] + 1;
		arr[i][0] = arr[i - 1][0] + 1;
	}
	for (int i = 1; i < grid; i++) {
		for (int j = 1; j < grid; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	cout << arr[grid - 1][grid - 1];
	for (int i = 0; i < grid; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}