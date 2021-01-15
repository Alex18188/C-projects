#include <iostream>
using namespace std;
int main()
{
	cout << "nermuceq tiv@: ";
	int n;
	cin >> n;
	int** arr = new int* [n];
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
	while (arjeq >= 2)
	{
		for (int i = 0; i < arjeq - 1; i++)
		{
			swap(arr[min][min + i], arr[min + i][max]);
			swap(arr[min][min + i], arr[max][max - i]);
			swap(arr[min][min + i], arr[max - i][min]);
		}
		++min, --max, arjeq = arjeq - 2;
	}
	if (arjeq < 2)
	{
		for (int r = 0; r < n; r++)
		{
			for (int e = 0; e < n; e++)
			{
				cout << arr[r][e] << " ";
			}
			cout << endl;
		}
	}
}
