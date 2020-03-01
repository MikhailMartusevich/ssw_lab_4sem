#include <iostream>
using namespace std;

class Abs // base class
{
public:
	Abs(short isize);
	~Abs();
	void Out();
	void Fill();
	short Peek();
	short Count();
	void Negative();
	void Range(short left, short right);
	friend bool operator< (const Abs& a, const Abs& b); // friend functions
	friend bool operator> (const Abs& a, const Abs& b);
	friend bool operator== (const Abs& a, const Abs& b);
	friend bool operator!= (const Abs& a, const Abs& b);
protected:
	short size = 0; // array size
	short* arr; // array
};

Abs::Abs(short isize) // base class constructor 
{
	size = isize;
	arr = new short[size];
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
	int z = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			NegativeCount++;
		}
	}
	size -= NegativeCount;
	short* newArray = new short[size];
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
	short* newArray = new short[size];
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

bool operator<(const Abs& a, const Abs& b)
{
	bool res = false;
	if (a.size <= b.size)
	{
		for (int i = 0; i < a.size; i++)
		{
			if (a.arr[i] > b.arr[i]) res = false;
			else res = true;
		}
	}
	else
	{
		for (int i = 0; i < b.size; i++)
		{
			if (a.arr[i] > b.arr[i]) res = false;
			else res = true;
		}
	}
	return res;
}
bool operator> (const Abs& a, const Abs& b)
{
	bool res = false;
	if (a.size <= b.size)
	{
		for (int i = 0; i < a.size; i++)
		{
			if (a.arr[i] > b.arr[i]) res = true;
			else res = false;
		}
	}
	else
	{
		for (int i = 0; i < b.size; i++)
		{
			if (a.arr[i] > b.arr[i]) res = true;
			else res = false;
		}
	}
	return res;
}
bool operator== (const Abs& a, const Abs& b)
{
	bool res = false;
	if (a.size <= b.size)
	{
		for (int i = 0; i < a.size; i++)
		{
			if (a.arr[i] == b.arr[i]) res = true;
			else res = false;
		}
	}
	else
	{
		for (int i = 0; i < b.size; i++)
		{
			if (a.arr[i] == b.arr[i]) res = true;
			else res = false;
		}
	}
	return res;
}
bool operator!= (const Abs& a, const Abs& b)
{
	bool res = false;
	if (a.size <= b.size)
	{
		for (int i = 0; i < a.size; i++)
		{
			if (a.arr[i] == b.arr[i]) res = false;
			else res = true;
		}
	}
	else
	{
		for (int i = 0; i < b.size; i++)
		{
			if (a.arr[i] == b.arr[i]) res = false;
			else res = true;
		}
	}
	return res;
}

class Stack : public Abs
{
public:
	Stack(short isize) : Abs(isize)
	{}
	void StackPop();
	void StackPush(short value);
};
void Stack::StackPush(short value)
{
	short* newArray = new short[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size] = value;
	size++;
	delete[] arr;
	arr = newArray;
}
void Stack::StackPop()
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

class Queue : public Abs
{
public:
	Queue(short isize) : Abs(isize)
	{}
	void QueuePush(short value);
	void QueuePop();
	short QueuePeek();
};
void Queue::QueuePush(short value)
{
	short* newArray = new short[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size] = value;
	size++;
	delete[] arr;
	arr = newArray;
}
void Queue::QueuePop()
{
	size--;
	short* newArray = new short[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i + 1];
	}
	delete[] arr;
	arr = newArray;
}
short Queue::QueuePeek()
{
	return arr[0];
}
class Vector : public Abs
{
public:
	Vector(short isize) : Abs(isize)
	{}
	void VectorPush(short value);
	void VectorPop();
	short & VectorAt(short value);
	
};
void Vector::VectorPush(short value)
{
	short* newArray = new short[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size] = value;
	size++;
	delete[] arr;
	arr = newArray;
}
void Vector::VectorPop()
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
short & Vector::VectorAt(short value)
{
	return arr[value];
}
 