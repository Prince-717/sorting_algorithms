#include "sort.h"

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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t space, i, j;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			while (j >= space && array[j - space] > array[j])
			{
				ints_swap(array + j, array + (j - space));
				j -= space;
			}
		}
		print_array(array, size);
	}
}
