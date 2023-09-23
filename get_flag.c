#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @k: take a parameter.
 * Return: Flag:
 */
int get_flags(const char *format, int *k)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_k;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_k = *k + 1; format[curr_k] != '\0'; curr_k++)
	{
		for (j = 0; FLAG_CH[j] != '\0'; j++)
			if (format[curr_k] == FLAG_CH[j])
			{
				flag |= FLAG_ARR[j];
				break;
			}

		if (FLAG_CH[j] == 0)
			break;
	}

	*k = curr_k - 1;

	return (flag);
}
