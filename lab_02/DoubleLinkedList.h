#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

template <typename T>
class DLList
{
public:
	DLList() = default;
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	void insert(T data, int index);
	void erase(int index);
	void quicksort(int l, int r);
	void mergesort(int l, int r);
	T* begin() { return &head->data; }
	T* end() { return &tail->data; }
	size_t count() { return size; };
	T& operator[](const int index);
	friend std::ostream& operator<< (std::ostream& msg, const DLList<T> lst)
	{
		if (lst.head == nullptr) throw std::out_of_range("This DLlist is empty");
		Element* temp = lst.head;
		msg << "{ ";
		while (temp->nextptr != nullptr)
		{
			msg << temp->data << ", ";
			temp = temp->nextptr;
		}
		msg << temp->data << " }";
		return msg;
	}
	bool operator>(const DLList<T>& b);
	bool operator<(const DLList<T>& b);
	bool operator==(const DLList<T>& b);
	bool operator!=(const DLList<T>& b);
	bool operator<=(const DLList<T>& b);
	bool operator>=(const DLList<T>& b);
private:
	int sort(int l, int r);
	void merge(int l, int r);
	class Element
	{
	public:
		T data{ 0 };
		Element* nextptr{ nullptr };
		Element* prevptr{ nullptr };
		Element(T data = T(), Element* nextptr = nullptr, Element* prevptr = nullptr)
		{
			this->data = data;
			this->prevptr = prevptr;
			this->nextptr = nextptr;
		}
	};
	size_t size{ 0 };
	Element* head{ nullptr };
	Element* tail{ nullptr };
};

template <typename T>
T& DLList<T>::operator[](const int index)
{
	size_t tempcount = { 0 };
	Element* temp = this->head;
	while (temp != nullptr)
	{
		if (tempcount == index)
		{
			return temp->data;
		}
		temp = temp->nextptr;
		tempcount++;
	}
}
template <typename T>
void DLList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Element(data, head, tail);
		tail = head;
	}
	else
	{
		Element* temp = tail;
		tail = new Element(data, nullptr, temp);
		temp->nextptr = tail;
	}
	size++;
}
template <typename T>
void DLList<T>::push_front(T data)
{
	if (head == nullptr)
	{
		head = new Element(data);
		tail = head;
	}
	else
	{
		Element* temp = head;
		head = new Element(data, temp);
		temp->prevptr = head;
	}
	size++;
}
template <typename T>
void DLList<T>::pop_front()
{
	if (size == 0) throw std::out_of_range("This DLList is empty (pop_front)");
	Element* temp = head;
	head = temp->nextptr;
	delete temp;
	size--;
}
template <typename T>
void DLList<T>::pop_back()
{
	if (size == 0) throw std::out_of_range("This DLList is empty (pop_back)");
	if (size == 1)
	{
		pop_front();
	}
	else
	{
		Element* temp = tail;
		tail = tail->prevptr;
		tail->nextptr = nullptr;
		delete temp;
		size--;
	}
}
template <typename T>
void DLList<T>::insert(T data, int index)
{
	if ((index < 0) || (index > size))
	{
		throw std::out_of_range("index is out of range");
	}
	if (index == 0) push_front(data);
	if (index == size) push_back(data);
	if ((index != 0) && (index != size))
	{
		if (index <= size / 2)
		{
			Element* tempprev = this->head;
			for (size_t i = 0; i < index - 1; i++)
				tempprev = tempprev->nextptr;
			Element* x = new Element(data, tempprev->nextptr, tempprev);
			tempprev->nextptr = x;
			Element* tempnext = x->nextptr;
			tempnext->prevptr = x;
			size++;
		}
		if (index > size / 2)
		{
			Element* tempnext = this->tail;
			for (size_t i = size - 1; index < i; i--)
				tempnext = tempnext->prevptr;
			Element* x = new Element(data, tempnext, tempnext->prevptr);
			tempnext->prevptr = x;
			Element* tempprev = x->prevptr;
			tempprev->nextptr = x;
			size++;
		}
	}
}
template <typename T>
void DLList<T>::erase(int index)
{
	if ((index < 0) || (index >= size))
	{
		throw std::out_of_range("index is out of range");
	}
	if (index == 0) pop_front();
	if (index == size - 1) pop_back();
	if ((index != 0) && (index != size))
	{
		if (index <= size / 2)
		{
			Element* tempprev = this->head;
			for (size_t i = 0; i < index - 1; i++)
				tempprev = tempprev->nextptr;
			Element* tempdelete = tempprev->nextptr;
			tempprev->nextptr = tempdelete->nextptr;
			Element* tempnext = tempdelete->nextptr;
			delete tempdelete;
			tempprev->nextptr = tempnext;
		}
		if (index > size / 2)
		{
			Element* tempnext = this->tail;
			for (int i = size - 1; index + 1 < i; i--)
				tempnext = tempnext->prevptr;
			Element* tempdelete = tempnext->prevptr;
			tempnext->prevptr = tempdelete->prevptr;
			Element* tempprev = tempdelete->prevptr;
			delete tempdelete;
			tempprev->nextptr = tempnext;
		}
		size--;
	}
}
template<typename T>
bool DLList<T>::operator>(const DLList<T>& b)
{
	if (size == 0 && b.size == 0)
	{
		throw std::out_of_range("Lists are empty");
	}
	Element* tempa = head;
	Element* tempb = b.head;
	while ((tempa->nextptr != nullptr) && (tempb->nextptr != nullptr))
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
bool DLList<T>::operator<(const DLList<T>& b)
{
	return !(*this >= b);
}
template<typename T>
bool DLList<T>::operator==(const DLList<T>& b)
{
	if (size == 0 && b.size == 0)
	{
		throw std::out_of_range("Lists are empty");
	}
	if (size == b.size)
	{
		Element* tempa = head;
		Element* tempb = b.head;
		while ((tempa->nextptr != nullptr) && (tempb->nextptr != nullptr))
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
bool DLList<T>::operator!=(const DLList<T>& b)
{
	return !(*this == b);
}

template<typename T>
bool DLList<T>::operator<=(const DLList<T>& b)
{
	return !(*this > b);
}

template<typename T>
bool DLList<T>::operator>=(const DLList<T>& b)
{
	return ((*this > b) || (*this == b));
}

template <typename T>
int DLList<T>::sort(int l, int r)
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

template<typename T>
void DLList<T>::quicksort(int l, int r) {
	if (l < r)
	{
		int pivot = sort(l, r);
		quicksort(l, pivot - 1);
		quicksort(pivot + 1, r);
	}
}
template<typename T>
void DLList<T>::mergesort(int l, int r) {
	if (l < r) {
		mergesort(l, (l + r) / 2);
		mergesort((l + r) / 2 + 1, r);
		merge(l, r);
	}
}

template<typename T>
void DLList<T>::merge(int l, int r)
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
#endif // !DOUBLE_LINKED_LIST_H
