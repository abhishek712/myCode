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
#define FILENAME "C-large-practice"

typedef long long LL;
typedef long double LD;

bool p[1000005];
VI prime;

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	CLR(p);
	FOR(i,2,1000005){
		if(p[i]==0){
			prime.PB(i);
			for(int j=2*i;j<1000005;j+=i)p[j]=1;
		}
	}
	int TN;
	cin >> TN;
	REP(tn,TN)
	{
		LL N;
		cin>>N;
		LL i=0,res=0;
		while(i<prime.size()&&prime[i]<N){
			LL nn=N;
			while(nn>=prime[i]){
				res++;
				nn=nn/prime[i];
			}
			res--;
			i++;
		}
		if(N==1)printf("Case #%I64d: 0\n",tn+1);
		else printf("Case #%I64d: %I64d\n",tn+1,res+1);
		cerr << tn + 1 << endl;
		fflush(stdout);
	}
}
