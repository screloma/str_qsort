﻿#include "stdafx.h"
#include "iostream"
#include "cstdint"
#include "utility"
#include "handy.h"
#include "windows.h"
#include "string_.h"
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

void quickSort(std::vector<String>& arr, int left, int right) {
	int i = left, j = right;
	String pivot(arr[left+(right-left)/2]);
	while (left<j || i<right)
	{
		if (arr[i].lowercase() != pivot.lowercase()) {
			while (arr[i].lowercase() < pivot.lowercase())
				i++;
		}
		else {
			while (arr[i] < pivot)
				i++;
		}
		if (arr[j].lowercase() != pivot.lowercase()) {
			while (arr[j].lowercase() > pivot.lowercase())
				j--;
		}
		else {
			while (arr[j] > pivot)
				j--;
		}
		if (i <= j) {
			arr[i].swap(arr[j]);
			i++;
			j--;
		}
		else {
			if (left<j)
				quickSort(arr, left, j);
			if (i<right)
				quickSort(arr, i, right);
			return;
		}
	}
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}
int32_t main(){
	std::ifstream file("strings.txt");
	std::cout << (String("velen") < String("Velen")) << " " << (String("Velen") < String("velen"));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::vector<String> array;
	char* temp = new char[30];
	while (file >> temp) {
		array.emplace_back(temp);
	}
	if (array.size() > 0) {
		cout << "Исходный массив: \n";
		print_array(array, array.size());
		quickSort(array, 0, array.size() - 1);
		cout << "Отсортированный массив: \n";
		print_array(array, array.size());
	}
	else {
		std::cout << "Файл пустой.\n";
	}
	system("pause");
	file.close();
	return 0;
}

 
 