#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

//console input output 헤더파일 콘솔창에서 입출력
#include <conio.h>

using namespace std;


int main()
{
	srand((unsigned int)time(0));
	int idx1, idx2, temp;
	int iNumber[25];
	int star_place;
	bool flag = false;

	for (int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}
	iNumber[24] = INT_MAX;

	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		temp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = temp;
	}

	while (true)
	{
		system("cls");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) {
				if (iNumber[5 * i + j]==INT_MAX) {
					cout << "*\t";
					star_place = 5*i+j;
				}
				else {
					cout << iNumber[5 * i + j] << "\t";
				}
			}
			cout << endl;
		}

		cout << "w : 위 s : 아래 a :왼쪽 d : 오른쪽 q : 종료" << endl;
		char cinput = _getch();  // _getch 문자 1개 받자마자 반환하고 종료 엔터 없어도 됨
		
		if (cinput == 'q' || cinput == 'Q')
			break;
	
		switch (cinput)
		{
		case 'W':
		case 'w':
			if (star_place >= 5) {
				iNumber[star_place] = iNumber[star_place-5];
				star_place -= 5;
				iNumber[star_place] = INT_MAX;
			}
			break;
		case 's':
		case 'S':
			if (star_place < 20) {
				iNumber[star_place] = iNumber[star_place + 5];
				star_place += 5;
				iNumber[star_place] = INT_MAX;
			}
			break;
		case 'a':
		case 'A':
			if (star_place > 0) {
				iNumber[star_place] = iNumber[star_place -1];
				star_place -= 1;
				iNumber[star_place] = INT_MAX;
			}
			break;

		case 'd':
		case 'D':
			if (star_place < 24) {
				iNumber[star_place] = iNumber[star_place + 1];
				star_place += 1;
				iNumber[star_place] = INT_MAX;
			}
			break;
		case 'p':
			flag = true;
			goto eastEgg;
			break;
		}

		for (int w = 0; w < 24; w++) {
			if (iNumber[w] != w + 1) {
				flag = false;
				break;
			}
			else if (w == 23) {
				flag == true;
			}
		}
eastEgg:
		if (flag == true) {
			cout << "mission complete!" << endl;
			break;
		}

	}

	cout << "game is over" << endl;

	return 0;
}
