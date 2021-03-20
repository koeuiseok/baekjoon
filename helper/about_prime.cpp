#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

// 에라토스테네스의 체를 이용한 소수 판별
// 함수 : n이하의 소수를 찾는 함수
// 입력 : n
// 설명 : n까지 배열을 만든 뒤, 소수 여부에 따라 true, false를 입력함
void Eratos(int n)
{
	if (n <= 1) return;

	bool* PrimeArray = new bool[n + 1];


	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;

	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}

}

// 소수인지 판별하는 함수
// return 0이면, 합성수
// return 1이면, 소수
// 홀수로 나누는 방식
int isprime(unsigned int num)
{
	if (num == 2) {
		return 1;
	}

	if (num % 2 == 0) {
		return 0;
	}

	for (int i = 3; i <= sqrt(num); i += 2) {
		if ((num % i) == 0) {
			return 0;
		}
	}

	return 1;
}


// isprime함수를 이용해서 vector에 소수를 순서대로 채우는 형식 
vector<unsigned int> prime;
void make_prime()
{
	int ret;
	prime.push_back(2);
	for (int i = 3; i <= 10000; i+=2) {
		ret = isprime(i);
		if (ret) {
			prime.push_back(i);
		}
	}
}
