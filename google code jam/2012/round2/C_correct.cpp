//segment the peaks into several segments, then do the recursive.

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

#define MX 2005

typedef long long LL;
typedef long double LD;

int x[MX],h[MX];

bool solve(int a,int b,int l){//solve [a,b] as level l
	if(b<=a+1) return 1;
	VI peak;
	int p=a+1;
	while(p<b){
		peak.PB(p);
		p=x[p]-1;
	}
	if(p>b)return 0;
	REP(i,peak.size()){
		p=peak[peak.size()-i-1];
		h[p]=h[b]-l*(b-p);
	}
	REP(i,peak.size()-1){
		if(!solve(peak[i],peak[i+1],l+1))return 0;
	}
	if(!solve(peak[peak.size()-1],b,l+1))return 0;

	return 1;
}

void main2() {
	int n;
	cin>>n;
	REP(i,n-1)cin>>x[i];
	h[n-1]=1e9;
	if(solve(-1,n-1,0)){
	REP(i,n)
		printf(" %d",h[i]);}
	else cout<<" Impossible";
	cout<<endl;

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
		printf("Case #%I64d:", tn + 1);
		cerr << tn + 1 << endl;
		main2();
		fflush(stdout);
	}
}
