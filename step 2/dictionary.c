
/**********************************************************************************
* ���� : �ܾ��� �����
* ��� : �Է� ���� �ܾ �ܾ��忡 �����Ѵ�. 
* ���� ��� : �ߺ��� �ܾ�� �������� �ʴ´�. ���� ���� ���ϴ� �������� �ʴ´�.
* �Է� :  ù° �ٿ��� �ܾ��� ������ �ܾ��� ���� ������ �������� ���еǾ� �־��� 
* �Է� :  ��° �ٺ��� ~ �ܾ �Է� �޴´�.
**********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int overlap[10];

int addstr(char** array, char* str, int arrLen)
{
	int sameFlag = 1;
	printf("%d��°, %s���� �Է�\n", arrLen, str);

	if (arrLen == 0) {
		goto add;
	}

	for (int i = 0; i < arrLen; i++) {
		sameFlag = strncmp(array[i], str,10);
		printf("%d��° %d flag, array : %s, str : %s\n", i, sameFlag, array[i], str);
		if (!sameFlag) {
			goto skip;
		}
	}
add:
	strcpy(array[arrLen], str);
	printf("+%s\n", array[arrLen]);
	return arrLen +1;

skip:
	printf("�ߺ�\n");
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