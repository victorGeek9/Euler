#include <iostream>
#include <fstream>
using namespace std;
short* sum(short* a, short* b, int a_size, int b_size);
void read_number(short* ptr, ifstream& file);
int main()
{
	int index, result = 0;
	ifstream file;
	file.open("temp3.txt");
	short* a = new short[50], *b = new short[50];
	read_number(a, file);
	read_number(b, file);
	a = sum(a, b, 50, 50);
	for (int i = 3; i <= 100; i++) {
		read_number(b, file);
		a = sum(a, b, 100, 50);
	}
	for (index = 0; a[index] == 0; index++) {}
	for (int i = 0; i < 10; i++, index++) {
		cout << a[index];
	}
}
void read_number(short* ptr, ifstream& file) {
	char temp;
	for (int i = 0; i < 50; i++) {
		file >> temp;
		ptr[i] = temp - 48;
	}
}
short* sum(short* a, short* b, int a_size, int b_size) {
	int index;
	short* result = new short[100];
	for (int i = 0; i < 100; i++) result[i] = 0;
	a_size--;
	b_size--;
	for (index = 99; b_size >= 0; a_size--, b_size--, index--) {
		result[index] += a[a_size] + b[b_size];
		if (result[index] > 9) {
			result[index - 1] += result[index] / 10;
			result[index] %= 10;
		}
	}
	for (; a_size >= 0; index--, a_size--) {
		result[index] += a[a_size];
		if (result[index] > 9) {
			result[index - 1] += result[index] / 10;
			result[index] %= 10;
		}
	}
	
	return result;
}
