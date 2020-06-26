#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <iostream>

template <typename T>
class RingBuffer
{
public:
	explicit RingBuffer(int isize);
	void push_back(T data);
	void pop_front();
	void insert(T data, int index);
	size_t count() { return size; }
	T* begin() { return &head->data; }
	T* end() { return &tail->data; }
	void quicksort(int l, int r);
	void mergesort(int l, int r);
	friend std::ostream& operator<< (std::ostream& msg, const RingBuffer<T> lst)
	{
		if (lst.size == 0) throw std::out_of_range("This ring buffer is empty");
		Element* temp = lst.head;
		int isize = lst.size;
		msg << "{";
		for (size_t i = 1; i < lst.size; i++)
		{
			msg << temp->data << ", ";
			temp = temp->nextptr;
			isize--;
		}
		msg << temp->data << " } ";
		return msg;
	}
	bool operator>(const RingBuffer<T>& b);
	bool operator<(const RingBuffer <T>& b);
	bool operator==(const RingBuffer<T>& b);
	bool operator!=(const RingBuffer<T>& b);
	bool operator<=(const RingBuffer<T>& b);
	bool operator>=(const RingBuffer<T>& b);
private:
	int sort(int l, int r);
	void merge(int l, int r); 
	class Element
	{
	public:
		T data{ 0 };
		Element* nextptr{ nullptr };
		Element(T data = T(), Element* nextptr = nullptr)
		{
			this->data = data;
			this->nextptr = nextptr;
		}
	};
	size_t maxsize;
	size_t size{ 0 };
	Element* head{ nullptr };
	Element* tail{ nullptr };
};

template<typename T>
RingBuffer<T>::RingBuffer(int isize)
{
	if (isize <= 0)
	{
		throw std::invalid_argument("size of ring buffer must be positive number");
	}
	maxsize = isize;
	head = new Element(0);
	Element* temp = head;
	for (size_t i = 1; i < maxsize; i++)
	{
		temp->nextptr = new Element(0);
		temp = temp->nextptr;
	}
	tail = head;
	temp->nextptr = head;
}

template<typename T>
void RingBuffer<T>::push_back(T data)
{
	if (size == 0)
	{
		tail->data = data;
	}
	else
	{
		if (tail->nextptr == head)
		{
			head = head->nextptr;
		}
		tail = tail->nextptr;
		tail->data = data;
	}
	if (size < maxsize) size++;
}

template<typename T>
void RingBuffer<T>::pop_front()
{
	if (head == nullptr)
	{
		throw std::out_of_range("This ring buffer is empty");
	}
	head = head->nextptr;
	size--;
}

template<typename T>
void RingBuffer<T>::insert(T data, int index)
{
	if ((index < 0) || (index >= size))
	{
		throw std::out_of_range("Out of range insert of ring buffer");
	}
	Element* temp = this->head;
	for (size_t i = 0; i < index; i++)
	{
		temp = temp->nextptr;
	}
	temp->data = data;
}

template<typename T>
void RingBuffer<T>::quicksort(int l, int r)
{
	if (l < r)
	{
		int pivot = sort(l, r);
		quicksort(l, pivot - 1);
		quicksort(pivot + 1, r);
	}
}
template<typename T>
void RingBuffer<T>::mergesort(int l, int r) {
	if (l < r) {
		mergesort(l, (l + r) / 2);
		mergesort((l + r) / 2 + 1, r);
		merge(l, r);
	}
}

template<typename T>
void RingBuffer<T>::merge(int l, int r)
{
	std::vector<T> result(this->count());
	int mid = (l + r) / 2;
	int start = l;
	int secondstart = mid + 1;
	int i = 0;
	Element* tempfirst = this->head;
	while (i < l)
	{
		tempfirst = tempfirst->nextptr;
		i++;
	}
	int j = i;
	Element* tempsecond = tempfirst;
	while (j < secondstart)
	{
		tempsecond = tempsecond->nextptr;
		j++;
	}

	while (i < r + 1)
	{
		if ((start <= mid) && ((secondstart > r) || tempfirst->data < tempsecond->data))
		{
			result[i] = tempfirst->data;
			start++;
			if (i != r)
				tempfirst = tempfirst->nextptr;
		}
		else {
			result[i] = tempsecond->data;
			secondstart++;
			if (i != r)
				tempsecond = tempsecond->nextptr;
		}
		i++;
	}
	int k = 0;
	Element* tmp = this->head;
	while (k < l) {
		tmp = tmp->nextptr;
		k++;
	}
	while (k < r + 1) {
		tmp->data = result[k];
		tmp = tmp->nextptr;
		k++;
	}
}

template<typename T>
bool RingBuffer<T>::operator>(const RingBuffer<T>& b)
{
	if (size == 0 && b.size == 0)
	{
		throw std::out_of_range("Lists are empty");
	}
	Element* tempa = head;
	Element* tempb = b.head;
	for (size_t i = 0; i < b.size; i++)
	{
		if (tempa->data < tempb->data) return false;

		if (tempa->data > tempb->data) return true;

		tempa = tempa->nextptr;
		tempb = tempb->nextptr;
	}		
	if (tempa->data < tempb->data) return false;
	if (tempa->data > tempb->data) return true;
	return (size > b.size);
}

template<typename T>
bool RingBuffer<T>::operator<(const RingBuffer<T>& b)
{
	return !(*this >= b);
}

template<typename T>
bool RingBuffer<T>::operator==(const RingBuffer<T>& b)
{
	if (size == 0 && b.size == 0)
	{
		throw std::out_of_range("Lists are empty");
	}
	if (size == b.size)
	{
		Element* tempa = head;
		Element* tempb = b.head;
		for (size_t i = 0; i < b.size; i++)
		{
			if (tempa->data != tempb->data) return false;
			tempa = tempa->nextptr;
			tempb = tempb->nextptr;
		}
		if (tempa->data != tempb->data) return false;
		return true;
	}
	else return false;
}

template<typename T>
bool RingBuffer<T>::operator!=(const RingBuffer<T>& b)
{
	return !(*this == b);
}

template<typename T>
bool RingBuffer<T>::operator<=(const RingBuffer<T>& b)
{
	return !(*this > b);
}

template<typename T>
bool RingBuffer<T>::operator>=(const RingBuffer<T>& b)
{
	return ((*this > b) || (*this == b));
}

template<typename T>
int RingBuffer<T>::sort(int l, int r)
{
	Element* temp = this->head;
	for (int i = 0; i < l; i++)
		temp = temp->nextptr;
	Element* pivot = temp;
	Element* copyPivot = temp;
	T pivotValue = temp->data;
	int wall = l;
	for (int i = l + 1; l < size - 1; l++)
	{
		temp = temp->nextptr;
		if (temp->data < pivotValue)
		{
			wall++;
			pivot = pivot->nextptr;
			T t = pivot->data;
			pivot->data = temp->data;
			temp->data = t;
		}
	}
	T t = pivot->data;
	pivot->data = copyPivot->data;
	copyPivot->data = t;
	return wall;

}

#endif // !RINGBUFFER_H