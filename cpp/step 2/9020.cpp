#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;



bool* Eratos(int n)
{
	bool* PrimeArray = new bool[n + 1];
	if (n <= 1) return PrimeArray;
	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;

	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}

	return PrimeArray;

}

int goldbach(int num, bool* ptr)
{
	unsigned int iTemp;
	int ret, i;

	i = num/2+1;
	for (; i >= 2; i--) {
		iTemp = num - i;
		if (ptr[iTemp] == true && ptr[i] == true) {
			if (iTemp >= i) {
				cout << i << " " << iTemp << endl;
			}
			else {
				cout << iTemp << " " << i << endl;
			}
			return 0;
		}
	}


	return 0;
}


int main()
{

	unsigned int i, iTemp, idx, iInput;
	bool* ptr;
	ptr = Eratos(10000);

	cin >> iInput;
	for (i = 0; i < iInput; i++) {
		cin >> idx;
		goldbach(idx, ptr);

	}

	return 0;
}
