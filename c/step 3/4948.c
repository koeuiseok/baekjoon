/**************************************************************
문제
베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.

이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.

예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)

자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 케이스는 n을 포함하는 한 줄로 이루어져 있다.

입력의 마지막에는 0이 주어진다.

출력
각 테스트 케이스에 대해서, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력한다.

제한
1 ≤ n ≤ 123,456
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int primeArray[62000];

int isprime(int x)
{
	if (x==0||x == 1) {
		return 0;
	}

	for (int i = 2; i <= sqrt(x); i++)
	{
		if (i != 2 && i % 2 == 0) {
			continue;
		}

		if (x % i == 0) {
			return 0;
		}
		
	}

	return 1;
}

int main()
{
	int ret;
	int i, x;
	int num;
	int cnt =0;
	int first = 0;
	int second = 0;

	for (i = 2; i <= 2*123456; i++) {
		ret = isprime(i);
		if (ret) {
			primeArray[cnt] = i;
			cnt++;
		}
	}


	while (1) {
		ret = scanf("%d", &num);
		if (!num) {
			return 0;
		}
		else if (num==1) {
			printf("1\n");
			continue;
		}
		else {
			for (i = 0; i < cnt; i++) {
				if (primeArray[i] > num) {
					break;
				}
				first = i;
			}
			for (i = 0; i < cnt; i++) {
				
				if (primeArray[i] > 2 * num) {
					break;
				}
				second = i;
			}
		}
		printf("%d\n", (second - first));
	}
	

	return 0;
}

