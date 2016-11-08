#include"sort.h"
#include"globals.h"

int sortIns(int* arr, int num)
{
	int temp, j;
	int t = clock();
	for (int i = 1; i < num; i++)
	{
		C++;
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			j = i - 1;
			while (arr[j] > temp && j >= 0)
			{
				C++;
				M++;
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = temp;
		}
	}
	t = clock() - t;
	return t;
}
int Ins(int* arr, int size, int num)
{
	int temp, j;
	int t = clock();
	for (int k = 0; k < num; k++)
	{
		for (int i = k + num; i < size; i += num)
		{
			C++;
			if (arr[i] < arr[i - num])
			{
				temp = arr[i];
				j = i - num;
				while (arr[j] > temp && j >= num - 1)
				{
					C++;
					M++;
					arr[j + num] = arr[j];
					j -= num;
				}
				arr[j + num] = temp;
			}
		}
	}
	t = clock() - t;
	return t;
}
int sortShell(int* arr, int size)
{
	int t = 0;
	int n = log(size) / log(3) - 1;
	int* step = new int[n];
	step[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
		step[i] = 3 * step[i + 1] + 1;

	for (int i = 0; i < n; i++)
		t += Ins(arr, size, step[i]);
	/*int i = size / 2;
	while (i >= 1)
	{
		t += Ins(arr, size, i);
		i /= 2;
	}*/
	
	return t;
}
int SelectionSort(int* arr, int size)
{
	int temp, j;
	int t = clock();
	for (int i = 0; i < size - 1; i++)
	{
		temp = arr[i];
		j = i;
		for (int k = i + 1; k < size; k++)
			if (arr[k] < arr[j]) j = k;
		if (j != i)
		{
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	t = clock() - t;
	return t;
}
int BubbleSort(int* arr, int size)
{
	bool flag = true;
	int temp;
	int t = clock();
	while (flag == true)
	{
		flag = false;
		for (int i = 0; i < size-1; i++)
		{
			if (arr[i]>arr[i + 1])
			{
				flag = true;
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
	t = clock() - t;
	return t;
}
void MergeSort(int* arr, int first, int last)
{
	if (first < last)
	{
		MergeSort(arr, first, (first + last) / 2);
		MergeSort(arr, (first + last) / 2 + 1, last);
		Merge(arr, first, last);
	}
}
void Merge(int* arr, int first, int last)
{
	int start, middle, endpart, j;
	int *mas = new int[last - first + 1];
	middle = (first + last) / 2;
	start = first;
	endpart = middle + 1;
	for (j = 0; j <= last - first; j++)
	{
		if (start <= middle && ((endpart > last) || (arr[start] < arr[endpart])))
		{
			mas[j] = arr[start];
			start++;
		}
		else
		{
			mas[j] = arr[endpart];
			endpart++;
		}
	}
	for (j = 0; j <= last - first; j++)
		arr[j + first] = mas[j];
	delete [] mas;
}