
#ifndef _LIST_H
#define _LIST_H

template <typename T>
class Node {
public:
    Node(T d, Node * n, Node * p)
	{
		data = d;
		next = n;
		prev = p;
	}
    Node(T d, Node * n)
	{
		data = d;
		next = n;
		prev = 0;
	}
    Node(T d)
	{
		data = d;
		next = 0;
		prev = 0;
	}
    T data;
    Node * next;
    Node * prev;
};

template <typename T>
class List {
public:
    List()
	{
		head = 0;
		tail = 0;
	}
    void push_front(T element)
	{
		Node<T> * node = new Node<T>(element, head);
		if (head != 0)
		{
			head -> prev = node;
		}
		head = node;
		if (tail == 0)
		{
			tail = node;
		}
	}
    T peek_front()
	{
		return head -> data;
	}
    void pop_front()
	{
		Node<T> * node = head -> next;
		delete head;
		head = node;
		if (node != 0)
		{
			node -> prev = 0;
		}
		else
		{
			tail = head;
		}
	}
    void push_back(T element)
	{
		Node<T> * node = new Node<T> (element, 0, tail);
		if (tail != 0)
		{
			tail -> next = node;
		}
		tail = node;
		if (head == 0)
		{
			head == node;
		}
	}
    T peek_back()
	{
		return tail -> data;
	}
    void pop_back()
	{
		Node<T> * node = tail -> prev;
		delete tail;
		tail = node;
		if (node != 0)
		{
			node -> next = 0;
		}
		else
		{
			head = tail;
		}
	}
    bool empty()
	{
		return head == 0 && tail == 0;
	}
    Node<T> * begin()
	{
		return head;
	}
    Node<T> * end()
	{
		return 0;
	}
    Node<T> * last()
	{
		return tail;
	}
    int size()
	{
		int result = 0;
		for (Node<T> * pointer = head; pointer != 0; pointer = pointer -> next)
		{
			result++;
		}
		return result;
	}
private:
    Node<T> * head;
    Node<T> * tail;
};

#endif