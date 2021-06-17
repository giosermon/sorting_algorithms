#include "sort.h"

/**
 * shell_sort - Shell sort algorithm an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the array
 * Return - void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, value = 1, j;
	int tmp;

	if (!array || size < 2)
		return;

	while (value < size / 3)
	{
		value = value * 3 + 1;
	}

	while (value > 0)
	{
		for (i = value; i < size; i++)
		{
			tmp = array[i];
			for (i = value; i < size; i += 1)
			{
				tmp = array[i];

				j = i;
				while (j >= value && array[j - value] > tmp)
				{
					array[j] = array[j - value], j -= value;
				}
				array[j] = tmp;
			}
		}
		print_array(array, size), value = (value - 1) / 3;
	}
}
