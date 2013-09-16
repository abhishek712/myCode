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
#define FILENAME "large"

typedef long long ll;

double s[204];
double s2[204];

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
		double sum=0;
		REP(n,N){
			cin>>s[n];
			sum+=s[n];
		}
		REP(n,N){
			s[n]/=sum;
			s2[n]=s[n];
		}
		sort(s,s+N);
		double remain=1.0;
		int upper=1;
		while(upper!=N&&remain>=(s[upper]-s[upper-1])*upper){
			remain-=(s[upper]-s[upper-1])*upper;
			REP(i,upper){
				s[i]=s[upper];
			}
			while(s[upper]==s[upper-1]&&upper<N)
				upper++;
		}
		double safe=s[upper-1]+remain/upper;
		printf("Case #%d:",t+1);
		REP(n,N){
			printf(" %f",max((safe-s2[n])*100,0.0));
		}
		printf("\n");
	}

}
