/*
  (xn)   (6   -4)^n-1 (6)
 (xn-1)= (1    0)	  (2)
 *
 *
 *
 *
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
#define FILENAME "C-large-practice"

typedef long long ll;

void multi(int a[][2], int b[][2]) {
	ll c[2][2];
	REP(i,2)
	{
		REP(j,2)
		{
			c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % 1000;
		}
	}
	REP(i,2)
		REP(j,2)
			a[i][j]=(int)c[i][j];
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
		int n;
		cin >> n;
		n--;
		int a[2][2],b[2][2];
		a[0][0]=6;a[0][1]=-4;a[1][0]=1;a[1][1]=0;
		b[0][0]=1;b[0][1]=0;b[1][0]=0;b[1][1]=1;
		while(n!=0){
			if(n%2==1){
			multi(b,a);
			}
			n/=2;
			multi(a,a);
		}
		ll res=((6LL*b[0][0]+2*b[0][1])%1000+1000-1)%1000;
		printf("Case #%d: %03lld\n", t + 1,res);
		cerr << t + 1 << endl;
		fflush(stdout);
	}
}
