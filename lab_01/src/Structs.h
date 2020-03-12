#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <iostream>
using namespace std;

class Abs // base class
{
public:
	Abs() //default constructor
	{
		size = 0;
		arr = new short[size];
	}
	explicit Abs(short isize); // param constructor
	~Abs();

	void Out();
	void Fill();
	void Push(short value);
	virtual void Pop();
	virtual short Peek();

	size_t Count();
	void Negative();
	void Range(short left, short right);

	bool operator<(const Abs& b); // comparison functions
	bool operator>(const Abs& b);
	bool operator==(const Abs& b);
	bool operator!=(const Abs& b);
	bool operator<=(const Abs& b);
	bool operator>=(const Abs& b);

protected:
	size_t size {0}; // array size
	short* arr {nullptr}; // array
};

Abs::Abs(short isize) 
{
	if (isize < 0)
	{
		throw invalid_argument("Invalid size of structure");
	}
	else
	{
		size = isize;
		arr = new short[size];
	}
}

Abs::~Abs() //destructor
{
	delete[] arr;
}

void Abs::Fill()
{
	
	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
		//arr[i] = rand() % 10;
	}
}

void Abs::Out()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Abs::Push(short value)
{
	auto* newArray = new short[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size] = value;
	size++;
	delete[] arr;
	arr = newArray;
}

void Abs::Pop()
{
	if (size <= 0)
	{
		throw out_of_range("Out of range Pop()");
	}
	else
	{
		size--;
		auto* newArray = new short[size];
		for (size_t i = 0; i < size; i++)
		{
			newArray[i] = arr[i];
		}
		delete[] arr;
		arr = newArray;
	}
}

short Abs::Peek()
{
	if (size > 0)
	{
		return arr[size -1];
	}
	else
	{
		throw out_of_range("Out of range Peek()");
	}
}

size_t Abs::Count()
{
	return size;
}

void Abs::Negative() // erase negative nums
{
	int NegativeCount = 0;
	int k = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			NegativeCount++;
		}
	}
	size -= NegativeCount;
	auto* newArray = new short[size];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i + k] < 0)
		{
			k++;
			i--;
		}
		else
			newArray[i] = arr[i + k];
	}
	delete[] arr;
	arr = newArray;
}

void Abs::Range(short left, short right) // erase nums in defined range
{
	int RangeCount = 0;
	int k = 0;
	for (size_t i = 0; i < size; i++)
	{
		if ((arr[i] >= left) && (arr[i] <= right))
		{
			RangeCount++;
		}
	}
	size -= RangeCount;
	auto* newArray = new short[size];
	for (size_t i = 0; i < size; i++)
	{
		if ((arr[i + k] >= left) && (arr[i + k] <= right))
		{
			k++;
			i--;
		}
		else
			newArray[i] = arr[i + k];
		
	}
	delete[] arr;
	arr = newArray;
}


bool Abs::operator<(const Abs& b)
{
	if (size > b.size)
	{
		size_t it = 0;

		do
		{
			if (arr[it] < b.arr[it]) return true;

			else if (arr[it] > b.arr[it]) return false;

			it++;

		} while ((it < b.size) && (arr[it] == b.arr[it]));
	}
	else if (size <= b.size)
	{
		size_t it = 0;
		do
		{
			if (arr[it] < b.arr[it]) return true;

			if (arr[it] > b.arr[it]) return false;

			it++;

		} while ((it < b.size) && (arr[it] == b.arr[it]));
		if (size < b.size) return true;
	}
	return false;
}

bool Abs::operator>(const Abs& b)
{
	if (size >= b.size)
	{
		size_t it = 0;

		do
		{
			if (arr[it] < b.arr[it]) return false;

			else if (arr[it] > b.arr[it]) return true;

			it++;

		} while ((it < b.size) && (arr[it] == b.arr[it]));
		if (size > b.size) return true;
	}
	else if (size < b.size)
	{
		size_t it = 0;
		do
		{
			if (arr[it] < b.arr[it]) return false;

			else if (arr[it] > b.arr[it]) return true;

			it++;

		} while ((it < size) && (arr[it] == b.arr[it]));
	}
	return false;
}
bool Abs::operator==(const Abs& b)
{
	if (size == b.size)
	{
		size_t it = 0;
		do
		{
			if (arr[it] != b.arr[it]) return false;
			it++;

		} while ((it < size) && (arr[it] == b.arr[it]));
		return true;
	}
	else return false;
}

bool Abs::operator!=(const Abs& b)
{
	return !(*this == b);
}

bool Abs::operator<=(const Abs& b)
{
	return !(*this > b);
}

bool Abs::operator>=(const Abs& b)
{
	return !(*this < b);
}

class Stack : public Abs
{
public:
	Stack() = default;
	~Stack() = default;
	explicit Stack(short isize) : Abs(isize)
	{}
};

class Queue : public Abs
{
public:
	Queue() = default;
	~Queue() = default;
	explicit Queue(short isize) : Abs(isize)
	{}
	void Pop() override
	{
		if (size <= 0)
		{
			throw out_of_range("Out of range Pop()");
		}
		else
		{
			size--;
			auto* newArray = new short[size];
			for (size_t i = 0; i < size; i++)
			{
				newArray[i] = arr[i + 1];
			}
			delete[] arr;
			arr = newArray;
		}
	}
		
	short Peek() override
	{
		if (size > 0)
		{
			return arr[0];
		}
		else
		{
			throw out_of_range("Out of range Peek()");
		}
	}
};

class Vector : public Abs
{
public:
	Vector() = default;
	~Vector() = default;
	explicit Vector(short isize) : Abs(isize)
	{}
	short & At(size_t value);
	
};

short & Vector::At(size_t value)
{
	if ((value < 0) && (value >= size))
	{
		throw out_of_range("Out of range At()");
	}
	else
	{
		return arr[value];
	}
}
#endif // !STRUCTS_H_ 