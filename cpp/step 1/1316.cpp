#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<cstring>

using namespace std;

unsigned char alpha[26];

int isgroup(string str)
{
	memset(alpha, 0, sizeof(alpha));
	int a,b;

	b = 0;
	for (int i = 0; i < str.size(); i++) {
		a = (int)str.at(i) - 'a';
		if (b != a && alpha[a] != 0) {
			return -1;
		}
		alpha[a]++;
		b = a;
	}

	return 0;
}

int main()
{
	int num, ret;
	string str = "";
	int sum = 0;

	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		getline(cin, str);
		ret = isgroup(str);
		if (ret==0) {
			sum++;
		}
	}

	cout << sum;

	return 0;
}
