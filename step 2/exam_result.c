
/**************************************************************
* (변형) 4344번 평균은 넘겠지
*입력
* 첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
* 둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
*
*출력
* 전체 평균을 넘는 학생들이 줄마다 얼만큼 있는지 반올림하여 소수점 셋째 자리까지 출력한다.
* 
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int caseNum = 0;
	int caseLen = 0;
	int ret,i,cnt_i, tmp;
	char** array;
	int sum = 0;
	int num = 0;
	float avg, per;
	int cnt=0;


	ret = scanf("%d", &caseNum);
	array = (char**)malloc(sizeof(char*) * caseNum);
	for (i = 0; i < caseNum; i++)
	{
		ret = scanf("%d",&caseLen);
		array[i] = (char*)malloc(sizeof(char) * caseLen);
		num += caseLen;
		for (cnt_i = 0; cnt_i < caseLen; cnt_i++)
		{
			ret = scanf("%d", &tmp);
			array[i][cnt_i] = tmp;
			sum += tmp;
		}

	}
	avg = (float)sum / (float)num;
	printf("avg : %f, sum : %d, num : %d\n", avg,sum, num);
	
	for (i = 0; i < caseNum; i++)
	{
		caseLen = strlen(array[i]);
		cnt=0;
		for (cnt_i = 0; cnt_i < caseLen; cnt_i++)
		{

			if ((int)avg < array[i][cnt_i]) {
				cnt++;
			}
		}
		
		per = (float)cnt / (float)caseLen;
		per *= 100;
		printf("%3.3f\%\n", per);
	}

	for (i = 0; i < caseNum; i++)
	{
		free(array[i]);
	}
	free(array);
	return 0;
}
