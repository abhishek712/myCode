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

int main() {
#ifdef OPENFILE
		char INPUTF[30]=FILENAME;
		char INPUTF2[30]=FILENAME;
		freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
		freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
#endif
	int C;
	cin>>C;
	REP(c,C){
		int N,K,B,T;
		int x[55],v[55];
		cin>>N>>K>>B>>T;
		REP(i,N)
			cin>>x[i];
		REP(i,N)
			cin>>v[i];
		int res=0,t=0,bad=0;
		if(K==0){printf("Case #%d: 0\n",c+1);continue;}
		for(int i=N-1;i>=0;i--){
			if((B-x[i])<=T*v[i]){
				t++;
				res+=bad;
			}
			else bad++;
			if(t==K)break;
		}
		if(t<K)
			printf("Case #%d: IMPOSSIBLE\n",c+1);
		else
			printf("Case #%d: %d\n",c+1,res);
		cerr<<c+1<<endl;
		fflush(stdout);
	}
}
