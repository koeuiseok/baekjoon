/*

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num, i, x1,y1,x2,y2,r1,r2;
	double d, r;
	cin >> num;
	
	for (i = 0; i < num; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		r = (r1 > r2) ? r2 : r1;
		
		if(r1==0|| r2==0){
			if (x1 == x2&&y1==y2) {
				cout << "-1" << endl;
			}
			else {
				cout << "0" << endl;
			}
			continue;
		}
		
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				cout << "-1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (d > r1+r2 || d <r) {
			cout << "0" << endl;
		}
		else if (d < r1 + r2 && d>r) {
			cout << "2" << endl;
		}
		else if (d == r|| d==r1+r2) {
			if (d == r1 && d == r2) {
				cout << "2" << endl;
				continue;
			}

			cout << "1" << endl;
		}
		

	}

	return 0;
}
