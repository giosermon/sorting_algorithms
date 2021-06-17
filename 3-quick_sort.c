#include "sort.h"
/**
 * recursion - function that executes recursion
 * @array: input array
 * @low: left side of the matrix
 * @high: rigth side of the matrix
 * @size: array size
 */
void recursion(int *array, int low, int high, size_t size)
{
	int depart;

	if (low < high)
	{
		depart = partition(array, low, high, size);
		recursion(array, low, depart - 1, size);
		recursion(array, depart + 1, high, size);
	}
}

/**
 * partition - lamuto Partition function to divide the array by the pivot
 * @array: Array of integers
 * @lower: lowest number in the array
 * @higher: Highest number in the array
 * @size: Size of the array
 * Return: index
 */


int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = (low), j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[j] != array[i])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[high] != array[i])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
* quick_sort - Sorts an array of integers in ascending order
* @array: array to be sorted
* @size: size of array
* Return: void
*/

void quick_sort(int *array, size_t size)
{
	int high = (size - 1), low = 0;

	if (array == NULL)
		return;
	recursion(array, low, high, size);
}

/**
 * swap - swaps the values of two integers
 * @xp: pointer to int to be swapped
 * @yp: pointer to other int to be swapped
 */
void swap(int *xp, int *yp)
{
	size_t temp = *xp;

	*xp = *yp;
	*yp = temp;
}
