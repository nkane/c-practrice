/*
 * sort.h
 *
 */

void
Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void
BubbleSort(int array[], int size)
{
	bool swapped = false;
	for (int i = 0; i < size - 1; ++i)
	{
		swapped = false;
		for (int j = 0; j < size - (1 + i); ++j)
		{
			if (array[j] > array[j + 1])
			{
				swapped = true;
				Swap(&array[j], &array[j + 1]);
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

void
SelectionSort(int array[], int size)
{
	int i = 0;
	int j = 0;
	int min_index = 0;

	for (i = 0; i < size - 1; ++i)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Swap(&array[i], &array[min_index]);
		}
	}
}

void
InsertionSort(int array[], int size)
{
	int i = 0;
	int j = 0;
	int key = 0;

	for (int i = 1; i < size; ++i)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}

