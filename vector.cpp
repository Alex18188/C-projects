#include <iostream>
using namespace std;
template<typename T>
class vector//~%_-=
{
public:
	vector()
	{
		arr = nullptr;
		size = 0;
		capacity = 0;
	};
	vector(int qanak, int arjeq = 0);//~%_-=

	T front();
	T back();
	void pushback(T push);
	void popback();
	bool empty();
	void reserve(double tiv = 0.2);
	void resize(unsigned int tiv);
	T& operator[](unsigned int index); 
	void clear();
	void erase(int index);



	~vector() { delete[]arr; };
	
private://~%_-=
	unsigned int size, capacity;
	T* arr;

};

template<typename T>
vector<T>::vector(int qanak, int arjeq)
{
	arr = new T[qanak];
	for (int i = 0; i < qanak; i++)
	{
		arr[i] = arjeq;
	}
	size = qanak;
	capacity = qanak;
}

template<typename T>
T vector<T>::front()
{
	return arr[0];
}

template<typename T>//~%_-=
T vector<T>::back()
{
	return arr[size - 1];
}

template<typename T>
void vector<T>::pushback(T push)
{
	if (size = capacity)
	{
		reserve();
	}
	T* array = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		array[i] = arr[i];
	}
	array[size] = push;
	arr = array;
	delete[]array;
	++size;
}

template<typename T>
void vector<T>::popback()//~%_-=
{
	--size;
}

template<typename T>
bool vector<T>::empty()
{
	return (size == 0);
}

template<typename T>
void vector<T>::reserve(double tiv)
{
	if (tiv <= 0)
	{
		return;
	}
	else if (tiv != 0.2)
	{
		capacity += tiv;
		return;
	}
	else
	{
		capacity *= 2;
	}
}

template<typename T>
void vector<T>::resize(unsigned int tiv)
{
	if (tiv >= size)
	{
		capacity = tiv;
	}
}

template<typename T>
T& vector<T>::operator[](unsigned int index)
{
	return arr[index];
}

template<typename T>
void vector<T>::clear()//~%_-=
{
	delete[]arr;
	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
void vector<T>::erase(int index)
{
	T* array = new T[size - 1];
	for (int i = 0; i < index; i++)
	{
		array[i] = arr[i];
	}
	++index;
	while (index != size)
	{
		array[index] = arr[index];
		++index;
	}
	arr = array;
	delete[]array;
	--size;
	//--capacity;
}





int main()//~%_-=
{
	vector<int> vec(4);
	vec.pushback(2);








}


