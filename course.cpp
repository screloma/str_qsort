﻿#include "stdafx.h"
#include "iostream"
#include "cstdint"
#include "utility"
#include "handy.h"
#include "windows.h"
#include <cctype>
#include "string_.h"
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

void qs(std::vector<String>& arr, int left, int right, int size=0) {
	int i = left, j = right;
	String mid = arr[(left + right) / 2];
	
	while (i<=j) {
		while (i<=j && arr[i] < mid) {
			std::cout << arr[i] << " < " << mid << std::endl;
			i++;
		}
		while (i <=j && arr[j] > mid) {
			std::cout << arr[j] << " > " << mid << std::endl;
			j--;
		}
		if (i <= j) {
			arr[i].swap(arr[j]);
			i++; j--;
			/*for (auto& item : arr) {
				std::cout << item << " ";
			}
			std::cout << std::endl;*/
		}
	};

	if (left < j)
		qs(arr, left, j, size);
	if (i < right)
		qs(arr, i, right, size);
}




int32_t main(){
	std::ifstream file("strings.txt");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::vector<String> array;
	String temp;
	while (file >> temp) {
		array.emplace_back(temp);
	}
	if (array.size() > 0) {
		cout << "Исходный массив: \n";
		print_array(array, array.size());
		qs(array, 0, array.size()-1, array.size());
		cout << "Отсортированный массив: \n";
		print_array(array, array.size());
	}
	else {
		std::cout << "Файл пустой.\n";
	}
	system("pause");
	return 0;
}

 
 