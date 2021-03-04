
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

#define case_c 1
#define case_d 2
#define case_l 3
#define case_n 4
#define case_s 5
#define case_z 6

int main()
{
	int ret;
	char a[101];

	int count = 0;
	int sum = 0;
	int flag = 0;

	ret = scanf("%s", a);

	for (int i = 0; i < strlen(a); i++)
	{
		if (flag>0 &&(a[i]=='=')) {
			count++;
			flag = 0;
			continue;
		}
		else if (a[i - 2] == 'd' && flag == case_z && a[i] != '-' && a[i]!='\n') {
			count++; count++;
			flag = 0;
		}
		else if (flag>0 && (a[i] == '-')) {
			count++;

			flag = 0;
			continue;
		}
		else if (flag == case_d && a[i] == 'z')
		{
			flag = case_z;
			continue;
		}

		else if (flag == case_l || flag == case_n) {
			if (a[i] == 'j') {
				count++;
				flag = 0;
				continue;
			}
			else {
				count++;
				flag = 0;
			}
		}
		
		if (flag>0) {
			flag = 0;
			count++;
		}

		if (a[i] == '\n') {
			goto end;
		}

		switch (a[i]) {
			case 'c':
				flag = case_c;
				break;
			case 'd':
				flag = case_d;
				break;
			case 'l': 
				flag = case_l;
				break;
			case 'n': 
				flag = case_n;
				break; 
			case 's': 
				flag = case_s;
				break; 
			case 'z':
				flag = case_z;
				break;
			default:
				count++;
				flag = 0;
				break;
		}
	}
end:
	printf("%d", count);

	return 0;
}
