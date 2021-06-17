#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: Void - No return
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int j, swapp = 1;
	int tmp = 1;

	while (swapp)
	{
		swapp = 0;
		for (j = 1; j < size; j++)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
				swapp = 1;
			}
		}

	}
}
