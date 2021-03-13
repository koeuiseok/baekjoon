/**************************************************************
문제
우주선은 그 크기와 질량이 엄청난 이유로 최신기술력을 총 동원하여 개발한 공간이동 장치를 탑재하였다. 하지만 이 공간이동 장치는 이동 거리를 급격하게 늘릴 경우 기계에 심각한 결함이 발생하는 단점이 있어서, 이전 작동시기에 k광년을 이동하였을 때는 k-1 , k 혹은 k+1 광년만을 다시 이동할 수 있다. 예를 들어, 이 장치를 처음 작동시킬 경우 -1 , 0 , 1 광년을 이론상 이동할 수 있으나 사실상 음수 혹은 0 거리만큼의 이동은 의미가 없으므로 1 광년을 이동할 수 있으며, 그 다음에는 0 , 1 , 2 광년을 이동할 수 있는 것이다. ( 여기서 다시 2광년을 이동한다면 다음 시기엔 1, 2, 3 광년을 이동할 수 있다. )

김우현은 공간이동 장치 작동시의 에너지 소모가 크다는 점을 잘 알고 있기 때문에 x지점에서 y지점을 향해 최소한의 작동 횟수로 이동하려 한다. 하지만 y지점에 도착해서도 공간 이동장치의 안전성을 위하여 y지점에 도착하기 바로 직전의 이동거리는 반드시 1광년으로 하려 한다.

김우현을 위해 x지점부터 정확히 y지점으로 이동하는데 필요한 공간 이동 장치 작동 횟수의 최솟값을 구하는 프로그램을 작성하라.

입력
입력의 첫 줄에는 테스트케이스의 개수 T가 주어진다. 각각의 테스트 케이스에 대해 현재 위치 x 와 목표 위치 y 가 정수로 주어지며, x는 항상 y보다 작은 값을 갖는다. (0 ≤ x < y < 231)

출력
각 테스트 케이스에 대해 x지점으로부터 y지점까지 정확히 도달하는데 필요한 최소한의 공간이동 장치 작동 횟수를 출력한다.
**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int low_dist(unsigned int x, unsigned int y)
{
	unsigned int dist;
	int cnt,buf, extra;
	int i = 1;
	int j = 1;


	dist = y - x;

	if (dist == 1) {
		printf("1\n");
		return 0;
	}
	else if (dist == 2) {
		printf("2\n");
		return 0;
	}
	else if (dist == 3) {
		printf("3\n");
		return 0;
	}

	while (i <= dist)
	{
		if (dist < i * 2) {
			break;
		}
		else if (dist == 2 * i ) {
			printf("%d\n", j*2);
			return 0;
		}
		j++;
		i+=j;

	}
	i -= j;
	j--;
	extra = dist - (2 * i);
	cnt = 2*j;
	for (int w = j+1; w >= 1; w--)
	{
		
		buf = extra / w;
		extra -= buf * w;
		cnt += buf;
		if (extra == 0) {
			break;
		}
	}

	printf("%d\n", cnt);

	return 0;

}

int main()
{
	int ret;
	unsigned int i;
	unsigned int num, x,y;

	ret = scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		ret = scanf("%d %d", &x, &y);
		low_dist(x,y);
	}

	return 0;
}

