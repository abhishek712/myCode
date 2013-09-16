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
#define FILENAME "A-large-practice"

typedef long long LL;
typedef long double LD;

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	int TN;
	cin >> TN;
	REP(tn,TN)
	{
		int x, s, r, n;
		double t;
		double total=0;
		VI el[1003];
		cin >> x >> s >> r >> t >> n;
		REP(i,n)
		{
			int a1, a2, a3;
			cin >> a1 >> a2 >> a3;
			el[i].PB(a3);
			el[i].PB(a1);
			el[i].PB(a2);
			total+=a2-a1;
		}
		sort(el, el + n);
		double res = 0.0;
		double time = (x-total) / ( r);
		if (t >= time) {
			res += time;
			t-=time;

		} else {
			res += t
					+ (0.0 + x - total-( r) * t)
							/ (s);
			t=0;
		}
		REP(i,n)
		{
			double time = (el[i][2] - el[i][1] + 0.0) / ( r + el[i][0]);
			if (t >= time) {
				res += time;
				t -= time;
			} else {
				res += t
						+ (0.0 + el[i][2] - el[i][1] - (el[i][0] + r) * t)
								/ (s + el[i][0]);
				t = 0;
			}
		}

		printf("Case #%I64d: %lf\n", tn + 1,res);
		cerr << tn + 1 << endl;
		fflush(stdout);
	}
}
