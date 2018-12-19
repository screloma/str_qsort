
class String {
	private:
		int32_t size_;
		char* data_;
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
			:size_(strlen(str)),
			data_(new char[strlen(str) + 1])
		{
			strcpy_s(data_, strlen(str) + 1, str);
		}

		String(const String& rhs)
			:data_(new char[strlen(rhs.data_)+1]),
			size_(rhs.size())
		{
			strcpy_s(data_, strlen(rhs.data_) + 1, rhs.data_);
		}


		String(String&& rhs) {
			data_ = rhs.data_;
			size_ = rhs.size_;
			rhs.data_ = nullptr;
		}

		inline const int32_t size() const {
			return size_;
		}

		void swap(String& rhs)
		{
			std::swap(data_, rhs.data_);
			std::swap(size_, rhs.size_);
		}


		String lowercase()const {
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
				data_ = new char[strlen(rhs.data_) + 1];
				memcpy(data_, rhs.data_, rhs.size_);
				size_ = rhs.size_;
				return *this;
			}
		}

		String& operator=(const char* rhs) {
			if (data_ == rhs) {
				return *this;
			}
			else {
				data_ = new char[strlen(rhs) + 1];
				memcpy(data_, rhs, strlen(rhs));
				size_ = strlen(rhs);
				return *this;
			}
		}

		String& operator=(String&& rhs) {
			if (this == &rhs) {
				return *this;
			}
			else {
				data_ = new char[strlen(rhs.data_) + 1];
				memcpy(data_, rhs.data_, rhs.size_);
				size_ = rhs.size_;
				return *this;
			}
		}

		const char operator[](size_t idx)const {
			return data_[idx];
		}

		friend std::ostream& operator<<(std::ostream &os, String& rhs) {
			for (int32_t i = 0; i < rhs.size(); i++) {
				os << rhs.data_[i];
			}
			return os;
		}

		friend std::ostream& operator<<(std::ostream &os, String&& rhs) {
			for (int32_t i = 0; i < rhs.size(); i++) {
				os << rhs.data_[i];
			}
			return os;
		}

		friend std::istream& operator>>(std::istream &is, String& rhs) {
			char temp[100];
			is >> temp;
			if (strlen(temp) > strlen(rhs.data_)) {
				rhs.data_ = new char[strlen(temp) + 1];
				rhs.size_ = strlen(temp);
			}
			else {
				rhs.size_ = strlen(temp);
			}
			memcpy(rhs.data_, temp, rhs.size_ + 1);
			return is;
		}

		friend std::istream& operator>>(std::istream &is, String&& rhs) {
			char temp[100];
			is >> temp;
			if (strlen(temp) > strlen(rhs.data_)) {
				rhs.data_ = new char[strlen(temp) + 1];
				rhs.size_ = strlen(temp);
			}
			else {
				rhs.size_ = strlen(temp);
			}
			memcpy(rhs.data_, temp, rhs.size_ + 1);
			return is;
		}

		friend String operator+(String& lhs, const String& rhs) {
			String temp(lhs);
			temp.data_ = new char[rhs.size_ + lhs.size_ + 1];
			memcpy(temp.data_, rhs.data_, rhs.size_);
			memcpy(temp.data_ + temp.size_, rhs.data_, rhs.size_);
			temp.size_ += rhs.size_;
			return temp;
		}

		friend String operator+(String& lhs, const String&& rhs) {
			String temp(lhs);
			temp.data_ = new char[rhs.size_ + lhs.size_ + 1];
			memcpy(temp.data_, rhs.data_, rhs.size_);
			memcpy(temp.data_ + temp.size_, rhs.data_, rhs.size_);
			temp.size_ += rhs.size_;
			return temp;
		}

		friend String operator+(String&& lhs, const String& rhs) {
			String temp(lhs);
			temp.data_ = new char[rhs.size_ + lhs.size_ + 1];
			memcpy(temp.data_, rhs.data_, rhs.size_);
			memcpy(temp.data_ + temp.size_, rhs.data_, rhs.size_);
			temp.size_ += rhs.size_;
			return temp;
		}

		friend String operator+(String&& lhs, const String&& rhs) {
			String temp(lhs);
			temp.data_ = new char[rhs.size_ + lhs.size_ + 1];
			memcpy(temp.data_, rhs.data_, rhs.size_);
			memcpy(temp.data_ + temp.size_, rhs.data_, rhs.size_);
			temp.size_ += rhs.size_;
			return temp;
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

		inline friend bool operator<(String& lhs, String& rhs) {
			return (rhs > lhs);
		}

		inline friend bool operator<(String&& lhs, String&& rhs) {
			return (rhs > lhs);
		}

		inline friend bool operator==(String& lhs, String& rhs) {
			return !(lhs > rhs || lhs < rhs);
		}

		inline friend bool operator==(String&& lhs, String&& rhs) {
			return !(lhs > rhs || lhs < rhs);
		}

		inline friend bool operator!=(String& lhs, String& rhs) {
			return !(lhs == rhs);
		}

		inline friend bool operator!=(String&& lhs, String&& rhs) {
			return !(lhs == rhs);
		}

		inline friend bool operator<=(String& lhs, String& rhs) {
			return (lhs < rhs || lhs == rhs);
		}

		inline friend bool operator<=(String&& lhs, String&& rhs) {
			return (lhs < rhs || lhs == rhs);
		}

		inline friend bool operator>=(String& lhs, String& rhs) {
			return(lhs > rhs || lhs == rhs);
		}

		inline friend bool operator>=(String&& lhs, String&& rhs) {
			return(lhs > rhs || lhs == rhs);
		}
};
