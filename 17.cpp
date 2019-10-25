#include <iostream>
#include <string>
using namespace std;
void check(int i, int& amount);
/*
1-12
20 30 40 ... 90
100 ... 900 1000
21-29 ... 91-99
101 - 199 ... 901 999

*/
int main() {
	string s;
	int amount = 0;
	for (int i = 1; i <= 1000; i++) {
		if (i < 13) {//1-12
			check(i, amount);
		}
		else {
			if (i >= 13 && i <= 19) {//13-19
				check(i % 10, amount);
				amount += 4;
				if (i % 10 == 3 || i % 10 == 5 || i % 10 == 8) amount--;
			}
			else {
				if (i % 10 == 0) {//20 30 .. 90
					if (i % 100 == 0) {// 100 200 .. 900
						if (i % 1000 == 0) {//1000
							check(i / 1000, amount);
							amount += 8;
						}
						else {
							check(i / 100, amount);
							amount += 7;
						}
						
					}
					else {//110
						if (i / 100 != 0) {//20 30 .. 90
							amount += 10;
							check(i / 100, amount);
							if (i % 100 == 10) {
								check(i % 100, amount);
							}
							else {
								check(i % 100 / 10, amount);
								amount += 2;
								if (i % 100 / 10 == 3 || i % 100 / 10 == 4 || i % 100 / 10 == 5 || i % 100 / 10 == 8) amount--;
								if (i % 100 / 10 == 2) amount++;
							}
						}
						else {
							check(i / 10, amount);
							amount += 2;
							if (i / 10 == 3 || i / 10 == 4 || i / 10 == 5 || i / 10 == 8) amount--;
							if (i / 10 == 2) amount++;
						}
						
					}	
				}
				else {
					if (i / 100 == 0) {// 21-29 .. 91-99
						check(i % 10, amount);
						check(i / 10, amount);
						amount += 2;
						if (i / 10 == 3 || i / 10 == 4 || i / 10 == 5 || i / 10 == 8) amount--;
						if (i / 10 == 2) amount++;
					}
					else {//101-199 .. 901-999
						amount += 10;
						check(i / 100, amount);
						if (i % 100 < 13) {//101-112 .. 901-912
							check(i % 100, amount);
						}
						else {//113-119
							if (i % 100 >= 13 && i % 100 < 20) {//101-112 .. 901-912
								check(i % 10, amount);
								amount += 4;
								if (i % 10 == 3 || i % 10 == 5 || i % 10 == 8) amount--;
							}
							else {
								// .. 991-999
								check(i % 100 % 10, amount);
								check(i % 100 / 10, amount);
								amount += 2;
								if (i % 100 / 10 == 3 || i % 100 / 10 == 4 || i % 100 / 10 == 5 || i % 100 / 10 == 8) amount--;
								if (i % 100 / 10 == 2) amount++;
							}
						}
					}
				}
			}	
		}
	}
	cout << amount;
}

void check(int i, int& amount) {
	switch (i) {
		case 1: amount += 3; break;
		case 2: amount += 3; break;
		case 3: amount += 5; break;
		case 4: amount += 4; break;
		case 5: amount += 4; break;
		case 6: amount += 3; break;
		case 7: amount += 5; break;
		case 8: amount += 5; break;
		case 9: amount += 4; break;
		case 10: amount += 3; break;
		case 11: amount += 6; break;
		case 12: amount += 6; break;
	}
}