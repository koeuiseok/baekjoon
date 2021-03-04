/**************************************************************
* 예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
*
* dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.
*
* 입력
*첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.
*
*단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.
*
* 출력
*입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int ret;
	char a[101];

	int count = 0;

	ret = scanf("%s", a);

	for (int i = 1; i < strlen(a); i++)
	{
		if (a[i - 1] == 'c' && a[i] == '-') {
			count++;
		}
		else if (a[i - 1] == 'c' && a[i] == '=') {
			count++;
		}
		else if (a[i - 1] == 'd' && a[i] == '-') {
			count++;
		}
		else if (a[i - 1] == 'l' && a[i] == 'j') {
			count++;
		}
		else if (a[i - 1] == 'n' && a[i] == 'j') {
			count++;
		}
		else if (a[i - 1] == 's' && a[i] == '=') {
			count++;
		}
		else if (a[i - 1] == 'z' && a[i] == '=') {
			count++;
		}

		if (i > 1) {
			if (a[i - 2] == 'd' && a[i - 1] == 'z' && a[i] == '=')
			{
				count++;
			}
		}

	}

	printf("%d", strlen(a) - count);

	return 0;
}
