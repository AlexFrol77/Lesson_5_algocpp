#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

void print_vec(std::vector <int>& vec) {
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

void print_heap(std::vector <int> &vec) {
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

void go_request(int &req) {	
	std::string temp_request;
	int temp = req;
	std::cout << "Введите команду: ";
	std::cin >> temp_request;
	if (temp_request == "up") {
		if (req != 0) {
			req = ((req - 1) / 2);
		}
		else {
			std::cout << "Ошибка! Отсутствует родитель!" << std::endl;
			go_request(req);
		}
	}
	if (temp_request == "left") { req = (2 * temp + 1); }
	if (temp_request == "right") { req = (2 * temp + 2); }
	if (temp_request == "exit") { req = - 1; }
}

void print_request(std::vector <int> &vec, int &req) {
	if ((req != 0)  && (req % 2 == 1)) {
		if (req <= (vec.size() - 1)) {
			std::cout << "ok" << std::endl;
			std::cout << "Вы находитесь здесь: ";
			std::cout << log_vec(req + 1) << " " << "left" << " (" << vec[(req - 1) / 2] << ") " << vec[req] << std::endl;
		}
		else {
			std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
			std::cout << "Вы находитесь здесь: ";
			req = ((req - 1) / 2);
			std::cout << log_vec(req + 1) << " " << ((req % 2 == 0) ? "right" : "left") << " (" << vec[(req - 1) / 2] << ") " << vec[req] << std::endl;
		}
	}
	if ((req != 0) && (req % 2 == 0)) {
		if (req <= (vec.size() - 1)) {
			std::cout << "ok" << std::endl;
			std::cout << "Вы находитесь здесь: ";
			std::cout << log_vec(req + 1) << " " << "right" << " (" << vec[(req - 1) / 2] << ") " << vec[req] << std::endl;
		} 
		else {
			std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
			std::cout << "Вы находитесь здесь: ";
			req = ((req - 1) / 2);
			std::cout << log_vec(req + 1) << " " << ((req % 2 == 1) ? "left" : "right") << " (" << vec[(req - 1) / 2] << ") " << vec[req] << std::endl;
		}
	}
	if (req == 0) {
		std::cout << "ok" << std::endl;
		std::cout << "Вы находитесь здесь: ";
		std::cout << log_vec(req) << " " << "root" << " " << vec[req] << std::endl;
	}
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int temp_request = 0;
	bool flag = false;

	std::vector <int> vec{ 1, 3, 6, 5, 9, 8 };

	print_vec(vec);
	print_heap(vec);

	print_request(vec, temp_request);
	do {		
		go_request(temp_request);
		print_request(vec, temp_request);
	} while (temp_request != -1);

	return 0;
}