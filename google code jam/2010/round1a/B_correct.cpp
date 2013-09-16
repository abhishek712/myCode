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

int a[260];
int dp[105][260];
int D,I,M,N;

int solve(int i,int final){
	if(i<0)return 0;
	if(dp[i][final]!=-1)return dp[i][final];
	int best=solve(i-1,final)+D;
	if(M==0){
		best=min(best,abs(final-a[i])+solve(i-1,final));
	}
	else REP(j,256){
		int prev=solve(i-1,j);
		int move=abs(final-a[i]);
		int ninsert=(int)(max(0.0,floor(abs(final-j)/(M+0.0)-1e-8)));
		// be careful. another way ninsert=(final-j==0)?0:((M==0)?100000000:(final-j-1)/M);
		int insert=ninsert*I;
		best=min(best,prev+move+insert);
	}
	dp[i][final]=best;
	return best;
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
		cin>>D>>I>>M>>N;
		REP(i,N){
			cin>>a[i];
			REP(j,260)
				dp[i][j]=-1;
		}
		int result=1e9;
		REP(j,256)
			result=min(solve(N-1,j),result);
		printf("Case #%d: %d\n",t+1,result);
		cerr<<t+1<<endl;
		fflush(stdout);
	}
}
