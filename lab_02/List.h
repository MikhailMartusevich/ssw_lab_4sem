#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <vector>

template <typename T>
class List
{
public:
	List() = default;
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	void insert(T data, int index);
	void erase(int index);
	void quicksort(int l, int r);
	void mergesort(int l, int r);


	T* begin() { return &head->data; }
	T* end();
	size_t count() { return size; }
	T& operator[](const int index);
	friend std::ostream& operator<< (std::ostream& msg, const List<T> lst)
	{
		if (lst.head == nullptr) throw std::out_of_range("This list is empty");
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
	bool operator>(const List<T>& b);
	bool operator<(const List<T>& b);
	bool operator==(const List<T>& b);
	bool operator!=(const List<T>& b);
	bool operator<=(const List<T>& b);
	bool operator>=(const List<T>& b);

private:
	int sort(int l, int r);
	void merge(int l, int r);
	class Element
	{
	public:
		Element* nextptr{ nullptr };
		T data{ 0 };
		Element(T data = T(), Element* nextptr = nullptr)
		{
			this->data = data;
			this->nextptr = nextptr;
		}
	};
	size_t size{ 0 };
	Element* head{ nullptr };
};
template <typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Element(data);
	}
	else
	{
		Element* temp = this->head;
		while (temp->nextptr != nullptr)
		{
			temp = temp->nextptr;
		}
		temp->nextptr = new Element(data);
	}
	size++;
}
template <typename T>
void List<T>::push_front(T data)
{
	if (head == nullptr)
	{
		head = new Element<T>(data);
	}
	else
	{
		Element* temp = this->head;
		head = new Element<T>(data, temp);
	}
	size++;
}
template <typename T>
void List<T>::pop_back()
{
	if (size > 0)
	{
		erase(size - 1);
	}
	else
	{
		throw std::out_of_range("Out of range pop_back");
	}
}
template <typename T>
void List<T>::pop_front()
{
	if (size > 0)
	{
		Element* temp = this->head;
		head = head->nextptr;
		delete temp;
		size--;
	}
	else
	{
		throw std::out_of_range("Out of range pop_front");
	}
}

template<typename T>
void List<T>::erase(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("index is out of range");
	}
	if (index == 0) pop_front();
	else
	{
		Element* temp = this->head;
		for (size_t i = 0; i < index - 1; i++)
		{
			temp = temp->nextptr;
		}
		Element* x = temp->nextptr;
		temp->nextptr = x->nextptr;
		delete x;
		size--;
	}
}
template <typename T>
int List<T>::sort(int l, int r) 
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
void List<T>::mergesort(int l, int r) {
	if (l < r) {
		mergesort(l, (l + r) / 2);
		mergesort((l + r) / 2 + 1, r);
		merge(l, r);
	}
}

template<typename T>
void List<T>::merge(int l, int r) 
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
void List<T>::quicksort(int l, int r) {
	if (l < r) 
	{
		int pivot = sort(l, r);
		quicksort(l, pivot - 1);
		quicksort(pivot + 1, r);
	}
}
template<typename T>
void List<T>::insert(T data, int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("index is out of range");
	}
	if (index == 0) push_front(data);
	else
	{
		Element* temp = this->head;
		for (size_t i = 0; i < index - 1; i++)
		{
			temp = temp->nextptr;
		}
		temp->nextptr = new Element<T>(data, temp->nextptr);
		size++;
	}
}
template<typename T>
T* List<T>::end()
{
	Element* temp = this->head;
	while (temp != nullptr)
	{
		temp = temp->nextptr;
	}
	return &temp->data;
}

template<typename T>
T& List<T>::operator[](const int index)
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

template<typename T>
bool List<T>::operator>(const List<T>& b)
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
bool List<T>::operator<(const List<T>& b)
{
	return !(*this >= b);
}

template<typename T>
bool List<T>::operator==(const List<T>& b)
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
bool List<T>::operator!=(const List<T>& b)
{
	return !(*this == b);
}

template<typename T>
bool List<T>::operator<=(const List<T>& b)
{
	return !(*this > b);
}

template<typename T>
bool List<T>::operator>=(const List<T>& b)
{
	return ((*this > b) || (*this == b));
}



#endif // !LIST_H
