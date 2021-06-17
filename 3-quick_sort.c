#include "sort.h"
/**
 * partition - lamuto Partition function to divide the array by the pivot
 * @array: Array of integers
 * @lower: lowest number in the array
 * @higher: Highest number in the array
 * @size: Size of the array
 * Return: index
 */


int partition(int *array, size_t low, size_t pivot, size_t size)
{
	size_t i, temp;

	for (i = low; i < pivot; i++)
	{
		if (array[i] < array[pivot])
		{
			if (i != low)
			{
				temp = array[low];
				array[low] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			low++;
		}
	}
	if (array[low] > array[pivot])
	{
		temp = array[low];
		array[low] = array[pivot];
		array[pivot] = temp;
		pivot = low;
		print_array(array, size);
	}
	return (pivot);
}

/**
* q_sort -  quick sort algorithm
* @array: The array to be sorted
* @start: beginning of array
* @end: end of array
* @size: size of array
* Return: void
*/

void q_sort(int *array, size_t start, size_t end, size_t size)
{
	size_t pivot;

	if (end <= start || end == 0)
		return;

	pivot = partition(array, start, end, size);

	if (pivot > start && pivot != 0)
		q_sort(array, start, pivot - 1, size);
	if (pivot < size - 1)
		q_sort(array, pivot + 1, end, size);
}
/**
* quick_sort - Sorts an array of integers in ascending order
* @array: array to be sorted
* @size: size of array
* Return: void
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	if (size == 0 || size == 1)
		return;

	q_sort(array, 0, size - 1, size);
}
