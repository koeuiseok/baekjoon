/**************************************************************
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.
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
	int num, x;
	int sum = 0;

	ret = scanf("%d", &num);
	
	for (i = 0; i < num; i++)
	{
		(void)scanf("%d", &x);
		ret = isprime(x);
		sum += ret;
	}

	printf("%d", sum);

	return 0;
}

