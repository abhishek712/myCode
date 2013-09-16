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
#define REP(i,n) for(long long i=0;i<(n);++i)
#define FOR(i,k,n) for (long long i=(k); i<=(long long)(n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define OPENFILE
#define FILENAME "B-large-practice"

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
		int x, y;
		cin >> x >> y;
		int x2 = abs(x), y2 = abs(y);
		int n = sqrt(2 * (x2 + y2));
		while (n * (n + 1) < 2 * (x2 + y2))
			n++;
		while ((n * (n + 1) / 2 - x2 - y2) % 2 == 1)
			n++;
		string res;
		for (int i = n; i >= 1; i--) {
			if (abs(x) > abs(y)) {
				if (x > 0)
					res += 'E', x -= i;
				else
					res += 'W', x += i;
			} else {
				if (y > 0)
					res += 'N', y -= i;
				else
					res += 'S', y += i;
			}
		}
		assert(x == 0 && y == 0);
		reverse(ALL(res));
		cout << "Case #" << t + 1 << ": " << res << endl;
		cerr << t + 1 << endl;
		fflush(stdout);
	}
}
