#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b;
	int ret;
	int input;
	int max;
	int min;
	int *array;

	ret = scanf("%d", &input);
	if (input < 1 || input >1000000)
	{
		printf("error");
		return -1;
	}
	array = malloc(sizeof(int) * input);

	ret = scanf("%d", &array[0]);
	max = array[0];
	min = array[0];
	for (int i = 0; i < input-1; i++)
	{
		ret = scanf("%d", &array[i]);
		if (max < array[i]) {
			max = array[i];
		}
		else if (min > array[i]){
			min = array[i];
		}
	}

	printf("%d %d", min, max);
	free(array);
	return 0;
}