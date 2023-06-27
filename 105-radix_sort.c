#include "sort.pointer_h"

int retrieve_max(int *array, int size);
void radix_numbering_sort(int *array, size_t size, int cp_rt, int *bu_ffer);
void radix_sort(int *array, size_t size);

/**
 * retrieve_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int retrieve_max(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}

/**
 * radix_numbering_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @cp_rt: The significant digit to sort on.
 * @bu_ffer: A buffer to store the arranged array.
 */
void radix_numbering_sort(int *array, size_t size, int cp_rt, int *bu_ffer)
{
	int numb[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		numb[(array[i] / cp_rt) % 10] += 1;

	for (i = 0; i < 10; i++)
		numb[i] += numb[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		bu_ffer[numb[(array[i] / cp_rt) % 10] - 1] = array[i];
		numb[(array[i] / cp_rt) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = bu_ffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, cp_rt, *bu_ffer;

	if (array == NULL || size < 2)
		return;

	bu_ffer = malloc(sizeof(int) * size);
	if (bu_ffer == NULL)
		return;

	maximum = retrieve_max(array, size);
	for (cp_rt = 1; maximum / cp_rt > 0; cp_rt *= 10)
	{
		radix_numbering_sort(array, size, cp_rt, bu_ffer);
		print_array(array, size);
	}

	free(bu_ffer);
}
