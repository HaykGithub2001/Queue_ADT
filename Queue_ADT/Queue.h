#pragma once
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