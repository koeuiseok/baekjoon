
/**************************************************************
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int alphabet[26] = { 0, };

int main()
{
	int ret,i, temp, max_cnt;
	int num = 0;
	char input;
	int cnt = 1000002;
	int max = -1;
	int flag = 0;

	while (cnt) {
		ret = scanf("%c", &input);
		if (input == '\n') {
			break;
		}
		else if ((int)input < (int)'a') {
			temp = (int)input - (int)'A';
		}
		else {
			temp = (int)input - (int)'a';
		}
		if (temp < 26 && temp>=0) {
			alphabet[temp]++;
		}
		cnt--;
	}

	for (i = 0; i < 26; i++)
	{
		if (max < alphabet[i]) {
			flag = 0;
			max = alphabet[i];
			max_cnt = i;
		}
		else if (max == alphabet[i]) {
			flag = 1;
		}
	}

	if (flag==0) {
		input = (char)(max_cnt + (int)'A');
		printf("%c",input);
	}
	else {
		printf("?");
	}

	return 0;
}


