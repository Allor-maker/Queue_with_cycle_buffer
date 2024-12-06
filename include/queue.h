#include <iostream>

template <class T>

class Queue
{
	T* data = nullptr;
	T* first = nullptr;
	T* last = nullptr;
	int sz = 0;
	int capacity;
public:
	Queue(int size):capacity(2*size)
	{
		data = new T[size * 2];
		for (int i = 0; i < capacity; i++) data[i] = 0;
		first = &data[0];
		last = &data[0];
	}
	Queue(const Queue& Q):sz(Q.sz),capacity(Q.capacity)
	{
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = Q.data[i];
		first = data + (Q.first - Q.data);
		last = data + (Q.last - Q.data);
	}
	Queue& operator=(const Queue& Q)
	{
		if (*this == Q) return *this;
		if (capacity != Q.capacity)
		{
			capacity = Q.capacity;
			delete[] data;
			data = new T[capacity];
		}
		for (int i = 0; i < capacity; i++) data[i] = Q.data[i];
		sz = Q.sz;
		first = data + (Q.first - Q.data);
		last = data + (Q.last - Q.data);
		return *this;
	}
	T get_first() const
	{
		return *first;
	}
	T get_last() const
	{
		return *last;
	}
	void push(const T& elem)
	{
		sz++;
		if (sz > capacity)
			resize();
		else
		{
			if (last == &data[capacity - 1] || (last == &data[0] && sz==1))
				last = &data[0];
			else
				last++;
			*last = elem;
		}
	}
	void resize()
	{
		T* arr = new T[2 * capacity];
		for (int i = 0; i < 2*capacity; i++) arr[i] = 0;
		int i = 0;
		for (T* curr = first; curr <= &data[capacity - 1]; curr++)
		{
			arr[i] = *curr;
			i++;
		}
		for (T* curr = last; curr < first; curr++)
		{
			arr[i] = *curr;
			i++;
		}
		delete[] data;
		data = arr;
		first = &data[0];
		last = &data[capacity - 1];
		capacity = 2 * capacity;
	}
	void pop()
	{
		if (sz == 0)throw 0;
		sz--;
		*first = 0;
		if (first == &data[capacity - 1])
			first = &data[0];
		else
			first++;
	}
	void print() const
	{
		for (int i = 0; i < capacity; i++)
		{
			std::cout << "arr[" << i << "]=" << data[i] << " " << std::endl;
		}
		std::cout << std::endl;
	}
	bool empty() const
	{
		return (sz == 0);
	}
	bool full() const
	{
		return (sz == capacity);
	}
	int get_capacity() const
	{
		return capacity;
	}
	bool operator==(const Queue& other) const
	{
		if (capacity != other.capacity || sz != other.sz) return false;
		if (last == data + (other.last - other.data)) return true;
		if (first != data + (other.first - other.data)) return false;

		for (int i = 0; i < capacity; i++)
		{
			if (data[i] != other.data[i])
				return false;
		}
		return true;
	}
	void clear()
	{
		first = &data[0];
		last = &data[0];
		sz = 0;
		for (int i = 0; i < capacity; i++) data[i] = 0;
	}
	size_t size() const
	{
		return sz;
	}
};