#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int input, n, prime[10001] = { 0, };
	prime[0] = prime[1] = 0;

	for (int i = 2; i * i <= 10000; i++){
		for (int j = i; j * i <= 10000; j++) {
			if (prime[j * i] == 0)
				prime[j * i] = 1;
		}
	}
	(void)scanf("%d", &input);
	while (input--) {
		(void)scanf("%d", &n);
		for (int i = n / 2; i <= n; i++) {
			if (prime[i] == 0 && prime[n - i] == 0) {
				printf("%d %d\n", n - i, i);
				break;
			}
		}
	}

	return 0;
}
