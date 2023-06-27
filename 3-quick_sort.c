#include "sort.pointer_h"

void ints_swap(int *a_1, int *b_1);
int l_division(int *array, size_t size, int l_side, int r_side);
void l_sort(int *array, size_t size, int l_side, int r_side);
void fast_sort(int *array, size_t size);

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
 * l_division - Order a_1 subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @l_side: The starting index of the subset to order.
 * @r_side: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int l_division(int *array, size_t size, int l_side, int r_side)
{
	int *pivot, above, below;

	pivot = array + r_side;
	for (above = below = l_side; below < r_side; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				ints_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		ints_swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * l_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @l_side: The starting index of the array partition to order.
 * @r_side: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void l_sort(int *array, size_t size, int l_side, int r_side)
{
	int part;

	if (r_side - l_side > 0)
	{
		part = l_division(array, size, l_side, r_side);
		l_sort(array, size, l_side, part - 1);
		l_sort(array, size, part + 1, r_side);
	}
}

/**
 * fast_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void fast_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	l_sort(array, size, 0, size - 1);
}
