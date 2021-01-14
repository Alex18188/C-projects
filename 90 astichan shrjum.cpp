#include <iostream>
using namespace std;
void func(int** arr, int arjeq, int min, int max)
{
	
	for (int i = 0; i < arjeq - 1; i++)
	{
		swap(arr[min][min + i], arr[min + i][max]);
		swap(arr[min][min + i], arr[max][max - i]);
		swap(arr[min][min + i], arr[max - i][min]);

	}
	if (arjeq > 3)
	{
		++min, --max, arjeq = arjeq - 2;
		func(arr, arjeq, min, max);
	}
	if (arjeq < 4)
	{
		return;
	}
}
int main()
{
	cout << "nermuceq tiv@: ";
	int n;
	cin >> n;
	cout << endl;
	int ** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0, l = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = l;
			++l;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int arjeq = n, min = 0, max = n - 1;
	func(arr, arjeq, min, max);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}