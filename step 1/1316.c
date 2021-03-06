/**************************************************************
문제
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

출력
첫째 줄에 그룹 단어의 개수를 출력한다.
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int is_groupword(unsigned char* b)
{
	int cnt_i, tmp;
	int flag[26] = { 0, };

	for (cnt_i = 0; cnt_i < strlen(b); cnt_i++)
	{
		if (b[cnt_i] != b[cnt_i + 1]) {
			tmp = (int)b[cnt_i] - (int)'a';
			if (flag[tmp] == 0) {
				flag[tmp]++;
			}
			else {
				return -1;
			}
		}
	}

	return 0;
}

int main()
{
	int ret, i;
	int a;
	unsigned char b[100];
	int count=0;

	ret = scanf("%d", &a);
	
	for (i = 0; i < a; i++)
	{
		ret = scanf("%s", b);
		if (!is_groupword(b)) {
			count++;
		}
	}

	printf("%d", count);


	return 0;
}

