#include <iostream>
#include <string>
using namespace std;
void first_day(int &day, int month, int year);
int main() {
	int day = 1, result = 0;
	for (int i = 1901; i <= 2000; i++) {
		for (int j = 1; j <= 12; j++) {
			if (day == 7) result++;
			first_day(day, j, i);
		}
	}
	cout << result;
}
void first_day(int &day, int month, int year) {
	int amount, temp = 8;
	switch (month) {
	case 1: amount = 31; break;
	case 2: amount = 28; break;
	case 3: amount = 31; break;
	case 4: amount = 30; break;
	case 5: amount = 31; break;
	case 6: amount = 30; break;
	case 7: amount = 31; break;
	case 8: amount = 31; break;
	case 9: amount = 30; break;
	case 10: amount = 31; break;
	case 11: amount = 30; break;
	case 12: amount = 31; break;
	default: amount = 0;
	}
	if (year % 400 == 0 && month == 2) amount++;
	while (temp + 7 < amount) {
		temp += 7;
	}
	while (temp <= amount) {
		temp++;
		day++;
		if (day == 8) day = 1;
	}
}