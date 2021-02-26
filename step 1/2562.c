#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b;
	int ret;
	int input[9] = { 0, };
	int cnt_i;
	int cnt=0;

	for (cnt_i = 0; cnt_i < 9; cnt_i++)
	{
		ret = scanf("%d",&input[cnt_i]);
		if (input[cnt] < input[cnt_i]) {
			input[cnt] = input[cnt_i];
			cnt = cnt_i;
		}
	}
	printf("%d\n%d", input[cnt], cnt+1);

	return 0;
}
