#include "sort.h"

/**
 * merge_sort - sorts an array of ints using top-down merge sort algorithm
 * @array: array of integers to sort
 * @size: size of the array of integers to sort
 *
 */

void merge_sort(int *array, size_t size)
{
	int *holder = malloc(sizeof(int) * size);

	if (holder == NULL)
		return;
	if (size <= 1 || array == NULL)
	{
		free(holder);
		return;
	}
	merge_sort_holder(array, size, holder);
	free(holder);
}

/**
 * merge_sort_holder - sorts array of ints with top-down merge sort algorithm
 * and includes malloced holder array
 * @array: array of integers to sort
 * @size: size of the array of integers to sort
 * @holder: temp array to hold information during merge
 */

void merge_sort_holder(int *array, size_t size, int *holder)
{
	int mid = size / 2;

	if (size <= 1)
		return;

	merge_sort_holder(array, mid, holder);
	merge_sort_holder(&array[mid], size - mid, holder);
	merge(holder, array, mid, size);
}

/**
 * merge - merges two subarrays together
 * @holder: temp array to hold information during merge
 * @array: array to merge
 * @mid: index of mid-point
 * @size: size of array to merge
 *
 */

void merge(int *holder, int *array, int mid, size_t size)
{
	int left = 0, right = mid, index = 0;

	printf("Merging...\n[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(&array[mid], size - mid);
	while (left < mid && right < (int)size)
	{
		if (array[left] <= array[right])
		{
			holder[index] = array[left];
			left++;
		}
		else
		{
			holder[index] = array[right];
			right++;
		}
		index++;
	}
	while (left < mid)
	{
		holder[index] = array[left];
		left++;
		index++;
	}
	while (right < (int)size)
	{
		holder[index] = array[right];
		right++;
		index++;
	}
	for (index = 0; index < (int)size; index++)
		array[index] = holder[index];
	printf("[Done]: ");
	print_array(array, size);
}
