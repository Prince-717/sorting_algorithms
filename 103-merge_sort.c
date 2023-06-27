#include "sort.pointer_h"

void sub_array_join(int *sub_array, int *bu_ffer, size_t first, size_t middle,
		size_t last_n);
void recursive_merge_sort(int *sub_array, int *bu_ffer, size_t first, size_t last_n);
void merge_sort(int *array, size_t size);

/**
 * sub_array_join - Sort a_1 subarray of integers.
 * @sub_array: A subarray of an array of integers to sort.
 * @bu_ffer: A buffer to store the arranged subarray.
 * @first: The first index of the array.
 * @middle: The middle index of the array.
 * @last_n: The last_n index of the array.
 */
void sub_array_join(int *sub_array, int *bu_ffer, size_t first, size_t middle,
		size_t last_n)
{
	size_t i, j, k = 0;

	printf("Merging...\n[l_side]: ");
	print_array(sub_array + first, middle - first);

	printf("[r_side]: ");
	print_array(sub_array + middle, last_n - middle);

	for (i = first, j = middle; i < middle && j < last_n; k++)
		bu_ffer[k] = (sub_array[i] < sub_array[j]) ? sub_array[i++] : sub_array[j++];
	for (; i < middle; i++)
		bu_ffer[k++] = sub_array[i];
	for (; j < last_n; j++)
		bu_ffer[k++] = sub_array[j];
	for (i = first, k = 0; i < last_n; i++)
		sub_array[i] = bu_ffer[k++];

	printf("[Done]: ");
	print_array(sub_array + first, last_n - first);
}

/**
 * recursive_merge_sort - Implement the merge sort algorithm through recursion.
 * @sub_array: A subarray of an array of integers to sort.
 * @bu_ffer: A buffer to store the arranged result.
 * @first: The first index of the subarray.
 * @last_n: The last_n index of the subarray.
 */
void recursive_merge_sort(int *sub_array, int *bu_ffer, size_t first, size_t last_n)
{
	size_t middle;

	if (last_n - first > 1)
	{
		middle = first + (last_n - first) / 2;
		recursive_merge_sort(sub_array, bu_ffer, first, middle);
		recursive_merge_sort(sub_array, bu_ffer, middle, last_n);
		sub_array_join(sub_array, bu_ffer, first, middle, last_n);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *bu_ffer;

	if (array == NULL || size < 2)
		return;

	bu_ffer = malloc(sizeof(int) * size);
	if (bu_ffer == NULL)
		return;

	recursive_merge_sort(array, bu_ffer, 0, size);

	free(bu_ffer);
}
