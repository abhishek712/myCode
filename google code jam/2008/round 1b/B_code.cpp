//I don't know why it quit
//only can pass small input


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

typedef long long ll;

int uni[1000005];

int find(int x) {
	if (uni[x] == x)
		return x;
	return uni[x] = find(uni[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (uni[x] > uni[y])
		swap(x, y);
	uni[y] = x;
}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	int T;
	bool *pri = (bool *) malloc(1000005 * sizeof(bool));
	memset(pri, 0, sizeof(pri));
	int prime[100000], npri = 0;
	FOR(i,2,1000005)
	{
		if (!pri[i]) {
			prime[npri] = i;
			npri++;
			for (int j = 2 * i; j < 1000005; j += i)
				pri[j] = 1;
		}
	}
	free(pri);
	cin >> T;
	REP(t,T)
	{
		ll a, b, p;
		cin >> a >> b >> p;
		REP(i,b-a+1)
			uni[i] = i;
		int pos = lower_bound(prime, prime + npri, p) - prime;
		for (int i = pos; prime[i] <= b - a && i < npri; i++) {
			ll las = b - b % prime[i];
			ll pre = las - prime[i];
			while (pre >= a) {
				merge((int) las - a, (int) pre - a);
				pre -= prime[i];
			}
		}
		int res = 0;
		REP(i,b-a+1)
		{
			if (uni[i] == i)
				res++;
		}
		printf("Case #%d: %d\n", t + 1, res);
		cerr << t + 1 << endl;
		fflush(stdout);
	}
}
