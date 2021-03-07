/**************************************************************
무한히 큰 배열에 다음과 같이 분수들이 적혀있다.

1/1	1/2	1/3	1/4	1/5	…
2/1	2/2	2/3	2/4	…	…
3/1	3/2	3/3	…	…	…
4/1	4/2	…	…	…	…
5/1	…	…	…	…	…
…	…	…	…	…	…

이와 같이 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.

출력
첫째 줄에 분수를 출력한다.
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int ret;
	int cnt_i, mom,son;
	int a,b, flag;
	

	ret = scanf("%d", &b);
	a = b;

	cnt_i = 1;
	while (a > 0)
	{
		a -= cnt_i;
		cnt_i++;
	}
	flag = cnt_i % 2;
	if (!flag) {
		mom = cnt_i+a-1;
		son = cnt_i - mom;
	}
	else {
		son = cnt_i + a - 1;
		mom = cnt_i - son;
	}


	printf("%d/%d", son, mom);

	return 0;
}

