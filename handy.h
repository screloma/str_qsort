template <typename t>
void print_array(t array, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template <typename t>
void print_matrix(t** array, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

template <typename t>
void input_square_matrix(t* array, const size_t size) {
	t item;
	for (size_t i = 0; i < size; i++) {
		array[i] = new int[size];
		for (size_t j = 0; j < size; j++) {
			array[i][j] = validate_input(array[i][j]);
		}
	}
}

template <class t>
t* copyArray(t* input, size_t size) {
	t* output = new t[size];
	for (size_t i = 0; i < size; i++) {
		output[i] = input[i];
	}
	return output;
}

template <class t>
t validate_input(const t* variable) {
	t result = *variable;
	delete variable;
	std::cin >> result;
	while (std::cin.fail()) {
		std::cout << "Ошибка, повторите ввод. \n";
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> result;
	}
	return result;
}