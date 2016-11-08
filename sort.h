#ifndef __SORT_H__
#define __SORT_H__
#include<iostream>
#include<math.h>
#include<ctime>
#include<fstream>
using namespace std;


int sortIns(int* arr, int num);
int Ins(int* arr, int size, int num);
int sortShell(int* arr, int size);
int SelectionSort(int*, int);
int BubbleSort(int*, int);
void Merge(int*, int, int);
void MergeSort(int*, int, int);
#endif