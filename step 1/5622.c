
/**************************************************************
문제
상근이의 동생 상수는 수학을 정말 못한다. 상수는 숫자를 읽는데 문제가 있다. 이렇게 수학을 못하는 상수를 위해서 상근이는 수의 크기를 비교하는 문제를 내주었다. 상근이는 세 자리 수 두 개를 칠판에 써주었다. 그 다음에 크기가 큰 수를 말해보라고 했다.

상수는 수를 다른 사람과 다르게 거꾸로 읽는다. 예를 들어, 734와 893을 칠판에 적었다면, 상수는 이 수를 437과 398로 읽는다. 따라서, 상수는 두 수중 큰 수인 437을 큰 수라고 말할 것이다.

두 수가 주어졌을 때, 상수의 대답을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 칠판에 적은 두 수 A와 B가 주어진다. 두 수는 같지 않은 세 자리 수이며, 0이 포함되어 있지 않다.

출력
첫째 줄에 상수의 대답을 출력한다.
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int ret;
	char a[16];

	int count = 0;
	int sum = 0;


	ret = scanf("%s", a);

	for (int i = 0; i < strlen(a); i++)
	{
		switch (a[i]) {
			case 'A': case 'B': case 'C':
				count = 3;
				break;
			case 'D': case 'E': case 'F':
				count = 4;
				break;		
			case 'G': case 'H': case 'I':
				count = 5;
				break;
			case 'J': case 'K': case 'L':
				count = 6;
				break;
			case 'M': case 'N': case 'O':
				count = 7;
				break;
			case 'P': case 'Q': case 'R': case 'S':
				count = 8;
				break;	
			case 'T': case 'U': case 'V':
				count = 9;
				break;
			case 'W': case 'X': case 'Y':case 'Z':
				count = 10;
				break;
			default:
				break;
		}
		sum += count;
	}

	printf("%d", sum);

	return 0;
}

