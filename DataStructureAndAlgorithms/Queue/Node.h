template<typename T>
class Node 
{
public:
	T m_val ;
	Node<T> *Next = NULL;

	Node<T>(T val) { m_val = val; };
};
