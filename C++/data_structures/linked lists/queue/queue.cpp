#include <iostream>


template<typename T>
struct Node_t
{
	T data;
	Node_t* next;
};


template<typename T>
class queue
{
private:
	Node_t<T>* begin;
	Node_t<T>* end;
public:
	queue();
	queue(const queue &other);
	~queue();
	void addNode(T data);

};



template<typename T>
queue<T> :: queue()
{
	begin = nullptr;
	end = nullptr;

}

template<typename T>
void queue<T> :: addNode(T data)
{
	Node_t<T>* new_node = new Node_t<T>;
	new_node->data = data;
	new_node->next = nullptr;
	if(end == nullptr)
	{
		end = new_node;
		begin = new_node->next;
	}
	else 
	{

	}

}





int main ()
{
	return 0;
}
