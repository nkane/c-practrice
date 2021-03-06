/*
 * Modify program 8.13 to use a list of 100 randomly generated
 * numbers and determine the number of moves required to put the
 * list in order using a selection sort. Display both the initial
 * list and the reordered list
 *
 * Implement for bubble sort as well.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 10;

void
GenerateNumber(int array[], int size);

void
PrintArray(int array[], int size, char *text);

void
Swap(int *x, int *y);

int
BubbleSort(int array[], int size);

int
SelectionSort(int array[], int size);

int
main()
{
	int TestCase[Size] = { 0 };

	GenerateNumber(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "bubble sort (before):");
	printf("bubble sort swap count: %d\n", BubbleSort(TestCase, len(TestCase)));
	PrintArray(TestCase, len(TestCase), "bubble sort (after):");

	printf("\n");

	GenerateNumber(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "selection sort (before):");
	printf("selection sort swap count: %d\n", SelectionSort(TestCase, len(TestCase)));
	PrintArray(TestCase, len(TestCase), "selection sort (after):");


	return 0;
}

void
GenerateNumber(int array[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		array[i] = (1 + (rand() % 100));
	}
}

void
PrintArray(int array[], int size, char *text)
{
	printf("%s { ", text);
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
}

void
Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int
BubbleSort(int array[], int size)
{
	bool swapped = false;
	int swapCount = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		swapped = false;
		for (int j = 0; j < size - (i + 1); ++j)
		{
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				swapped = true;
				++swapCount;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
	return swapCount;
}

int 
SelectionSort(int array[], int size)
{
	int swapCount = 0;
	int i = 0;
	int j = 0;
	int min_index = 0;

	for (int i = 0; i < size - 1; ++i)
	{
		min_index = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (array[min_index] > array[j])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			++swapCount;
			Swap(&array[min_index], &array[i]);
		}
	}
	return swapCount;
}

