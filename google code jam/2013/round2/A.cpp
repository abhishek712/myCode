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
#define REP(i,n) for(LL i=0;i<(n);++i)
#define FOR(i,k,n) for (LL i=(k); i<=(LL)(n); ++i)
#define X first
#define Y second
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
typedef pair<int, int> PII;
typedef vector<int> VI;

#define OPENFILE
#define FILENAME "A-small-practice"

#define MX 10
#define MOD 1000002013

typedef long long LL;
typedef long double LD;

LL n, m;
vector<vector<LL> > p;

LL def(LL a, LL b, LL c, LL d) {
	LL ans = ((d - a - 1) * (d - a) / 2) % MOD;
	ans = (ans + (b - c - 1) * (b - c) / 2) % MOD;
	ans = (ans - (d - c - 1) * (d - c) / 2) % MOD;
	ans = (ans - (b - a - 1) * (b - a) / 2) % MOD;
	return (ans + MOD) % MOD;
}

void main2() {
	cin >> n >> m;
	LL ans = 0;
	LL a, b, c, d;
	REP(i,m)
	{
		cin >> a >> b >> c;
		vector<LL> temp;
		temp.PB(a);
		temp.PB(b);
		temp.PB(c);
		p.push_back(temp);
	}
	while (p.size() != 0) {
		if (p.front()[2] == 0) {
			p.erase(p.begin());
			continue;
		}
		int s = p.size();
		sort(p.begin(), p.end());
		bool flag = 0;
		for (int i = 1; i < s; i++) {
			a = p[0][0];
			b = p[0][1];
			c = p[i][0];
			d = p[i][1];
			if (b >= c && d > b&&c>a) {
				flag = 1;
				LL num = min(p[0][2], p[i][2]);
				if (p[0][2] > num) {
					if(p[0][2]!=num){
					vector<LL> temp;
					temp.PB(p[0][0]);
					temp.PB(p[0][1]);
					temp.PB(p[0][2] - num);
					p.push_back(temp);}
					p[0][2] = num;
					p[0][1] = d;
					p[i][1] = b;
					p[i][2] = num;

				} else {
					if(p[i][2]!=num){
						vector<LL> temp;
						temp.PB(p[i][0]);
						temp.PB(p[i][1]);
						temp.PB(p[i][2] - num);
						p.push_back(temp);}

					p[0][2] = num;
					p[0][1] = d;
					p[i][1] = b;
					p[i][2] = num;

				}
				ans = (ans + def(a, b, c, d)) % MOD;
			}

		}
		if (flag == 0)
						p.erase(p.begin());

	}
	cout << ans << endl;
}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	cout.precision(15);
	int TN;
	cin >> TN;
	REP(tn,TN)
	{
		printf("Case #%I64d: ", tn + 1);
		cerr << tn + 1 << endl;
		main2();
		fflush(stdout);
	}
}
