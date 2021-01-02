#pragma once
#include "Sequence.hpp"
#include "DynamicArray.hpp"


template <class T>
class ArraySequence : public Sequence<T>
{
private:
	DynamicArray<T> dynamic_array = DynamicArray<T>(0);
public:
	ArraySequence(const int count) : Sequence<T>()
	{
		if (count == 0) throw std::length_error(NegativeSizeOfArray);
		this->dynamic_array = DynamicArray<T>(count);
	}
	ArraySequence() : Sequence<T>()
	{
		this->dynamic_array = DynamicArray<T>();
	}
	ArraySequence(const T* items, const int count) : Sequence<T>()
	{
		if (count == 0)
			throw std::length_error(NegativeSizeOfArray);
		this->dynamic_array = DynamicArray<T>(items, count);
	}
	ArraySequence(const ArraySequence<T>& other) : Sequence<T>()
	{
		const int newsize = other.GetSize();
		this->dynamic_array = DynamicArray<T>(newsize);
		for (int i = 0; i < newsize; i++) this->dynamic_array[i] = (*other)[i];
	}
public:
	int GetSize() const override
	{
		return this->dynamic_array.GetSize();
	}
	T GetFirst() const override
	{
		return this->dynamic_array.Get(0);
	}
	T GetLast() const override
	{
		const int size = this->dynamic_array.GetSize();
		return  this->dynamic_array.Get(size - 1);
	}
	T Get(const int i) const override
	{
		if (i < 0 || i >= this->dynamic_array.GetSize())
			throw std::out_of_range(IndexOutOfRange);
		return  this->dynamic_array.Get(i);
	}
	Sequence<T>* GetSubList(const int start, const int end) const override
	{
		if (start > this->dynamic_array.GetSize() || end > this->dynamic_array.GetSize() || start < 0 || end < 0)
			throw std::out_of_range(IndexOutOfRange);
		int SubSize = end - start + 1;
		ArraySequence<T>* SubSequence = new ArraySequence<T>(SubSize);
		int j = 0;
		for (int i = start; i <= end; i++) { SubSequence->dynamic_array[j] = this->dynamic_array[i]; j++; }
		return SubSequence;
	}
public:
	void Append(const T value) override {
		const int old_size = this->dynamic_array.GetSize();
		this->dynamic_array.Resize(old_size + 1);
		this->dynamic_array[old_size] = value;
	}
	void Prepend(const T value) override {
		const int size = this->dynamic_array.GetSize();
		DynamicArray<T> dynamic_array_c(this->dynamic_array);
		this->dynamic_array.Resize(size + 1);
		for (int i = 0; i < size; ++i) this->dynamic_array[i + 1] = dynamic_array_c[i];
		this->dynamic_array[0] = value;
	}
	/*void InsertAt(const T value, const int index) override
	{
		//if (this->dynamic_array.GetSize() == 0)
		//	throw std::length_error(ZeroSize);
		int count = 0;
		const int presize = this->dynamic_array.GetSize();
		const int newsize = presize + 1;
		if (index < 0 || index > presize)
			throw std::out_of_range(IndexOutOfRange);
		DynamicArray<T> dynamic_array_copy(this->dynamic_array);
		this->dynamic_array.Resize(newsize);
		for (int i = 0; i < newsize; i++)
		{
			if (i != index) {
				this->dynamic_array[i] = dynamic_array_copy[i - count];
			}
			else {
				this->dynamic_array[i] = value;
				count = 1;
			}
		}
	}*/
	void InsertAt(T item, int index) override {
		this->dynamic_array.Resize(this->dynamic_array.GetSize() + 1);
		for (int i = this->dynamic_array.GetSize() - 1; i > index; i--) {
			this->dynamic_array.Set(i, this->dynamic_array.Get(i - 1));
		}
		this->dynamic_array.Set(index, item);
	}
	void Set(int index, T item) override {
		this->dynamic_array.Set(index, item);
	}
	/*ArraySequence<T>* operator = (const Sequence<T>* sequence) override {
		const int new_size = sequence->GetSize();
		this->dynamic_array = DynamicArray<T>(new_size);
		for (int i = 0; i < new_size; ++i) this->dynamic_array[i] = (*sequence)[i];
		return  this;
	}*/
	T& operator [] (const int index) const override {
		return this->dynamic_array[index];
	}
	Sequence<T>* Concat(const Sequence<T>* other) override
	{
		const int sumsize = this->GetSize() + other->GetSize();
		ArraySequence<T>* concat_array = new ArraySequence<T>(sumsize);
		for (int i = 0; i < this->GetSize(); i++) concat_array->dynamic_array[i] = this->dynamic_array[i];
		for (int i = this->GetSize(); i < sumsize; i++) concat_array->dynamic_array[i] = (*other)[i - this->GetSize()];
		return  concat_array;
	}
	void Delete_(const int index) override {
		this->dynamic_array.Delete_(index);
	}
	~ArraySequence() override = default;
};