#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <memory.h>

using namespace std;

#define PI 3.14159265359
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "A-large-practice"

typedef long long ll;

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	int T;
	cin >> T;
	REP(t,T)
	{
		int N, K;
		string board[54];
		cin >> N >> K;
		REP(i,N)
		{
			cin >> board[i];
		}
		REP(i,N)
		{
			int p = N - 1;
			for (int j = N - 1; j >= 0; j--) {
				if (board[i][j] != '.') {
					swap(board[i][j], board[i][p]);
					p--;
				}
			}
		}
		bool rwin = 0, bwin = 0;
		REP(i,N)
		{
			int r = 0, b = 0;
			REP(j,N)
			{
				if ((r > 0 && board[i][j] != 'R')
						|| (b > 0 && board[i][j] != 'B')) {
					r = 0;
					b = 0;
				}
				if (board[i][j] == 'R')
					r++;
				 if (board[i][j] == 'B')
					b++;
				if (r == K)
					rwin = 1;
				if (b == K)
					bwin = 1;
			}
		}
		//horzon
		REP(i,N)
		{
			int r = 0, b = 0;
			REP(j,N)
			{
				if ((r > 0 && board[j][i] != 'R')
						|| (b > 0 && board[j][i] != 'B')) {
					r = 0;
					b = 0;
				}  if (board[j][i] == 'R')
					r++;
				 if (board[j][i] == 'B')
					b++;
				if (r == K)
					rwin = 1;
				if (b == K)
					bwin = 1;
			}
		}
		//vertical
		REP(i,N)
		{
			int r = 0, b = 0;
			for (int j1 = 0, j2 = i; j1 < N && j2 < N; j1++, j2++) {

					if ((r > 0 && board[j1][j2] != 'R')
							|| (b > 0 && board[j1][j2] != 'B')) {
						r = 0;
						b = 0;
					}  if (board[j1][j2] == 'R')
						r++;
					 if (board[j1][j2] == 'B')
						b++;
					if (r == K)
						rwin = 1;
					if (b == K)
						bwin = 1;

			}

		}
		REP(i,N)
		{
			int r = 0, b = 0;
			for (int j1 = i, j2 = 0; j1 < N && j2 < N; j1++, j2++) {

					if ((r > 0 && board[j1][j2] != 'R')
							|| (b > 0 && board[j1][j2] != 'B')) {
						r = 0;
						b = 0;
					}  if (board[j1][j2] == 'R')
						r++;
					 if (board[j1][j2] == 'B')
						b++;
					if (r == K)
						rwin = 1;
					if (b == K)
						bwin = 1;

			}

		}
		REP(i,N)
		{
			int r = 0, b = 0;
			for (int j1 = 0, j2 = i; j1 < N && j2 >= 0; j1++, j2--) {
				if ((r > 0 && board[j1][j2] != 'R')
						|| (b > 0 && board[j1][j2] != 'B')) {
					r = 0;
					b = 0;
				}  if (board[j1][j2] == 'R')
					r++;
				 if (board[j1][j2] == 'B')
					b++;
				if (r == K)
					rwin = 1;
				if (b == K)
					bwin = 1;

			}

		}
		REP(i,N)
		{
			int r = 0, b = 0;
			for (int j1 = i, j2 = N - 1; j1 < N && j2 >= 0; j1++, j2--) {

				if ((r > 0 && board[j1][j2] != 'R')
						|| (b > 0 && board[j1][j2] != 'B')) {
					r = 0;
					b = 0;
				}  if (board[j1][j2] == 'R')
					r++;
				 if (board[j1][j2] == 'B')
					b++;
				if (r == K)
					rwin = 1;
				if (b == K)
					bwin = 1;

			}

		}
		if (rwin && bwin)
			printf("Case #%d: Both\n", t + 1);
		else if (rwin)
			printf("Case #%d: Red\n", t + 1);
		else if (bwin)
			printf("Case #%d: Blue\n", t + 1);
		else
			printf("Case #%d: Neither\n", t + 1);
		cerr << t + 1 << endl;
	}
}
