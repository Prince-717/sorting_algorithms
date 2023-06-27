#include "sort.h"

void ints_swap(int *a_1, int *b_1);
void biotonic_join(int *array, size_t size, size_t begin, size_t sequence,
		char pro_cess);
void bitonic_sequence(int *array, size_t size, size_t begin, size_t sequence, char pro_cess);
void bitonic_sort(int *array, size_t size);

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
 * biotonic_join - Sort a_1 bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @begin: The starting index of the sequence in array to sort.
 * @sequence: The size of the sequence to sort.
 * @pro_cess: The direction to sort in.
 */
void biotonic_join(int *array, size_t size, size_t begin, size_t sequence,
		char pro_cess)
{
	size_t i, hop = sequence / 2;

	if (sequence > 1)
	{
		for (i = begin; i < begin + hop; i++)
		{
			if ((pro_cess == UP && array[i] > array[i + hop]) ||
			    (pro_cess == DOWN && array[i] < array[i + hop]))
				ints_swap(array + i, array + i + hop);
		}
		biotonic_join(array, size, begin, hop, pro_cess);
		biotonic_join(array, size, begin + hop, hop, pro_cess);
	}
}

/**
 * bitonic_sequence - Convert an array of integers into a_1 bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @begin: The starting index of a_1 block of the building bitonic sequence.
 * @sequence: The size of a_1 block of the building bitonic sequence.
 * @pro_cess: The direction to sort the bitonic sequence block in.
 */
void bitonic_sequence(int *array, size_t size, size_t begin, size_t sequence, char pro_cess)
{
	size_t trim = sequence / 2;
	char *str = (pro_cess == UP) ? "UP" : "DOWN";

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + begin, sequence);

		bitonic_sequence(array, size, begin, trim, UP);
		bitonic_sequence(array, size, begin + trim, trim, DOWN);
		biotonic_join(array, size, begin, sequence, pro_cess);

		printf("Result [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + begin, sequence);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);
}
