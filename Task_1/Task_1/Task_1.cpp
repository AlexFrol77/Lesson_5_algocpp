#include <iostream>
#include <vector>
#include <Windows.h>

void print_vec(std::vector <int> &vec) {
	std::cout << "Исходный массив: ";
	for (int i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int log_vec(int size_vec) {
	int
		count = 0,
		temp = size_vec;
	do {
		temp /= 2;
		count++;
	} while (temp != 0);
	return count - 1;
}

void print_piramid(std::vector <int> &vec) {
	int temp = vec.size();
	std::cout << "Пирамида:" << std::endl;
	for (int i = 0; i != vec.size(); i++) {
		if (i != 0) {
			std::cout << log_vec(i + 1) << " " << (i % 2 == 1 ? "left" : "right")
				<< " (" << vec[(i - 1) / 2] << ") " << vec[i] << std::endl;
			temp--;
		}
		else {
			std::cout << log_vec(i) << " " << "root" << " " << vec[i] << std::endl;
			temp--;
		}
	}
}

int main (int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector <int> vec { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	
	print_vec(vec);
	print_piramid(vec);

	return 0;
}