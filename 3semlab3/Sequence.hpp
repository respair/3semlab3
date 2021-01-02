#pragma once
template <class T>
class Sequence
{
public:
	const int size = 0;
public:
	virtual int GetSize() const = 0;
	virtual T GetFirst() const = 0;
	virtual T GetLast() const = 0;
	virtual T Get(const int i) const = 0;
	virtual Sequence<T>* GetSubList(const int start, const int end) const = 0;
	//virtual Sequence<T>* GetSubsequence(const int start, const int end) const = 0;
public:
	virtual void Append(T value) = 0;
	virtual void Prepend(T value) = 0;
	virtual void InsertAt(const T value, const int index) = 0;
	virtual Sequence<T>* Concat(const Sequence<T>* other) = 0;

	virtual void Delete_(const int index) = 0;
	virtual void Set(int index, T item) = 0;

	virtual T& operator [] (const int index) const = 0;
public:
	virtual ~Sequence() = default;
};