//벌집 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int deal_fnc(int num)
{
	int minus = 1;
	
	while (num>0) {
		num -= minus;
		minus++;
	}

	printf("%d", minus);

	return 0;
}

int main()
{
	int ret;
	unsigned int a, b;
	ret = scanf("%d", &a);

	if (a == 1) {
		printf("1");
		return 0;
	}
	else {
		b = (a+4) / 6;
		deal_fnc(b);
	}

	return 0;
}
