#include <iostream>
using namespace std;
void CountingSort(int arr[], const int S)
{
	int mectiv = arr[0];
	for (int i = 1; i < S; i++)
	{
		if (arr[i] > mectiv)
			mectiv = arr[i];
	}
	int* array = new int[mectiv + 1];
	for (int i = 0; i <= mectiv; i++)
	{
		array[i] = 0;
	}
	for (int i = 0; i < S; i++)
	{
		array[arr[i]]++;
	}
	cout << endl << endl;
	for (int i = 0; i <= mectiv; i++)
	{
		cout << array[i] << endl;
	}
	cout << endl << endl;
	for (int i = 0,j = 0; i <= mectiv; i++)
	{
		for (int l = 0; l < array[i]; j++, ++l)
		{
			arr[j] = i;
		}
	}
	cout << endl << endl;
	for (int i = 0; i < S; i++)
	{
		cout << arr[i] << endl;
	}

}
int main()
{//-=~_
	const int S = 24;
	int arr[S]{ 0,2,6,5,1,3,5,6,5,6,5,6,4,4,2,4,2,2,4,2,0,0,2 };
	CountingSort(arr, S);
}
