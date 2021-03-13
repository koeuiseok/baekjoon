/**************************************************************
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 1010000)

출력
첫째 줄에 A+B를 출력한다.
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
	int ret;
	int i,j,k;
	int num, a,b;
	int carry=0;
	int flag;

	unsigned char A[10001] = { 0, };
	unsigned char B[10001] = { 0, };
	unsigned char result[10002] = { 0, };

	ret = scanf("%s %s", A, B);

	if (strlen(A) >= strlen(B)) {
		j = strlen(B);
		k = strlen(A);
		flag = 0;
	}
	else {
		j = strlen(A);
		k = strlen(B);
		flag = 1;
	}
	result[0] = 0;

	for (i = 0; i < j; i++) {
		a = A[strlen(A) - i-1] - '0';
		b = B[strlen(B) - i-1] - '0';


		num = (a + b + carry) % 10;
		result[k - i] = num;
		carry = (a + b + carry) / 10;
	}

	for (i = j; i < k; i++) {
		if (!flag) {
			a = A[strlen(A) - i - 1] - '0';
			b = 0;
		}
		else {
			a = 0;
			b = B[strlen(B) - i - 1] - '0';
		}

		num = (a + b+carry) % 10;
		result[k - i] = num;
		carry = (a + b+carry) / 10;
	}
	result[0] += carry;

	for (i = 0; i < k+1; i++)
	{
		if (result[i] != 0 || i != 0) {
			printf("%d", result[i]);
		}
	}


	return 0;
}

