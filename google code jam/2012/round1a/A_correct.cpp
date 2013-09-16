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
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define openfile 1

typedef long long ll;
double p[100001];
double pi[100001];

int main() {
	if(openfile){
		freopen("large.in","r",stdin);//redirects standard input
		freopen("large.out","w",stdout);//redirects standard output
	}
	int T;
	cin>>T;
	REP(t,T){
		int A,B;
		cin>>A>>B;
		REP(a,A){
			cin>>p[a];
			if(a==0){
				pi[a]=p[a];
			}
			else{
				pi[a]=p[a]*pi[a-1];
			}
		}
		double res=min(p[0]*(B)+(1-p[0])*(2*B-1+2),B+2.0);
		FOR(i,2,A+1){
			res=min(pi[i-1]*(B-i+1)+(1-pi[i-1])*(2*B-i+2),res+1);
			res=min(B+2.0,res);
		}
		printf("Case #%d: %f\n",t+1,res);
		fprintf (stderr, "Case #%d: %f\n",t+1,res);

	}

}
