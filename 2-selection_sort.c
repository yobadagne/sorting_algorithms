#include "sort.h"
/**
  * selection_sort - function that sorts an array of integers
  * in ascending order using the Selection sort algorithm
  * @array: is data
  * @size: is size data
  * Return: nothing
  */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t element;
	int tmp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		element = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[element])
			{
				element = j;
			}
		}
		if (element != i)
		{
			tmp = array[i];
			array[i] = array[element];
			array[element] = tmp;
			print_array(array, size);
		}
	}
}
