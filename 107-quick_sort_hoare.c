#include "sort.h"

void ints_swap(int *a_1, int *b_1);
int hoare_division(int *array, size_t size, int l_side, int r_side);
void hoare_arrange(int *array, size_t size, int l_side, int r_side);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_division - Order a_1 subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @l_side: The starting index of the subset to order.
 * @r_side: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the fulcrum.
 * Prints the array after each swap of two elements.
 */
int hoare_division(int *array, size_t size, int l_side, int r_side)
{
	int fulcrum, ontop, downside;

	fulcrum = array[r_side];
	for (ontop = l_side - 1, downside = r_side + 1; ontop < downside;)
	{
		do {
			ontop++;
		} while (array[ontop] < fulcrum);
		do {
			downside--;
		} while (array[downside] > fulcrum);

		if (ontop < downside)
		{
			ints_swap(array + ontop, array + downside);
			print_array(array, size);
		}
	}

	return (ontop);
}

/**
 * hoare_arrange - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @l_side: The starting index of the array partition to order.
 * @r_side: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_arrange(int *array, size_t size, int l_side, int r_side)
{
	int portion;

	if (r_side - l_side > 0)
	{
		portion = hoare_division(array, size, l_side, r_side);
		hoare_arrange(array, size, l_side, portion - 1);
		hoare_arrange(array, size, portion, r_side);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_arrange(array, size, 0, size - 1);
}
