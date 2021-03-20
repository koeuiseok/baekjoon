#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

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

int answer[2];

int goldbach(int num)
{
	unsigned int iTemp;
	int ret;
	answer[0] = 0; answer[1] = 0;
	for (unsigned int i = 0; i < prime.size(); i++) {
		iTemp = num - prime.at(i);
		if (iTemp <= 0) {
			return 0;
		}
		ret = isprime(iTemp);
		if (ret) {
			answer[0] = prime.at(i);
			answer[1] = iTemp;
			return 0;
		}
	}
	
	return 0;
}


int main()
{

	unsigned int i, iTemp, idx, iInput;
	
	make_prime();

	cin >> iInput;
	for (i = 0; i < iInput; i++) {
		cin >> idx;
		goldbach(idx);
		cout << answer[0] << " " << answer[1] << endl;
	}

	return 0;
}
