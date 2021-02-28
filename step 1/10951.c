#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
	int ret,i,num1,num2;
	int sum = 0;
	int a[10];
	char ch = 0;
	
	while (scanf("%d %d", &num1, &num2) != EOF) {
		sum = num1 + num2;
		printf("%d\n", sum);
	}
	return 0;
}
