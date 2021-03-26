/**************************************************************

**************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int ret;
	int tri1, tri2, tri3;
	int longsq, short1sq, short2sq;

	while (1)
	{
		ret = scanf("%d %d %d", &tri1, &tri2, &tri3);
		if ((tri1 | tri2 | tri3)==0) {
			break;
		}

		else if (tri1 > tri2 && tri1 > tri3) {
			longsq = tri1 * tri1;
			short1sq = tri2 * tri2;
			short2sq = tri3 * tri3;

			if (longsq == short1sq + short2sq) {
				printf("right\n");
			}
			else {
				printf("wrong\n");
			}
		}
		else if (tri2 > tri1 && tri2 > tri3) {
			longsq = tri2 * tri2;
			short1sq = tri1 * tri1;
			short2sq = tri3 * tri3;

			if (longsq == short1sq + short2sq) {
				printf("right\n");
			}
			else {
				printf("wrong\n");
			}
		}
		else if (tri3 > tri2 && tri3 > tri1) {
			longsq = tri3 * tri3;
			short1sq = tri2 * tri2;
			short2sq = tri1 * tri1;

			if (longsq == short1sq + short2sq) {
				printf("right\n");
			}
			else {
				printf("wrong\n");
			}
		}
		else {
			printf("wrong\n");
		}
	}

	return 0;
}
