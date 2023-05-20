#include<iostream>
template <typename T>
class Queue
{
public:
	Queue();
	void push(T data);
	void pop();
	int length() { return size; }
	void output();
	T& front();
	bool empty() { return size == 0; }
	
private:
	template <typename T>
	class Node
	{
	public:
		Node<T>* pnext;
		Node<T>* pprev;
		T data;
		Node(T data=NULL, Node<T>* pnext = nullptr,Node<T>* pprev=nullptr) :data(data), pnext(pnext),pprev(pprev) {}
	};
	Node<T>* head;
	Node<T>* tail;
	int size;

};

template <typename T>
Queue<T>::Queue()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template <typename T>
void Queue<T>::push(T data)
{
	if (size == 0)
	{
		head = new Node<T>(data);
		tail = head;
	}
	else
	{
		head = new Node<T>(data, head);
		head->pnext->pprev = head;
	}
	size++;
}
template <typename T>
void Queue<T>::pop()
{
	if (size == 0)
	{
		return;
	}
	else if (size == 1)
	{
		head = tail = nullptr;
	}
	else
	{
		tail = tail->pprev;
		tail->pnext = nullptr;
	}
	size--;
	return;
}
template <typename T>
void Queue<T>::output()
{
	Node<T>* counter = head;
	while (counter != nullptr)
	{
		std::cout << counter->data << ' ';
		counter = counter->pnext;
	}
	delete counter;
	std::cout << std::endl;
}
template <typename T>
T& Queue<T>::front()
{
	return head->data;
}