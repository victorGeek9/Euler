#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream file;
	char temp;
	int* arr = new int[13], index = 0;
	long long result = 1, result_temp = 1;
	file.open("temp23.txt");
	for (int i = 0; i < 13; i++) {
		file >> temp;
		arr[i] = temp - 48;
		result *= arr[i];
	}
	for (int i = 13; i < 1000; i++, index++, result_temp = 1) {
		if (index == 13) index = 0;
		file >> temp;
		arr[index] = temp - 48;
		for (int j = 0; j < 13; j++) {
			result_temp *= arr[j];
		}
		if (result_temp > result) result = result_temp;
	}
	cout << endl << result;
	delete[] arr;
}