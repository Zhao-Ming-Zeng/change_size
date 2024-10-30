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
		cout << "�L�k�X�i" << endl;
	}
}

void main()
{
	int size;
	cout << "�п�J�ݭn���}�C�j�p�G";
	cin >> size;
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	cout << "�X�i�e�}�C���G";
	print_arr(arr,size);
	cout << endl;

	int n_size;
	cout << "�п�J�Q�n�ܦ����}�C�j�p�G";
	cin >> n_size;
	change_size(arr,size,n_size);
	
	for (int i = size; i < n_size; i++)
	{
		arr[i] = i;
	}
	cout << "�X�i��}�C���G";
	print_arr(arr, n_size);
}