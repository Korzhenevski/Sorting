#include"sort.h"
#include"globals.h"

int main()
{
	int size = 100;
	int* a = new int[size];
	srand(time(NULL));
	for(int i = 0; i < size; i++)
		a[i] = rand();
	cout << endl << endl;
	//ofstream out;
	//out.open("array.txt");
	for (int i = 0; i < size; i++)
	{
	cout << a[i] << "\t";
	////	/*if (i % 10 == 0) out << "\n";
	////	out << a[i] << "\t";*/
	}
	cout << endl;
	int t;
	//t = sortIns(a, size); 
	//t = sortShell(a, size); // for next sorting-functions write C++ & M++
	//t = SelectionSort(a, size);
	//t = BubbleSort(a, size);
	t = clock();
	MergeSort(a, 0, size - 1);
	t = clock() - t;
	//cout << endl << endl;
	////out << "\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "\t";
	//////	/*if (i % 10 == 0) out << "\n";
	//////	out << a[i] << "\t";*/
	}
	cout << endl;
	//out.close();
	delete [] a;
	cout << "Compares: " << C << endl
		<< "Moves: " << M << endl
		<< "Time: " << float(t) / CLOCKS_PER_SEC << " sec" << endl;
	system("pause");
	return 0;
}