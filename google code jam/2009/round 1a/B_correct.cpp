/*

 1------2
 |      |
 |      |
 0------3
 */
#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <cmath>
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
#define FILENAME "B-large-practice"
#define X first
#define Y second
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair

typedef long long ll;

int n, m, s[25][25], w[25][25], t[25][25];
ll dp[25][25][4];

ll goN(ll cur, int a, int b) {
	int x = (cur - t[a][b]) % (s[a][b] + w[a][b]);
	if (x < s[a][b])
		return cur + 1;
	return cur + (s[a][b] + w[a][b]) - x + 1;
}

ll goE(ll cur, int a, int b) {
	int x = (cur - t[a][b]) % (s[a][b] + w[a][b]);
	if (x >= s[a][b])
		return cur + 1;
	return cur + (s[a][b] - x) + 1;
}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	int TT;
	cin >> TT;
	REP(tt,TT)
	{
		cin >> n >> m;
		REP(i,n)
			REP(j,m)
			{
				cin >> s[n - 1 - i][j] >> w[n - 1 - i][j] >> t[n - 1 - i][j];
				t[n - 1 - i][j] = t[n - 1 - i][j]
						% (s[n - 1 - i][j] + w[n - 1 - i][j])
						- (s[n - 1 - i][j] + w[n - 1 - i][j]);
			}
		memset(dp, -1, sizeof(dp));
		priority_queue<pair<pair<ll, int>, pair<int, int> > > q;
		q.push(make_pair(make_pair(0LL, 0), make_pair(0, 0)));
		while (!q.empty()) {
			pair<pair<ll, int>, pair<int, int> > cur = q.top();
			q.pop();
			if (cur.Y.X < 0 || cur.Y.X > n - 1 || cur.Y.Y < 0
					|| cur.Y.Y > m - 1)
				continue;
			if (dp[cur.Y.first][cur.second.second][cur.first.second] != -1)
				continue;
			ll tim = -cur.first.first;
			dp[cur.second.first][cur.second.second][cur.first.second] = tim;
			if (cur.second.first == n - 1 && cur.second.second == m - 1
					&& cur.first.second == 2)
				break;
			int nn = cur.Y.X, mm = cur.Y.Y, num = cur.X.Y;
			if (num == 0) {
				q.push(MP(MP(-tim - 2, 3), MP(nn, mm - 1)));
				q.push(MP(MP(-tim - 2, 1), MP(nn - 1, mm)));
				q.push(MP(MP(-goN(tim, nn, mm), 1), MP(nn, mm)));
				q.push(MP(MP(-goE(tim, nn, mm), 3), MP(nn, mm)));
			}
			if (num == 1) {
				q.push(MP(MP(-tim - 2, 0), MP(nn + 1, mm)));
				q.push(MP(MP(-tim - 2, 2), MP(nn, mm - 1)));
				q.push(MP(MP(-goN(tim, nn, mm), 0), MP(nn, mm)));
				q.push(MP(MP(-goE(tim, nn, mm), 2), MP(nn, mm)));
			}
			if (num == 2) {
				q.push(MP(MP(-tim - 2, 1), MP(nn, mm + 1)));
				q.push(MP(MP(-tim - 2, 3), MP(nn + 1, mm)));
				q.push(MP(MP(-goN(tim, nn, mm), 3), MP(nn, mm)));
				q.push(MP(MP(-goE(tim, nn, mm), 1), MP(nn, mm)));
			}
			if (num == 3) {
				q.push(MP(MP(-tim - 2, 0), MP(nn, mm + 1)));
				q.push(MP(MP(-tim - 2, 2), MP(nn - 1, mm)));
				q.push(MP(MP(-goN(tim, nn, mm), 2), MP(nn, mm)));
				q.push(MP(MP(-goE(tim, nn, mm), 0), MP(nn, mm)));
			}
		}
		printf("Case #%d: %lld\n", tt + 1, dp[n - 1][m - 1][2]);
		cerr << tt + 1 << endl;
		fflush(stdout);
	}
}
