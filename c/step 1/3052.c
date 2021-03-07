
/**************************************************************
*  문제
* 두 자연수 A와 B가 있을 때, A%B는 A를 B로 나눈 나머지 이다. 예를 들어, 7, 14, 27, 38을 3으로 나눈 나머지는 1, 2, 0, 2이다.
* 수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.
*
*  입력
* 첫째 줄부터 열번째 줄 까지 숫자가 한 줄에 하나씩 주어진다. 이 숫자는 1,000보다 작거나 같고, 음이 아닌 정수이다.
*
*  출력
* 첫째 줄에, 42로 나누었을 때, 서로 다른 나머지가 몇 개 있는지 출력한다.
**************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int jungbook(int* a, int i)
{
	for (int cnt_i = 0; cnt_i < i; cnt_i++)
	{
		if (a[i] == a[cnt_i]) {
			return -1;
		}
	}

	return 0;
}

int MOD42()
{
	int num,ret, i;
	int cnt = 0;
	
	ret = scanf("%d", &num);
	
	return num % 42;
}

int main()
{
	int i;
	int cnt = 0;
	int a[10];
	for (i = 0; i < 10; i++) {
		a[i] = MOD42();
		if (!jungbook(a,i)) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}

