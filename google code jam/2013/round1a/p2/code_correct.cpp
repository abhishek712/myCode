// be careful that when R>E.
// My algorithm is theta(nlgn) which is better than the online solution

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

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "B-large-practice"

typedef long long ll;
ll E,R,N;
ll v[10004];
ll s[10004];

void solve(ll i,ll j,ll a,ll b){
	if(i==j){
		s[i]=a+R-b;
		return;
	}
	if(i>j)return;
	int m=0,n=0;
	FOR(k,i,j){
		if(v[k]>m){
			n=k;
			m=v[k];
		}
	}
	s[n]=min(a+(n-i)*R,E)-max(b-(j-n+1)*R,0LL);
	solve(i,n-1,a,min(a+(n-i)*R,E));
	solve(n+1,j,max(b-(j-n+1)*R,0LL)+R,b);
}


int main() {
#ifdef OPENFILE
		char INPUTF[30]=FILENAME;
		char INPUTF2[30]=FILENAME;
		freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
		freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
#endif
	int T;
	cin>>T;
	REP(t,T){
		cin>>E>>R>>N;
		REP(n,N){
			s[n]=0;
			cin>>v[n];
		}
		ll res=0;
		if(R>E){
			REP(n,N)s[n]=E;
		}
		else{
		solve(0,N-1,E,R);
		}
		REP(n,N)res+=v[n]*s[n];
		printf("Case #%d: %lld\n",t+1,res);
		//fprintf (stderr, "Case #%d: %f\n",t+1,res);

	}

}
