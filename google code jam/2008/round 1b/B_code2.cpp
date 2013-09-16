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

static int parent[1000001];

static int root(int x) {
	if (parent[x] < 0)
		return x;
	else
		return parent[x] = root(parent[x]);
}

static void merge(int a, int b) {
	a = root(a);
	b = root(b);
	if (a == b)
		return;
	if (parent[a] > parent[b])
		swap(a, b);
	parent[a] += parent[b];
	parent[b] = a;
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
			parent[i] = -1;
		int pos = lower_bound(prime, prime + npri, p) - prime;
		for (int i = pos; prime[i] <= b - a && i < npri; i++) {
			ll temp = b - b % i;
			while (temp - i >= a) {
				merge(temp - a, temp - i - a);
				t -= i;
			}
		}
		int res = 0;
		REP(i,b-a+1)
		{
			if (parent[i] < 0)
				res++;
		}
		printf("Case #%d: %d\n", t + 1, res);
		cerr << t + 1 << endl;
		fflush(stdout);
	}
}
