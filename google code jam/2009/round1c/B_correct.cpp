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
	int T;
	cin>>T;
	REP(t,T){
		int N;
		cin>>N;
		long double x[6];
		memset(x,0,sizeof(x));
		REP(i,N){
			REP(j,6){
				int inp;
				cin>>inp;
				x[j]+=inp;
			}
		}
		REP(i,6)x[i]/=(N+0.0);
		long double tmin;
		if(abs(x[3])<0.00000001&&abs(x[4])<0.00000001&&abs(x[5])<0.00000001)tmin=0.0;
		else
		tmin=max((long double)0.0,(-x[0]*x[3]-x[1]*x[4]-x[2]*x[5])/(x[3]*x[3]+x[4]*x[4]+x[5]*x[5]));
		long double d=0;
		REP(i,3){
			d+=(x[i]+x[i+3]*tmin)*(x[i]+x[i+3]*tmin);
		}
		d=sqrt(d);
		printf("Case #%d: %.8f %.8f\n",t+1,(double)d,(double)tmin);
		cerr<<t+1<<endl;
		fflush(stdout);
	}
}
