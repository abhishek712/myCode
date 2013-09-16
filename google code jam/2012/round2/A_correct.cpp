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

#define MX 10005

typedef long long LL;
typedef long double LD;

int d[MX],l[MX],f[MX];

void main2() {
	int n,dest;
	cin>>n;
	REP(i,n)
		cin>>d[i]>>l[i];
	cin>>dest;
	memset(f,-1,sizeof(f));
	f[0]=d[0];
	REP(i,n)if(f[i]>0){
		if(d[i]+f[i]>=dest){
			cout<<"YES"<<endl;
			return;
		}
		FOR(j,i+1,n-1){
			if(d[i]+f[i]>=d[j])
			f[j]=max(f[j],min(d[j]-d[i],l[j]));
			else break;
		}
	}
	cout<<"NO"<<endl;
}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
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
