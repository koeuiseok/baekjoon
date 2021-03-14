/**************************************************************
문제
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

출력
N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다. N이 1인 경우 아무것도 출력하지 않는다.
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int factorize(int x)
{
	
	for (int i = 2; i <= x; i++)
	{
		if (x % i == 0) {
			x = x / i;
			printf("%d\n", i);
			i--;
		}
	}

	return 0;
}

int main()
{
	int ret;
	int i;
	int num;
	int sum = 0;
	int min, minus;

	ret = scanf("%d", &num);

	factorize(num);

	return 0;
}

