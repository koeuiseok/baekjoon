
/**************************************************************
* 4344번 평균은 넘겠지
*  입력
* 첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
* 둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
*
*  출력
* 줄 평균을 넘는 학생들이 줄마다 얼만큼 있는지 반올림하여 소수점 셋째 자리까지 출력한다.
* 
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct _linedata
{
	int* lineScore;
	int overCount;
	int sum;
	int num;
	float avg;
}LineData;

int per_line(LineData* ld)
{
	int cnt = 0;
	float per;
	for (int cnt_i = 0; cnt_i < ld->num; cnt_i++)
	{
		if (ld->avg < (ld->lineScore[cnt_i]))
			cnt++;
	}
	per = (float)cnt / (float)ld->num;
	per *= 10000;
	cnt = floor(per);
	per = per/100;
	printf("%.3f%%\n", per);

	return 0;
}

int avg_line()
{
	int ret, cnt_i;
	int cnt = 0;
	
	LineData* ld = malloc(sizeof(LineData));
	ret = scanf("%d", &ld->num);
	ld->lineScore = (int*)malloc(sizeof(int) * ld->num);
	if (ld->lineScore == NULL)
		return -1;
	ld->sum = 0;
	for (cnt_i = 0; cnt_i < ld->num; cnt_i++)
	{
		ret = scanf("%d", &ld->lineScore[cnt_i]);
		ld->sum += ld->lineScore[cnt_i];
	}
	ld->avg = (float)ld->sum / (float)ld->num;

	ret = per_line(ld);
	
	free(ld->lineScore);
	free(ld);
	return 0;
}


int main()
{
	int ret, i;
	int lineNum;

	ret = scanf("%d", &lineNum);
	for (i = 0; i < lineNum; i++)
	{
		ret = avg_line();
	}

	return 0;
}

