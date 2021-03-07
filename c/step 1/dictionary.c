
/**********************************************************************************
* 제목 : 단어장 만들기
* 기능 : 입력 받은 단어를 단어장에 저장한다. 
* 세부 기능 : 중복된 단어는 저장하지 않는다. 일정 길이 이하는 저장하지 않는다.
* 입력 :  첫째 줄에는 단어의 개수와 단어의 길이 기준이 공백으로 구분되어 주어짐 
* 입력 :  둘째 줄부터 ~ 단어를 입력 받는다.
**********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int overlap[10];

int addstr(char** array, char* str, int arrLen)
{
	int sameFlag = 1;
	printf("%d번째, %s문장 입력\n", arrLen, str);

	if (arrLen == 0) {
		goto add;
	}

	for (int i = 0; i < arrLen; i++) {
		sameFlag = strncmp(array[i], str,10);
		printf("%d번째 %d flag, array : %s, str : %s\n", i, sameFlag, array[i], str);
		if (!sameFlag) {
			goto skip;
		}
	}
add:
	strcpy(array[arrLen], str);
	printf("+%s\n", array[arrLen]);
	return arrLen +1;

skip:
	printf("중복\n");
	overlap[arrLen] += 1;
	return arrLen;
}


int main(void)
{
	int cnt_i, cnt;
	int num, len;
	char** arr;
	int ret;
	char temp[10] = { 0, };
	int strLen;

	memset(overlap, 0, 10);

	ret = scanf("%d %d", &num, &len);
	if (num < 1 || num >100000)
	{
		printf("num : error\n");
		return -1;
	}
	else if (len < 1 || len>10)
	{
		printf("len : error\n");
		return -1;
	}

	arr = (char**)malloc(sizeof(char*) * num);
	arr[0] = (char*)malloc(sizeof(char) * 10);
	for (cnt_i = 1; cnt_i < num; cnt_i++)
	{
		arr[cnt_i] = arr[cnt_i - 1] + 10;
	}

	cnt = 0;
	for (cnt_i = 0; cnt_i < num; cnt_i++)
	{
		ret = scanf("%s",temp);
		strLen = strlen(temp);
		if (strLen > 10) {
			printf("too long : %s\n", temp);
			return -1;
		}
		else if (strLen >= len) {
			cnt = addstr(arr, temp, cnt);
		}
	}

	for (cnt_i = 0; cnt_i < cnt; cnt_i++)
	{
		printf("%s\n", arr[cnt_i]);
	}
	
	free(arr[0]);
	free(arr);

	return 0;
}