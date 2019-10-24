#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
int score(ifstream &file, string* s);
namespace {
	int number = 0;
	bool not_eof = true;
}
int main() {
	long long result = 0;
	string* s = new string[5170], min;
	int* arr = new int[5170], index, temp;
	for (int i = 0; i < 5170; i++) {
		arr[i] = 0;
		s[i] = "";
	}
	ifstream file;
	file.open("temp5.txt");
	for (int i = 0; not_eof && i < 5170; i++) {
		arr[i] = score(file, s);
	}
	for (int i = 0; i < 5169 && s[i+1] != ""; i++) {
		min = s[i];
		index = i;
		temp = arr[i];
		for (int j = i + 1; j < 5170 && s[j] != ""; j++) {
			if (min > s[j]) {
				min = s[j];
				index = j;
				temp = arr[j];
			}
		}
		s[index] = s[i];
		s[i] = min;
		arr[index] = arr[i];
		arr[i] = temp;
	}
	for (int i = 0; i < 5170 && arr[i] != 0; i++) {
		arr[i] *= (i + 1);
		cout << i + 1 << ") " << s[i] << "  " << arr[i] << endl;
		result += arr[i];
	}
	file.close();
	delete[] arr;
	cout << result;
}
int score(ifstream &file, string* s) {
	int result = 0, num;
	char temp;
	file >> temp;
	while (temp != ',' && temp != '@') {
		if (temp >= 65 && temp <= 90) {
			num = temp - 64;
			result += num;
			s[number] += temp;
		}
		file >> temp;
	}
	if (temp == '@') not_eof = false;
	number++;
	return result;
}
