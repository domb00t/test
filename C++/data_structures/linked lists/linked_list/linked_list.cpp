#include <iostream>





template<typename Type>
class List
{
public:
	List();
	~List();
	void push_back(Type data);
	void push_front(Type data);
	void insert(Type data,int index);
	void removeAt(int index);
	void pop_front();
	void pop_back();
	void clear();
	int getSize() {return size;}
	Type& operator[](const int index);
private:
	template<typename T>
	class Node
	{
	public:

		Node* next;
		T data;

		Node(T data=T(),Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	Node<Type>* head;
	int size;
};

template<typename Type>
List<Type> :: List()
{
	size = 0;
	head = nullptr;

}

template<typename Type>
void List<Type> :: push_back(Type data)
{
	if(head == nullptr)
	{
		head = new Node<Type>(data);
	}
	else 
	{
		Node<Type>* current = this->head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node<Type>(data);
	}
	size++;
}



template<typename Type>
void List<Type> :: push_front(Type data)
{
	head = new Node<Type>(data,head);
	size++;
}


template<typename Type>
void List<Type> :: insert(Type data, int index)
{
	if(index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<Type>* previous = head;
		for(int i = 0;i < index - 1;i++)
		{
			previous = previous->next;
		}
		previous->next = new Node<Type>(data,previous->next);
		size++;
	}
}

template<typename Type>
void List<Type> :: removeAt(int index)
{
	if(index == 0)
	{
		pop_front();
	}
	else
	{
		Node<Type> *previous = head;
		for(int i = 0; i < index -1;i++)
		{
			previous = previous->next;
		}
		Node<Type>* tmp = previous->next;
		previous->next = tmp->next;
		delete tmp;

		size--;
	}
}

template<typename Type>
Type& List<Type> ::operator[](const int index)
{
	Node<Type>* current = head;
	int count = 0;
	while (current != nullptr)
	{
		if(count == index)
		{
			return current->data;
		}
		current = current->next;
		count++;
	}
}

template<typename Type>
List<Type> :: ~List()
{
	clear();
}


template<typename Type>
void List<Type> :: pop_front()
{
	Node<Type>* tmp = head;
	head = head ->next;
	delete tmp;
	size--;
}


template<typename Type>
void List<Type> :: pop_back()
{
	removeAt(size-1);
}

template<typename Type>
void List<Type> :: clear()
{
	while (size)
	{
		pop_front();
	}
}

int main()
{
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);
	for(int i = 0; i < lst.getSize();i++)
	{
		std :: cout << lst[i] << '\n';
	}
	std :: cout << lst.getSize() << '\n';
	lst.insert(100,3);
	std :: cout << lst.getSize() << '\n';
	for(int i = 0; i < lst.getSize();i++)
	{
		std :: cout << lst[i] << '\n';
	}
	lst.removeAt(2);
	for (int i = 0 ;i < lst.getSize();i++)
	{	

		std :: cout << lst[i] << '\n';
	}
	lst.pop_back();
	for (int i = 0 ;i < lst.getSize();i++)
	{
		std :: cout << lst[i] << '\n';
	}
	return 0;
}
