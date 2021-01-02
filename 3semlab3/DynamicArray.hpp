#pragma once
#include <stdexcept>

const auto IndexOutOfRange = "Invalid range of index!";
const auto NegativeSizeOfArray = "Array size is negative!";


template <class T>
class DynamicArray {
private:
	int size = 0;
	T* data = nullptr;
	bool check = true;
public:
	DynamicArray(const int size) {
		this->size = size;
		this->data = new T[size];
		this->check = false;
	}
	DynamicArray() {
	}
	DynamicArray(const T* data, const int size) {
		this->size = size;
		this->data = new T[size];
		this->check = false;
		for (int i = 0; i < size; ++i) this->data[i] = data[i];
	}
	DynamicArray(const DynamicArray<T>& dynamic_array) {
		if (!this->check) delete[] this->data;
		this->size = dynamic_array.size;
		this->data = new T[dynamic_array.size];
		this->check = false;
		for (int i = 0; i < dynamic_array.size; ++i) this->data[i] = dynamic_array.data[i];

	}
	DynamicArray<T>& operator = (const DynamicArray<T>& dynamic_array) {
		T* new_data = new T[dynamic_array.GetSize()];
		for (int i = 0; i < dynamic_array.size; ++i) new_data[i] = dynamic_array.data[i];
		delete[] this->data;
		this->size = dynamic_array.size;
		this->data = new_data;
		this->check = false;
		return (*this);

	}
	T Get(const int index) const {
		if (index < 0 || index >= this->size) throw std::out_of_range(IndexOutOfRange);
		return this->data[index];
	}
	int GetSize() const {
		return this->size;
	}
	void Set(const int index, const T value) {
		if (index < 0 || index >= this->size) throw std::out_of_range(IndexOutOfRange);
		this->data[index] = value;
	}
	T& operator [] (const int index) const {
		if (index < 0 || index >= this->size) throw std::out_of_range(IndexOutOfRange);
		return this->data[index];
	}
	void Delete_(const int index) {
		if (index < 0 || index >= this->size) throw std::out_of_range(IndexOutOfRange);
		const int new_size = this->size - 1;
		T* data_ = new T[new_size];
		int index_ = 0;
		for (int i = 0; i < this->size; ++i) {
			if (i != index) {
				data_[i - index_] = this->data[i];
			}
			else {
				index_ = 1;
			}
		}
		delete[] this->data;
		this->data = data_;
		delete[] data_;
		this->size = new_size;
	}
	/*void Resize(const int new_size) {
		if (new_size < 0) throw std::length_error(NegativeSizeOfArray);
		int const min_size = new_size < this->size ? new_size : this->size;
		T* new_data = new T[new_size];
		this->size = new_size;
		for (int i = 0; i < min_size; ++i) new_data[i] = this->data[i];
		delete[] this->data;
		this->data = new_data;
		delete[] new_data;
	}*/
	void Resize(int newSize) {
		T* tmp = new T[newSize];
		if (newSize > this->size) {
			for (int i = 0; i < this->size; i++) {
				tmp[i] = this->data[i];
			}
			this->size = newSize;
		}
		else {
			for (int i = 0; i < newSize; i++) {
				tmp[i] = this->data[i];
			}
			this->size = newSize;
		}
		delete[] this->data;
		this->data = tmp;
	}

	~DynamicArray() {
		this->size = 0;
		delete[] this->data;
		this->check = true;
	}
};