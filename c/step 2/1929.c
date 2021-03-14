/**************************************************************
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isprime(int x)
{
	if (x==0||x == 1) {
		return 0;
	}

	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0) {
			return 0;
		}
		
	}

	return 1;
}

int main()
{
	int ret;
	int i;
	int num1, num2, x;
	int sum = 0;
	int minus;

	ret = scanf("%d %d", &num1, &num2);

	minus = num2 - num1;
	
	for (i = 0; i <= minus; i++)
	{	
		ret = isprime(num1+i);
		if (ret) {
			printf("%d\n", num1 + i);
		}
	}
	
	return 0;
}

