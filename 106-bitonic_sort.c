#include "sort.h"

/**
* bitonic_sort - sorts an array of integers in ascending order
*               using the bitonic sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/

void bitonic_sort(int *array, size_t size)
{
	size_t i;
	size_t j = size;
	int temp;

	if (array == NULL)
		return;

	while (j > 0)
	{
		for (i = 0; i + j < j; i++)
		{
			if (array[i] > array[i + j])
			{
				temp = array[i];
				array[i] = array[i + j];
				array[i + j] = temp;
			}
		}
		j = j / 2;
	}

	for (i = 0; i < size; i++)
	{
		printf("Merging [%d/%d] (UP):\n", (int)i, (int)size);
		print_array(array, size);
	}
}
