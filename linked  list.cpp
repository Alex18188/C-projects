#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class List
{
public:
	List();
	~List();

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	void foo();

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	void popfront();
	void clear();
	void pushback(T dat);
	int getsize() { return size; }
	T& operator[](const int n);
	void pushfront(T data);
	void popback();
	void insert(T dat, int v);
	void removeAt(int v);
private:
	template<typename T>
	class Node
	{
	public:
		Node* pnext;//-=~_
		T data;
		Node(T d = T(), Node* p = nullptr)
		{
			data = d;
			pnext = p;
		}
	};
	int size;
	Node<T>* head;



};

template<typename T>
List<T>::List()
{//-=~_
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{//-=~_%
	clear();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void List<T>::foo()
{
	Node<T>* pp = head;
	Node<T>* ppp;
	for (int i = 0; i < size - 1; i++)
	{
		ppp = head;
		pp = pp->pnext;
		for (int j = 0; j <= i; j++)
		{
			if (pp->pnext == ppp->pnext || pp->pnext == head)
			{
				cout << "error\n";
				return;
			}
			ppp = ppp->pnext;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void List<T>::popfront()
{//-=~_%
	Node<T> *t = head;
	head = head->pnext;
	delete t;
	--size;
}


template<typename T>
void List<T>::clear()
{//-=~_%
	cout << "\nclear\n";
	while (size)
	{
		popfront();
	}
	
}

template<typename T>
void List<T>::pushback(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *pp = this->head;
		while (pp->pnext != nullptr)
		{
			pp = pp->pnext;
		}
		pp->pnext = new Node<T>(data);
	}
	size++;
}

template<typename T>
T& List<T>::operator[](const int n)
{
	int hamar = 0;
	Node<T>* pp = this->head;
	while (pp != nullptr)
	{
		if (hamar == n)
		{
			return pp->data;
		}
		pp = pp->pnext;
		++hamar;

	}
}

template<typename T>
void List<T>::pushfront(T data)
{//-=~_%
	head = new Node<T>(data, head);
	++size;
}

template<typename T>
void List<T>::popback()
{//-=~_%
	removeAt(size - 1);
}

template<typename T>
void List<T>::insert(T dat, int v)
{//-=~_%
	if (v == 0)
	{
		pushfront(dat);
	}
	else
	{
		Node<T>* pp = head;
		for (int i = 0; i < v - 1; i++)
		{
			pp = pp->pnext;
		}

		pp->pnext = new Node<T>(dat, pp->pnext);;
	}
	++size;
}

template<typename T>
void List<T>::removeAt(int v)
{//-=~_%
	if (v == 0)
	{
		popfront();
	}
	else
	{
		Node<T>* pp = head;
		for (int i = 0; i < v - 1; i++)
		{
			pp = pp->pnext;
		}
		Node<T>* del = pp->pnext;
		pp->pnext = del->pnext;
		delete del;
	}
	--size;
}



int main()//-=~_%
{
	List<int> l;
	l.pushback(1);
	l.pushback(2);
	l.pushback(3);
	l.pushback(4);
	l.pushback(5);
	for (int i = 0; i < l.getsize(); i++)
	{
		cout << l[i] << " ";
	}



}