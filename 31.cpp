#include <iostream>
#include <fstream>
#include <vector>
int main()
{
	int value = 200, count = 0;
	for (int temp = 0, counter = value / 200; counter >= 0; counter--) {
		temp = value - counter * 200;
		for (int counter = temp / 100; counter >= 0; counter--) {
			temp -= counter * 100;
			for (int counter = temp / 50; counter >= 0; counter--) {
				temp -= counter * 50;
				for (int counter = temp / 20; counter >= 0; counter--) {
					temp -= counter * 20;
					for (int counter = temp / 10; counter >= 0; counter--) {
						temp -= counter * 10;
						for (int counter = temp / 5; counter >= 0; counter--) {
							temp -= counter * 5;
							for (int counter = temp / 2; counter >= 0; counter--) {
								count++;
							}
							temp += counter * 5;
						}
						temp += counter * 10;
					}
					temp += counter * 20;
				}
				temp += counter * 50;
			}
			temp += counter * 100;
		}
		temp += counter * 200;
	}
	std::cout << count;
}