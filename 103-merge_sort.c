#include "sort.h"

/**
* merge - merges
* @a: array to be sorted
* @n: size of array
* @m: merge
*
* Return: void
*/

void merge(int *a, int n, int m)
{
	int i, j, y;
	int *k = malloc(n * sizeof(int));

	for (i = 0, j = m, y = 0; y < n; y++)
	{
		k[y] = j == n      ? a[i++]
			: i == m      ? a[j++]
			: a[j] < a[i] ? a[j++]
			:               a[i++];
	}
	for (i = 0; i < n; i++)
	{
		a[i] = k[i];
	}
	free(k);
}

/**
* merge_sort - sorts an array of integers in ascending order
*               using the merge sort algorithm
* @array: array of integers
* @size: size of array
*
* Return: void
*/

void merge_sort(int *array, size_t size)
{
	int merg;

	if ((int)size < 2)
		return;
	m = (int)size / 2;
	merge_sort(array, merg);
	merge_sort(array + merg, (int)size - merg);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, size);
	printf("[right]: ");
	print_array(array, size);
	merge(array, (int)size, merg);
	printf("[Done]: ");
	print_array(array, size);
}
