﻿#include "stdafx.h"
#include "iostream"
#include "cstdint"
#include "utility"
#include "handy.h"
#include "windows.h"


using std::cin;
using std::cout;
using std::endl;

class String {
	private:
		char* data_;
		int32_t size_;
	public:
		String()
			:data_(new char[1]),
			size_(0)
			{
				*data_ = '\0';
			};

		~String() {
			delete[] data_;
		}

		String(const char* str)
			: data_(new char[strlen(str) + 1]),
			size_(strlen(str))
			{
				strcpy_s(data_, strlen(str)+1, str);
			}

		String(String& rhs)
			:data_(new char[rhs.size()+1]),
			size_(rhs.size())
			{
				memcpy(data_, rhs.data_, size_);
			}

		inline int32_t size() {
			return size_;
		}

		void swap(String& rhs)
		{
			std::swap(data_, rhs.data_);
			std::swap(size_, rhs.size_);
		}

		String& operator=(String& rhs) {
			if (this == &rhs) {
				return *this;
			}
			else {
				swap(rhs);
				return *this;
			}
		}

		const char operator[](size_t idx) {
			return data_[idx];
		}

		friend std::ostream& operator<<(std::ostream &os, String& rhs) {
			for (int32_t i = 0; i < rhs.size(); i++) {
				os << rhs.data_[i];
			}
			return os;
		}

		friend std::istream& operator>>(std::istream &is, String& rhs) {
			is >> rhs.data_;
			rhs.size_ = strlen(rhs.data_)+1;
			rhs.data_[rhs.size_] = '\0';
			return is;
		}

		friend String& operator+(String& lhs, String& rhs) {
			String* temp = new String(lhs);
			memcpy(temp->data_ + temp->size_, rhs.data_, rhs.size_);
			temp->size_ += rhs.size_;
			return *temp;
		}

		friend bool operator>(String& lhs, String& rhs) {
			char* lhs_data = lhs.get();
			char* rhs_data = rhs.get();
			size_t lhs_size = lhs.size();
			size_t rhs_size = rhs.size();
			int size = (lhs_size > rhs_size) ? rhs_size : lhs_size;
			for (int32_t i = 0; i < size; i++) {
				if (lhs_data[i] > rhs_data[i]) {
					return true;
				}
				else if(lhs_data[i] < rhs_data[i]) {
					return false;
				}
			}
			if (lhs_size == rhs_size) {
				return false;
			}
			else {
				return (lhs_size > rhs_size) ? true : false;
			}
		}

		inline friend bool operator<(String& lhs, String& rhs) {
			return (rhs > lhs);
		}

		inline friend bool operator==(String& lhs, String& rhs) {
			return !(lhs > rhs || lhs < rhs);
		}

		inline friend bool operator<=(String& lhs, String& rhs) {
			return (lhs < rhs || lhs == rhs);
		}

		inline friend bool operator>=(String& lhs, String& rhs) {
			return(lhs > rhs || lhs == rhs);
		}

		inline char* get() {
			return data_;
		}
};


template <typename t>
int split(t* arr, size_t left, size_t right) {
	int pivot = left;
	for (int i = left + 1; i < right; i++) {
		if (arr[i] < arr[pivot]) {
			if (pivot + 1 != i) {
				arr[pivot].swap(arr[pivot+1]);
			}
			arr[pivot].swap(arr[i]);
			pivot++;
		}
	}
	return pivot;
}

template <typename t>
t* quicksort(t* input, size_t left, size_t right) {
	if (right - left < 2) {
		return input;
	}
	else {
		int pivot = split(input, left, right);
		quicksort(input, left, pivot);
		quicksort(input, pivot + 1, right);
	}
	return input;
}

void quickSort(String* arr, int left, int right) {
	int i = left, j = right;
	String pivot(arr[(left+right)/2]);
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			arr[i].swap(arr[j]);
			i++;
			j--;
		}
	};
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}
int32_t main(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	String a1("a");
	String a2("bc");
	String a3 = a1 + a2;
	int32_t size = 4;
	cout << "Введите размер массива: ";
	size = validate_input(new int32_t);
	String* array = new String[size]{"fractal", "godspeed", "twec", "eleven"};
	for (size_t i = 0; i < size; i++) {
		cout << "Введите строку " << i + 1 << " из " << size << ": ";
		cin >> array[i];
	}
	cout << "Исходный массив: \n";
	print_array(array, size);
	quickSort(array, 0, size-1);
	cout << "Отсортированный массив: \n";
	print_array(array, size);
	system("pause");
	return 0;
}

 
 