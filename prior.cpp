#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Hert
{
public://_%~-=
	Hert()
	{


	};
	void push(int v, int priority)//_%~-=
	{
		if (priority >= 0 && priority < p.size())
		{
			p[priority].push_back(v);
		}
	};
	void print() 
	{
		cout << endl;
		for (int i = 0; i < p.size(); i++)
		{
			cout << "priority:" << i << "  ";
	    	for (list<int>::iterator it = p[i].begin(); it != p[i].end(); ++it) //??
			{
      			cout << *it << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	int pop(int i) 
	{
		int tiv = p[i].back();
		p[i].pop_back();
		return tiv;
	}
	void start() //_%~-=
	{
		for (int i = p.size() - 1; i >= 0; --i)
		{
			while(p[i].size() != 0)
			{
				cout << endl << "Priority: " << i << endl;
				cout << "mteq hamar " << pop(i) << endl;
			}
		}
	
	
	}




	void maxpriority(int tiv) 
	{
		p.resize(tiv + 1);
	}
private://_%~-=
	vector <list<int>> p;
};

int main()//_%~-=
{
	Hert hert;
	int tiv;
	cout << "nermuceq gerakayutyan chap@: "; cin >> tiv;
	hert.maxpriority(tiv);
	hert.push(45, 2);
	hert.push(16, 2);
	hert.push(1, 0);
	hert.push(12, 0);
	hert.push(2, 4);
	hert.push(244, 4);
	hert.push(4, 3);
	hert.push(43, 3);
	hert.push(67, 1);
	hert.push(47, 1);
	
	hert.print();
	
	cout << "priority: 3\nmteq hamar " << hert.pop(3) << endl;
	hert.start();
	
	
}


