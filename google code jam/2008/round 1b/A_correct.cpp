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
#define FILENAME "A-large-practice"

typedef long long ll;

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
		ll n,a,b,c,d,x,y,m;
		ll num[3][3];
		memset(num,0,sizeof(num));
		cin>>n>>a>>b>>c>>d>>x>>y>>m;
		num[x%3][y%3]++;
		REP(i,(int)n-1){
			x=(a*x+b)%m;
			y=(c*y+d)%m;
			num[x%3][y%3]++;
		}
		ll res=0;
		REP(i,3)
			REP(j,3){
			if(num[i][j]>=3)
				res+=num[i][j]*(num[i][j]-1)*(num[i][j]-2)/6;
		}
		REP(i,9)
			FOR(j,i+1,8)
				FOR(k,j+1,8)
					if(((i/3+j/3+k/3)%3==0)&&((i%3+j%3+k%3)%3==0)){
						res+=num[i/3][i%3]*num[j/3][j%3]*num[k/3][k%3];
		}
		printf("Case #%d: %lld\n",t+1,res);
		cerr<<t+1<<endl;
		fflush(stdout);
	}
}
