/**************************************************************
문제
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.

예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.

입력
입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.

M과 N은 10,000이하의 자연수이며, M은 N보다 작거나 같다.

출력
M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다.

단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.
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
	int min, minus;

	ret = scanf("%d", &num1);
	ret = scanf("%d", &num2);

	minus = num2 - num1;
	min = num2;

	
	for (i = 0; i <= minus; i++)
	{	
		ret = isprime(num1+i);
		if (ret) {
			sum += (num1 + i);
			if (min > num1 + i) {
				min = num1 + i;
			}
		}

	}
	if (sum) {
		printf("%d\n%d", sum, min);
	}
	else {
		printf("-1");
	}
	return 0;
}

