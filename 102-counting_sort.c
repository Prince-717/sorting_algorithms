#include "sort.h"

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
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *numb, *arranged, maximum, i;

	if (array == NULL || size < 2)
		return;

	arranged = malloc(sizeof(int) * size);
	if (arranged == NULL)
		return;
	maximum = retrieve_max(array, size);
	numb = malloc(sizeof(int) * (maximum + 1));
	if (numb == NULL)
	{
		free(arranged);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		numb[i] = 0;
	for (i = 0; i < (int)size; i++)
		numb[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		numb[i] += numb[i - 1];
	print_array(numb, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		arranged[numb[array[i]] - 1] = array[i];
		numb[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = arranged[i];

	free(arranged);
	free(numb);
}
