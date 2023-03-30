#include <iostream>
#include<cstdlib>
#include<ctime>

template<typename T>
void resize_arr(T*& arr, T old_length, T new_length ) {
	if (old_length == new_length) return;
	int* tmp_arr = new int[new_length] {};
	if (new_length > old_length) {
		for (int i = 0; i < old_length; i++) 
			tmp_arr[i] = arr[i];
		delete[] arr;
		arr = tmp_arr;
	}
	else {
		for (int i = 0; i < new_length; i++)
			tmp_arr[i] = arr[i];
		delete[] arr;
		arr = tmp_arr;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << " Задача 1 \n";
	int size1 = 6; int size2 = 4;
	int* arrA = new int[size1];
	srand(time(NULL));
	std::cout << " Изначальный массив A :\n[";
	for (int i = 0; i < size1; i++) {
		arrA[i] = rand() % 15;
		std::cout << arrA[i] << ' ';
	}
	std::cout << "\b]\n";
	int* arrB = new int[size2];
	srand(time(NULL));
	std::cout << " Изначальный массив B :\n[";
	for (int i = 0; i < size2; i++) {
		arrB[i] = rand() % 11 - 5;
		std::cout << arrB[i] << ' ';
	}
	std::cout << "\b]\n";
	
	int* arrC = new int[size1 + size2];
	for (int i = 0; i < size1; i++) 
			arrC[i] = arrA[i];
	for (int i = size1; i < size1 + size2; i++) 
		arrC[i] = arrB[i-size1];
	std::cout << " Итоговый массив, массив С \n[";
	for (int i = 0; i < size1 + size2; i++)
		std::cout << arrC[i] << ' ';
	std::cout << "\b]\n";
	delete[] arrA;
	delete[] arrB;
	std::cout << "\n\n";

	std::cout << " Задача 2 \n";
	int n;
	std::cout << " ВВедите новую длину массива С : ";
	std::cin >> n;
	resize_arr(arrC, size1 + size2, n);

	std::cout << " Новый массив С\n[";
	for (int i = 0; i < n; i++)
		std::cout << arrC[i] << ' ';
	std::cout << "\b]\n";



	return 0;
}