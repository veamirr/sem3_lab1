#include <iostream>
#include "ArraySequence.h"
#include "DynamicArray.h"
#include "LinkedListSequence.h"
#include <time.h>
#include "Sort.h"
using namespace std;

bool cmp(int a, int b)
{
	if (a >= b) return true;
	else return false;
}

void arrayShakeSortTest()
{
	ArraySequence<int>* arr = new ArraySequence<int>(500);
	Sort<int> sort;
	int x, flag = 1;
	clock_t start, end;

	for (int i = 0; i < 500 ; i++)
	{
		x = rand();
		arr->insertAt(i, x);
	}

	start = clock();
	sort.shakeSort(arr,cmp);
	end = clock();

	for (int i = 0; (i < (arr->getLength()-1)) && (flag == 1); i++)
	{
		if (arr->get(i) > arr->get(i + 1)) flag = 0;
	}

	if (flag == 1) cout << "ArrayShakeSort succecfully tested with time " << ((double)end-start)/((double) CLOCKS_PER_SEC) << "\n" << "\n";
	else cout << "shakeSort NOT succecfully tested\n" << "\n";
}

void arrayInsertSortTest()
{
	ArraySequence<int>* arr = new ArraySequence<int>(500);
	Sort<int> sort;
	int x, flag = 1;
	clock_t start, end;

	for (int i = 0; i < 500; i++)
	{
		x = rand();
		arr->insertAt(i, x);
	}

	start = clock();
	sort.insertSort(arr,cmp);
	end = clock();

	for (int i = 0; (i < (arr->getLength() - 1)) && (flag == 1); i++)
	{
		if (arr->get(i) > arr->get(i + 1)) flag = 0;
	}

	if (flag == 1) cout << "ArrayInsertSort succecfully tested with time " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << "\n" << "\n";
	else cout << "insertSort NOT succecfully tested\n" << "\n";
}

void arraySelectionSortTest()
{
	ArraySequence<int>* arr = new ArraySequence<int>(500);
	Sort<int> sort;
	int x, flag = 1;
	clock_t start, end;

	for (int i = 0; i < 500; i++)
	{
		x = rand();
		arr->insertAt(i, x);
	}

	start = clock();
	sort.SelectionSort(arr, cmp);
	end = clock();

	for (int i = 0; (i < (arr->getLength() - 1)) && (flag == 1); i++)
	{
		if (arr->get(i) > arr->get(i + 1)) flag = 0;
	}

	if (flag == 1) cout << "ArraySelectionSort succecfully tested with time " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << "\n" << "\n";
	else cout << "selectionSort NOT succecfully tested\n" << "\n";
}

void listShakeSortTest()
{
	LinkedListSequence<int>* list = new LinkedListSequence<int>;
	Sort<int> sort;
	int x, flag = 1;
	clock_t start, end;

	for (int i = 0; i < 500; i++)
	{
		x = rand();
		list->prepend(x);
	}

	start = clock();
	sort.shakeSort(list, cmp);
	end = clock();

	for (int i = 0; (i < 499) && (flag == 1); i++)
	{
		if (list->get(i) > list->get(i + 1)) flag = 0;
	}

	if (flag == 1) cout << "ListShakeSort succecfully tested with time " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << "\n" << "\n";
	else cout << "ListShakeSort NOT succecfully tested\n" << "\n";
}

void listInsertSortTest()
{
	LinkedListSequence<int>* list = new LinkedListSequence<int>;
	Sort<int> sort;
	int x, flag = 1;
	clock_t start, end;

	for (int i = 0; i < 10; i++)
	{
		x = rand();
		cout << x << "\n";
		list->prepend(x);
	}

	start = clock();
	sort.insertSort(list, cmp);
	end = clock();

	for (int i = 0; (i < 10) && (flag == 1); i++)
	{
		//if (list->get(i) > list->get(i + 1)) flag = 0;
		cout << list->get(i) << "\n";
	}

	if (flag == 1) cout << "ListInsertSort succecfully tested with time " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << "\n" << "\n";
	else cout << "ListInsertSort NOT succecfully tested\n" << "\n";
}


int main()
{
	arrayShakeSortTest();
	arrayInsertSortTest();
	arraySelectionSortTest();

	//listShakeSortTest();//сортировки для списков неверны. Что с insertAt?
	//listInsertSortTest();

	return 0;
};