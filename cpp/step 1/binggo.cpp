#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

//console input output 헤더파일 콘솔창에서 입출력
#include <conio.h>

using namespace std;


int main()
{

	int i, iTemp, idx1, idx2, iInput;
	int iNumber[25] = {};
	srand((unsigned int)time(0));
	for (i = 0; i < 25; i++)
	{
		iNumber[i] = i + 1;
	}

	for (i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true)
	{
		system("cls");

		for (i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) {
				if (iNumber[5 * i + j] == INT_MAX) {

				}
				cout << iNumber[5 * i + j] << "\t";
			}
			cout << endl;
		}

		cout << "input Number( 0 : end) :";
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 0 || iInput >25) {
			cout << "error" << endl;
			continue;
		}

		for (i = 0; i < 25; i++) {
			if (iInput == iNumber[i]) {
				iNumber[i] = INT_MAX;
			}
		}

	}

	return 0;
}
