#include <iostream>
using namespace std;

template <typename T> class List;

template <typename T>
class Listnode
{
public:
	friend class List<T>;
	Listnode( T& f);

private:
	T data;
	Listnode<T>* pnext;
};

template <typename T>
Listnode<T>::Listnode(T& f)
{
	data = f;
	pnext = nullptr;
}




template <typename T>//~%_-=
class List
{
public:
	List();
	~List();

	void insertinfront(T d);//~%_-=
	void insertinback(T d);
	bool removeformfront();
	bool removeformback();
	bool isempty();
	void print();//~%_-=
	Listnode<T>* getnode(T& d);
private:
	Listnode<T>* firstptr;
	Listnode<T>* lastptr;
};

template <typename T>
List<T>::List()
{
	firstptr = lastptr = 0;
}

template <typename T>//~%_-=
List<T>::~List()
{
	if (!isempty())
	{
		Listnode<T>* aptr = firstptr;
		Listnode<T>* bptr;
		while (aptr != 0)
		{
			bptr = aptr;
			aptr = aptr->pnext;
			delete bptr;
		}
	}
}

template<typename T>
void List<T>::insertinfront(T d)//~%_-=
{
	Listnode<T>* newptr = getnode(d);
	if (isempty())
	{
		firstptr = lastptr = newptr;
	}
	else
	{
		newptr->pnext = firstptr;
		firstptr = newptr;
	}
}

template<typename T>
void List<T>::insertinback(T d)
{
	Listnode<T>* newptr = getnode(d);//~%_-=
	if (isempty())
	{
		firstptr = lastptr = newptr;
	}
	else
	{
		lastptr->pnext = newptr;
		lastptr = newptr;
	}
}

template<typename T>//~%_-=
bool List<T>::removeformfront()
{
	if (isempty())
	{
		return 0;
	}
	Listnode<T>* newptr = firstptr;
	if (firstptr == lastptr)
		firstptr = lastptr = 0;
	else
		firstptr = firstptr->pnext;

	delete newptr;
	return true;

}

template<typename T>
bool List<T>::removeformback()
{
	if (isempty())
	{
		return 0;
	}
	Listnode<T>* newptr = lastptr;
	Listnode<T>* aptr = firstptr;
	if (firstptr == lastptr)
	{
		firstptr = lastptr = 0;
	}
	else
	{
		while (aptr->pnext != lastptr)
			aptr == aptr->pnext;
	}
	delete newptr;
	lastptr = aptr;
	aptr->pnext = 0;
	return 1;

}

template<typename T>
bool List<T>::isempty()
{
	return (firstptr == 0);
}

template<typename T>
void List<T>::print()
{
	if (isempty())
	{
		cout << "The List is empty \n";
		return;
	}
	Listnode<T>* aptr = firstptr;
	cout << "The List is \n";
	while (aptr != 0)
	{
		cout << aptr->data << " ";
		aptr = aptr->pnext;
	}
	cout << endl;
}

template<typename T>
Listnode<T>* List<T>::getnode(T& d)
{
	return new Listnode<T>(d);
}




int main()
{
	const int a = 8,b = 11;
	List<string> l;
	l.print();
	l.removeformback();
	l.removeformfront();
	l.print();
	cout << l.isempty();
	l.insertinback("assa");
	l.insertinback("assa");
	l.insertinback("assa");
	l.insertinback("assa");
	l.insertinback("assa");
	l.insertinback("assa");
	l.insertinback("assa");
	l.insertinback("assa");
	l.insertinback("assa");
	l.print();

}

















