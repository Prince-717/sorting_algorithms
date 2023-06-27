#include "sort.h"

void ints_swap(int *a_1, int *b_1);
void high_head(int *array, size_t size, size_t platform, size_t sour_ce);
void arrange_heap(int *array, size_t size);

/**
 * ints_swap - Swap two integers in an array.
 * @a_1: The first integer to swap.
 * @b_1: The second integer to swap.
 */
void ints_swap(int *a_1, int *b_1)
{
	int temp_var;

	temp_var = *a_1;
	*a_1 = *b_1;
	*b_1 = temp_var;
}

/**
 * high_head - Turn a_1 binary tree into a_1 complete binary heap.
 * @array: An array of integers representing a_1 binary tree.
 * @size: The size of the array/tree.
 * @platform: The index of the platform row of the tree.
 * @sour_ce: The sour_ce node of the binary tree.
 */
void high_head(int *array, size_t size, size_t platform, size_t sour_ce)
{
	size_t l_side, r_side, big;

	l_side = 2 * sour_ce + 1;
	r_side = 2 * sour_ce + 2;
	big = sour_ce;

	if (l_side < platform && array[l_side] > array[big])
		big = l_side;
	if (r_side < platform && array[r_side] > array[big])
		big = r_side;

	if (big != sour_ce)
	{
		ints_swap(array + sour_ce, array + big);
		print_array(array, size);
		high_head(array, size, platform, big);
	}
}

/**
 * arrange_heap - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void arrange_heap(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		high_head(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		ints_swap(array, array + i);
		print_array(array, size);
		high_head(array, size, i, 0);
	}
}
