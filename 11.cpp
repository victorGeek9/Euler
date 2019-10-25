#include <iostream>
#include <fstream>
using namespace std;
int diagonal_r(int** arr);
int diagonal_l(int** arr);
int vertical(int** arr);
int horizontal(int** arr);
int composition(int* arr);
int main()
{
	ifstream file;
	file.open("temp4.txt");
	int** arr = new int*[23];
	int* max = new int[4];
	for (int i = 0; i < 23; i++) {
		arr[i] = new int[23];
	}
	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 23; j++) {
			file >> arr[i][j];
		}
	}
	for (int i = 0; i < 23; i++) {
		cout << i + 1 << ") ";
		for (int j = 0; j < 23; j++) {
			cout << '\t' << arr[i][j] << " ";
		}
		cout << endl;
	}
	max[0] = horizontal(arr);
	max[1] = vertical(arr);
	max[2] = diagonal_r(arr);
	max[3] = diagonal_l(arr);
	for (int i = 0; i < 4; i++) {
		cout << max[i] << " ";
	}
		
	for (int i = 0; i < 23; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] max;
}
int horizontal(int** arr) {
	int max = 0, max_temp, index, a, b, c, d;
	int* temp = new int[4];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 4; j++) {
				temp[j] = arr[i][j];
		}
		index = 0;
		max_temp = composition(temp);
		if (max_temp > max) max = max_temp;
		for (int j = 4; j < 20; j++, index++) {
			if (index == 4) index = 0;
			temp[index] = arr[i][j];
			max_temp = composition(temp);
			if (max_temp > max) {
				max = max_temp;
				a = temp[0];
				b = temp[1];
				c = temp[2];
				d = temp[3];
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		temp[0] = arr[i][0];
		temp[1] = arr[i][1];
		temp[2] = arr[i][2];
		temp[3] = arr[i][19];
		max_temp = composition(temp);
		if (max_temp > max) {
			max = max_temp;
			a = temp[0];
			b = temp[1];
			c = temp[2];
			d = temp[3];
		}
	}
	for (int i = 0; i < 20; i++) {
		temp[0] = arr[i][0];
		temp[1] = arr[i][1];
		temp[2] = arr[i][18];
		temp[3] = arr[i][19];
		max_temp = composition(temp);
		if (max_temp > max) {
			max = max_temp;
			a = temp[0];
			b = temp[1];
			c = temp[2];
			d = temp[3];
		}
	}
	for (int i = 0; i < 20; i++) {
		temp[0] = arr[i][0];
		temp[1] = arr[i][17];
		temp[2] = arr[i][18];
		temp[3] = arr[i][19];
		max_temp = composition(temp);
		if (max_temp > max) {
			max = max_temp;
			a = temp[0];
			b = temp[1];
			c = temp[2];
			d = temp[3];
		}
	}
	cout << "horizontal: " << a << " " << b << " " << c << " " << d << " " << max << endl;
	delete[] temp;
	return max;
}
int vertical(int** arr) {
	int max = 0, *temp = new int[4], max_temp, index, a, b, c, d;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 4; j++) {
			temp[j] = arr[j][i];
		}
		max_temp = composition(temp);
		if (max_temp > max) max = max_temp;
		index = 0;
		for (int j = 4; j < 20; j++) {
			if (index == 4) index = 0;
			temp[index] = arr[j][i];
			max_temp = composition(temp);
			if (max_temp > max) {
				max = max_temp;
				a = temp[0];
				b = temp[1];
				c = temp[2];
				d = temp[3];
			}
			index++;
		}
	}
	for (int i = 0; i < 20; i++) {
		temp[0] = arr[0][i];
		temp[1] = arr[1][i];
		temp[2] = arr[2][i];
		temp[3] = arr[19][i];
		max_temp = composition(temp);
		if (max_temp > max) {
			max = max_temp;
			a = temp[0];
			b = temp[1];
			c = temp[2];
			d = temp[3];
		}
	}
	for (int i = 0; i < 20; i++) {
		temp[0] = arr[0][i];
		temp[1] = arr[1][i];
		temp[2] = arr[18][i];
		temp[3] = arr[19][i];
		max_temp = composition(temp);
		if (max_temp > max) {
			max = max_temp;
			a = temp[0];
			b = temp[1];
			c = temp[2];
			d = temp[3];
		}
	}
	for (int i = 0; i < 20; i++) {
		temp[0] = arr[0][i];
		temp[1] = arr[17][i];
		temp[2] = arr[18][i];
		temp[3] = arr[19][i];
		max_temp = composition(temp);
		if (max_temp > max) {
			max = max_temp;
			a = temp[0];
			b = temp[1];
			c = temp[2];
			d = temp[3];
		}
	}
	cout << "vertical: " << a << " " << b << " " << c << " " << d << endl;
	delete[] temp;
	return max;
}
int diagonal_r(int** arr) {
	int max = 0, *temp = new int[4], max_temp, a, b, c, d, line, row;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			temp[0] = arr[i][j];
			temp[1] = arr[i + 1][j + 1];
			temp[2] = arr[i + 2][j + 2];
			temp[3] = arr[i + 3][j + 3];
			max_temp = composition(temp);
			if (max_temp > max) {
				max = max_temp;
				a = temp[0];
				b = temp[1];
				c = temp[2];
				d = temp[3];
				line = i;
				row = j;
			}
		}		
	}
	cout << "diagonal right: " << a << " " << b << " " << c << " " << d << " " << line + 1 << " " << row + 1 << endl;
	delete[] temp;
	return max;
}
int diagonal_l(int** arr) {
	int max = 0, *temp = new int[4], max_temp, a, b, c, d, line, row;
	for (int i = 0; i < 20; i++) {
		for (int j = 22; j > 2; j--) {
			temp[0] = arr[i][j];
			temp[1] = arr[i + 1][j - 1];
			temp[2] = arr[i + 2][j - 2];
			temp[3] = arr[i + 3][j - 3];
			max_temp = composition(temp);
			if (max_temp > max) {
				a = temp[0];
				b = temp[1];
				c = temp[2];
				d = temp[3];
				line = i;
				row = j;
				max = max_temp;
			}
		}
	}
	
	cout << "diagonal left: " << a << " " << b << " " << c << " " << d << " " << line + 1 << " " << row + 1<< endl;
	delete[] temp;
	return max;
}
int composition(int* arr) { 
	int result = 1;
	for (int i = 0; i < 4; i++) {
		result *= arr[i];
	}
	return result;
}