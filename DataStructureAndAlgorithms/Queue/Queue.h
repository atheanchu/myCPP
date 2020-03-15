#include "Node.h"

template <typename T>
class Queue
{
private:
	int m_count = 0;
	Node<T> *m_front;
	Node<T> *m_back;

public:
	Queue() {};
	bool IsEmpty();
	T Front();
	void Enqueue(T val);
	void Dequeue();	
};

template<typename T>
T Queue<T>::Front() 
{
	return m_front->m_val;
}

template<typename T>
bool Queue<T>::IsEmpty()
{
	return m_count == 0;
}

template<typename T>
void Queue<T>::Enqueue(T val)
{
	Node<T> * node = new Node<T>(val);	

	if(m_count == 0) 
	{
		node->Next = NULL;
		m_front = node;
		m_back = m_front;
	}
	else
	{
		m_back->Next = node;
		m_back = node;
	}
	m_count++;
}

template<typename T>
void Queue<T>::Dequeue()
{
	if(m_count == 0) return;
	Node<T> *temp = m_front;
	m_front = m_front->Next;
	delete temp;
	m_count--;
}