
class String {
private:
	char* data_;
	int32_t size_=0;
public:
	String()
		:data_(new char[1])
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
		strcpy_s(data_, strlen(str) + 1, str);
	}

	String(char* str)
		: data_(new char[strlen(str) + 1]),
		size_(strlen(str))
	{
		strcpy_s(data_, strlen(str) + 1, str);
	}

	String(const String& rhs)
		:data_(new char[strlen(rhs.data_)+1]),
		size_(rhs.size())
	{
		//std::copy(rhs.data_, rhs.data_+rhs.size(), data_);
		strcpy_s(data_, strlen(rhs.data_) + 1, rhs.data_);
	}

	String(const String&& rhs)
		:data_(new char[strlen(rhs.data_) + 1]),
		size_(rhs.size())
	{
		strcpy_s(data_, strlen(rhs.data_) + 1, rhs.data_);
	}

	inline const int32_t size() const {
		return size_;
	}

	void swap(String& rhs)
	{
		std::swap(data_, rhs.data_);
		std::swap(size_, rhs.size_);
	}


	String lowercase() {
		String result(data_);
		for (size_t i = 0; i < size_; i++) {
			result.data_[i] = result.data_[i] | 32;
		}
		return result;
	}

	char* get() {
		return data_;
	}

	String& operator=(String& rhs) {
		if (this == &rhs) {
			return *this;
		}
		else {
			memcpy(data_, rhs.data_, rhs.size_);
			size_ = rhs.size_;
			return *this;
		}
	}

	String& operator=(String&& rhs) {
		if (this == &rhs) {
			return *this;
		}
		else {
			memcpy(data_, rhs.data_, rhs.size_);
			size_ = rhs.size_;
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
		rhs.size_ = strlen(rhs.data_);
		return is;
	}

	friend String& operator+(String& lhs, String& rhs) {
		String* temp = new String(lhs);
		memcpy(temp->data_ + temp->size_, rhs.data_, rhs.size_);
		temp->size_ += rhs.size_;
		return *temp;
	}

	/*
	LVALUE OPERATORS
	*/
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
			else if (lhs_data[i] < rhs_data[i]) {
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

	inline friend bool operator!=(String& lhs, String& rhs) {
		return !(lhs == rhs);
	}

	inline friend bool operator<=(String& lhs, String& rhs) {
		return (lhs < rhs || lhs == rhs);
	}

	inline friend bool operator>=(String& lhs, String& rhs) {
		return(lhs > rhs || lhs == rhs);
	}

	/*
	RVALUE OPERATORS
	*/

	friend std::ostream& operator<<(std::ostream &os, String&& rhs) {
		for (int32_t i = 0; i < rhs.size(); i++) {
			os << rhs.data_[i];
		}
		return os;
	}

	friend bool operator>(String&& lhs, String&& rhs) {
		char* lhs_data = lhs.get();
		char* rhs_data = rhs.get();
		size_t lhs_size = lhs.size();
		size_t rhs_size = rhs.size();
		int size = (lhs_size > rhs_size) ? rhs_size : lhs_size;
		for (int32_t i = 0; i < size; i++) {
			if (lhs_data[i] > rhs_data[i]) {
				return true;
			}
			else if (lhs_data[i] < rhs_data[i]) {
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

	inline friend bool operator<(String&& lhs, String&& rhs) {
		return (rhs > lhs);
	}

	inline friend bool operator==(String&& lhs, String&& rhs) {
		return !(lhs > rhs || lhs < rhs);
	}

	inline friend bool operator!=(String&& lhs, String&& rhs) {
		return !(lhs == rhs);
	}

	inline friend bool operator<=(String&& lhs, String&& rhs) {
		return (lhs < rhs || lhs == rhs);
	}

	inline friend bool operator>=(String&& lhs, String&& rhs) {
		return(lhs > rhs || lhs == rhs);
	}
};
