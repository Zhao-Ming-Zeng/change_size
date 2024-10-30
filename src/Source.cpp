#include<iostream>
using namespace std;

void print_arr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void change_size(int* &arr, int size, int n_size)
{
	if (n_size > size)
	{
		int* n_arr = new int[n_size];
		int* recycle = arr;
		copy(arr, arr + size, n_arr);
		delete[] recycle;
		arr = n_arr;
	}
	else
	{
		cout << "無法擴展" << endl;
	}
}

void main()
{
	int size;
	cout << "請輸入需要的陣列大小：";
	cin >> size;
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	cout << "擴展前陣列為：";
	print_arr(arr,size);
	cout << endl;

	int n_size;
	cout << "請輸入想要變成的陣列大小：";
	cin >> n_size;
	change_size(arr,size,n_size);
	
	for (int i = size; i < n_size; i++)
	{
		arr[i] = i;
	}
	cout << "擴展後陣列為：";
	print_arr(arr, n_size);
}