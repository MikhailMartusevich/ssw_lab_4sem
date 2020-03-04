#ifndef STRUCTS
#define STRUCTS

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

	short Count();
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
	short* arr; // array
};

Abs::Abs(short isize) 
{
	try
	{
		size = isize;
		arr = new short[size];
	}
	catch (const std::exception& exp)
	{
		cout << exp.what();
	}
}

Abs::~Abs() //destructor
{
	delete[] arr;
}

void Abs::Fill()
{
	
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
		//arr[i] = rand() % 10;
	}
}

void Abs::Out()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Abs::Push(short value)
{
	auto* newArray = new short[size + 1];
	for (int i = 0; i < size; i++)
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
	try
	{
		size--;
		short* newArray = new short[size];
		for (int i = 0; i < size; i++)
		{
			newArray[i] = arr[i];
		}
		delete[] arr;
		arr = newArray;
	}
	catch (const std::exception & exp)
	{
		cout << exp.what();
	}
}

short Abs::Peek()
{
	return arr[size - 1];
}

short Abs::Count()
{
	return size;
}

void Abs::Negative() // erase negative nums
{
	int NegativeCount = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			NegativeCount++;
		}
	}
	size -= NegativeCount;
	auto* newArray = new short[size];
	for (int i = 0; i < size; i++)
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
	for (int i = 0; i < size; i++)
	{
		if ((arr[i] >= left) & (arr[i] <= right))
		{
			RangeCount++;
		}
	}
	size -= RangeCount;
	auto* newArray = new short[size];
	for (int i = 0; i < size; i++)
	{
		if ((arr[i + k] >= left) & (arr[i + k] <= right))
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
		for (int i = 0; i < b.size; i++)
			return arr < b.arr;
	else
		for (int i = 0; i < size; i++)
			return arr < b.arr;
}

bool Abs::operator>(const Abs& b)
{
	if (size > b.size)
		for (int i = 0; i < b.size; i++)
			return arr > b.arr;
	else
		for (int i = 0; i < size; i++)
			return arr > b.arr;
}

bool Abs::operator==(const Abs& b)
{
	if (size != b.size)
		return false;
	else
		for (int i = 0; i < size; i++)
			return arr[i] == b.arr[i];
}

bool Abs::operator!=(const Abs& b)
{
	if (size != b.size)
		return true;
	else
		for (int i = 0; i < size; i++)
			return arr[i] != b.arr[i];
}

bool Abs::operator<=(const Abs& b)
{
	if (size > b.size)
		for (int i = 0; i < b.size; i++)
			return arr <= b.arr;
	else
		for (int i = 0; i < size; i++)
			return arr <= b.arr;
}

bool Abs::operator>=(const Abs& b)
{
	if (size > b.size)
		for (int i = 0; i < b.size; i++)
			return arr >= b.arr;
	else
		for (int i = 0; i < size; i++)
			return arr >= b.arr;
}

class Stack : public Abs
{
public:
	Stack() : Abs()
	{}
	explicit Stack(short isize) : Abs(isize)
	{}
};

class Queue : public Abs
{
public:
	Queue() : Abs()
	{}
	explicit Queue(short isize) : Abs(isize)
	{}
	void Pop() override
	{
		size--;
		auto* newArray = new short[size];
		for (int i = 0; i < size; i++)
		{
			newArray[i] = arr[i + 1];
		}
		delete[] arr;
		arr = newArray;
	}
	short Peek() override
	{
		return arr[0];
	}
};

class Vector : public Abs
{
public:
	Vector() : Abs()
	{}
	explicit Vector(short isize) : Abs(isize)
	{}
	short & At(short value);
	
};

short & Vector::At(short value)
{
	return arr[value];
}
#endif // !STRUCTS 