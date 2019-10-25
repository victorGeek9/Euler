#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
namespace {
	bool the_end_of_file = false;
}
bool is_triangle(int num);
void find_number(ifstream& file, int& number);
int main()
{
	int number, counter = 0;;
	ifstream file;
	file.open("temp7.txt");
	while (!the_end_of_file) {
		find_number(file, number);
		if (is_triangle(number)) counter++;
	}
	cout << counter;
}
void find_number(ifstream& file, int& number) {
	char temp;
	int index;
	number = 0;
	do {
		file >> temp;
	} while (temp != '"');
	do {
		file >> temp;
		number += temp - 64;
	} while (temp != '"');
	number += 30;
	if (!(file >> temp)) {
		the_end_of_file = true;
	}
}
bool is_triangle(int num) {
	double result;
	long long temp;
	num *= 2;
	temp = 1 + 4 * num;
	result = (sqrt(temp) - 1) / 2;
	temp = result;
	if (result - temp != 0) return false;
	return true;
}
