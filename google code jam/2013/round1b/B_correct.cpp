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
#include <time.h>

using namespace std;

#define PI 3.14159265359
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "B-large-practice"

typedef long long ll;

long double ans;


//c(a,b)/2^a
long double com(int a, int b) {
	long double x = 1.0;
	REP(i,b)
	{
		x *= (a - i);
	}
	REP(i,b)
	{
		x /= (i + 1);
	}
	REP(i,a)
		{
			x /= 2;
		}
	return x;
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
		int N, X, Y;
		cin >> N >> X >> Y;
		long double ans = 0.0;
		X = abs(X);
		int round = 0;
		if (N == 1) {
			if (X + Y == 0)
				ans = 1.0;
			printf("Case #%d: %f\n", t + 1, (double)ans);
			continue;
		}
		while (2 * round * round - round  < N)
			round++;
		round--;
		if (X + Y <2 * round)
			ans = 1.0;
		else if(X+Y>2*round)
			ans=0.0;
		else {
			int drop = N - (2 * round * round - round);
			if (drop >= Y+1+2*round)
				ans = 1.0;
			else if (drop  >=Y+1&&Y<2*round) {
				FOR(i,Y+1,drop)
				{
					ans += com(drop, i);
				}
			}
		}
		printf("Case #%d: %f\n", t + 1, (double)ans);
		cerr << t + 1 << endl;
		fflush(stdout);
	}
}

