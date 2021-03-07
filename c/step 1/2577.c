
/**************************************************************
문제
세 개의 자연수 A, B, C가 주어질 때 A × B × C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.

예를 들어 A = 150, B = 266, C = 427 이라면 A × B × C = 150 × 266 × 427 = 17037300 이 되고, 계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.

입력
첫째 줄에 A, 둘째 줄에 B, 셋째 줄에 C가 주어진다. A, B, C는 모두 100보다 같거나 크고, 1,000보다 작은 자연수이다.

출력
첫째 줄에는 A × B × C의 결과에 0 이 몇 번 쓰였는지 출력한다. 마찬가지로 둘째 줄부터 열 번째 줄까지 A × B × C의 결과에 1부터 9까지의 숫자가 각각 몇 번 쓰였는지 차례로 한 줄에 하나씩 출력한다.
**************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int count[10];

void deal_fnc(int num)
{
	switch (num) {
	case 0:
		count[0]++;
		break;
	case 1:
		count[1]++;
		break;
	case 2:
		count[2]++;
		break;
	case 3:
		count[3]++;
		break;
	case 4:
		count[4]++;
		break;
	case 5:
		count[5]++;
		break;
	case 6:
		count[6]++;
		break;
	case 7:
		count[7]++;
		break;
	case 8:
		count[8]++;
		break;
	case 9:
		count[9]++;
		break;
	}
}


int countNum(int num)
{
	int ret, i, mod;
	int cnt = 0;
	
	while (1) {
		if (num < 10) {
			deal_fnc(num);
			return 0;
		}

		mod = num % 10;
		deal_fnc(mod);
		num = num / 10;
		
	}

}

int main()
{
	int ret,i,num1,num2,num3;
	int cnt = 0;
	int a[10];
	
	ret = scanf("%d", &num1);
	ret = scanf("%d", &num2);
	ret = scanf("%d", &num3);

	num1 = num1 * num2 * num3;

	ret = countNum(num1);

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", count[i]);
	}

	return 0;
}

