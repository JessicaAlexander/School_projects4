// Binary Search Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<time.h>
#include<random>
using namespace std;

void fill(int list[], int n)
{
	for (int i = 0; i < n; i++)
		list[i] = rand() % 200;
}

int no_of_iterations;

void Bubble_Sort(int list[], int size)
{
	bool sort = false;
	while (!sort)
	{
		sort = true;
		for (int i = 1; i < size; i++)
		{
			if (list[i - 1] > list[i])
			{
				swap(list[i - 1], list[i]);
				sort = false;
			}
		}
		size--;
	}
}

int SequentialSearch(int list[], int n, int search)
{
	for (int i = 0; i < n; i++)
	{
		no_of_iterations++;
		if (list[i] == search)
			return i;
	}
	return -1;
}

int BinarySearch(int list[], int search, int l, int r)
{
	no_of_iterations++;
	if (l > r)
		return -1;
	int m = (l + r) / 2;
	if (search == list[m])
		return m;
	if (search > list[m])
		l = m + 1;
	else if (search < list[m])
		r = m - 1;
	return BinarySearch(list, search, l, r);
}

int main()
{
	srand(time(0));
	int list[1000];
	fill(list, 1000);
	Bubble_Sort(list, 1000);

	while (true)
	{
		cout << "Enter element to search: ";
		int search;
		cin >> search;
		no_of_iterations = 0;
		int index = SequentialSearch(list, 1000, search);
		cout << "Number of iterations using Sequential search is: " << no_of_iterations << endl;
		no_of_iterations = 0;
		index = BinarySearch(list, search, 0, 1000);
		cout << "Number of iterations using Binary search is: " << no_of_iterations << endl;
		if (index != -1)
			cout << "Index of element is: " << index << endl;
		else
			cout << "Element not found\n";
		cout << "Enter E to stop the program: ";
		char choise;
		cin >> choise;
		if (choise == 'e' || choise == 'E')
			break;
	}
}