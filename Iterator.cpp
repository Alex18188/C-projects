#include <iostream>
using namespace std;//=-~_%-=
template<typename T>
class myIterator
{
public:
	myIterator(T* my = nullptr)
	{
		myElement = my;
	}
	T getmyElement() { return *myElement; }
	myIterator& operator ++() 
	{
		++myElement;
		return *this;
	}
	myIterator operator ++(T)
	{
		myIterator m(myElement);
		++myElement;
		return m;
	}
	bool operator !=(myIterator m) 
	{
		return this->myElement != m.myElement; 
	}
private:
	T* myElement;
};



template<typename T>
int main()//=-~_%-=
{
	const int n = 5;
	int arr[n]{ 1,2,3,4,5 };
	myIterator I(arr);
	cout << I.getmyElement() << endl;
	++I;
	cout << I.getmyElement() << endl;
	I++;
	cout << I.getmyElement() << endl;
	myIterator<T> my(arr + 4);
	cout << (my != I) << endl;
	return 0;
}
