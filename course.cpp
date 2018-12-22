#include "iostream"
#include <cstdint>
#include "utility"
#include <cstring>
#include <climits>
#include "string_.h"
#include <fstream>
#include <vector>
#include "handy.h"

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
		}
	};

	if (left < j)
		qs(arr, left, j, size);
	if (i < right)
		qs(arr, i, right, size);
}



int32_t main(){
	std::ifstream file("strings.txt");
	std::vector<String> array;
	String temp;
	String a("abc");
	for (auto& item : a.lowercase()) {
		std::cout << item;
	}
	while (file >> temp) {
		array.emplace_back(temp);
	}
	if (array.size() > 0) {
		cout << "Исходный массив: \n";
		print_array(array, array.size());
		qs(array, 0, array.size() - 1);
		cout << "Отсортированный массив: \n";
		print_array(array, array.size());
	}
	else {
		std::cout << "Файл пустой.\n";
	}
	return 0;
}

 
 
