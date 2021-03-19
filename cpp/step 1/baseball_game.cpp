#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


int main()
{
	int first = rand() % 10;
	int second = rand() % 10;
	int last = rand() % 10;

	int player1, player2, player3;
	int cnt = 1;
	int strike, ball;


	while (1) {
		strike = 0; ball = 0;

		cout << cnt<< " round" << endl;
		cnt++;

		cin >> player1 >> player2 >> player3;

		if (player1 == first) {
			strike++;
		}
		else if (player1 == second){
			ball++;
		}
		else if (player1 == last) {
			ball++;
		}
		
		if (player2 == second ) {
			strike++;
		}
		else if (player2 == first) {
			ball++;
		}
		else if (player2 == last) {
			ball++;
		}
		
		if (player3 == last ) {
			strike++;
		}
		else if (player3 == second) {
			ball++;
		}
		else if (player3 == first) {
			ball++;
		}
		cout << strike << "strike " << ball << "ball" << endl;

		if (strike == 3) {
			break;
		}
	}

	return 0;
}
