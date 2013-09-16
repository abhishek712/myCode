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
#define FILENAME "small"

typedef long long ll;

ll lcm(ll a, ll b) {
	ll g = __gcd(a, b);
	if ((double) a * b / g > 1e16)
		return 0LL;
	return a / g * b;
}

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
		int f[10004];
		int N;
		ll L, H;
		cin >> N >> L >> H;
		REP(i,N)
			cin >> f[i];
		sort(f, f + N);
		ll result = 1LL;
		int i;
		for (i = 0; i < N && f[i] == 0; i++)
			;
		if (i == N) {
			printf("Case #%d: %lld\n", t + 1, L);
			continue;
		}
		int p = lower_bound(f, f + N, L) - f;
		FOR(j,i,p-1)
		{
			result = lcm(result, f[j]);
			if (result == 0 || result > H)
				goto done;
		}
		if (result<L) {

		}
		while (p < N) {
			int i;
			for (i = p; i < N; i++) {
				if (__gcd((ll) f[p], result) != min(result, (ll) f[p])) {
					break;
				}
			}
			result = lcm(f[p], result);
			if (result == 0 || result > H)
				goto done;
			p = i;
		}
		printf("Case #%d: %lld\n", t + 1, result);
		cerr << t + 1 << endl;
		continue;
		done: printf("Case #%d: NO\n", t + 1);
		cerr << t + 1 << endl;

	}
}
