#include "sort.h"
/**
  * place - placed elements to print
  * @array: is data
  * @size: is size data
  * @x: less
  * @y: higher
  * Return: nothing
  */
void place(int *array, size_t size, int x, int y)
{
	int tmp;

	if (array[x] != array[y])
	{
		tmp = array[x];
		array[x] = array[y];
		array[y] = tmp;
		print_array(array, size);
	}
}
/**
  * partition - Lomuto partition scheme
  * @array: is data
  * @size: is size data
  * @x: less
  * @y: higher
  * Return: element
  */
int partition(int *array, size_t size, int x, int y)
{
	int pivot  = array[y];
	int i = x;
	int j;

	for (j = x; j <= y; j++)
	{
		if (array[j] < pivot)
		{
			place(array, size, i, j);
			i++;
		}
	}
	place(array, size, i, y);
	return (i);
}
/**
  * quicksort - recursive process
  * @array: is data
  * @size: is size data
  * @x: less
  * @y: higher
  * Return: nothing
  */
void quicksort(int *array, size_t size, int x, int y)
{
	size_t qs;

	if (x < y)
	{
		qs = partition(array, size, x, y);
		quicksort(array, size, x, qs - 1);
		quicksort(array, size, qs + 1, y);
	}
}
/**
  * quick_sort - function that sorts an array of integers
  * in ascending order using the Quick sort algorithm
  * @array: is data
  * @size: is size data
  * Return: nothing
  */
void quick_sort(int *array, size_t size)
{
	int x;
	int y;

	if (array && size)
	{
		x = 0;
		y = size - 1;
		quicksort(array, size, x, y);
	}
}
