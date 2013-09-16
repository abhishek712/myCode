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

ll a[105],b[105];
int A[105],B[105];
ll dp[105][105];
int N,M;

ll solve(int x,int y,ll xx,ll yy){
	if(x>=N||y>=M)
		return 0;
	if(!xx&&!yy){
		if(dp[x][y]!=-1)
			return dp[x][y];
		if((A[x]==B[y])&&(min(a[x],b[y])>0)){
			ll c=min(a[x],b[y]);
			dp[x][y]=c+solve(x,y,c,c);
			return dp[x][y];
		}
		else{
			dp[x][y]=max(solve(x+1,y,0,0),solve(x,y+1,0,0));
			return dp[x][y];
		}
	}
	else{
		if(A[x]==B[y]&&min(a[x]-xx,b[y]-yy)>0){
			ll c=min(a[x]-xx,b[y]-yy);
			return c+solve(x,y,xx+c,yy+c);
		}
		else{
			return max(solve(x+1,y,0,yy),solve(x,y+1,xx,0));
		}
	}
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
		cin>>N>>M;
		REP(i,N)
			cin>>a[i]>>A[i];
		REP(i,M)
			cin>>b[i]>>B[i];
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %lld\n",t+1,solve(0,0,0,0));
		cerr<<t+1<<endl;
		fflush(stdout);
	}
}
