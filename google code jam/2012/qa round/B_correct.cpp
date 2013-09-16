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
//char s[128];


int main() {
	if(openfile){
		freopen("input.txt","r",stdin);//redirects standard input
		freopen("output.txt","w",stdout);//redirects standard output
	}
	int T,N,S,p;
	int I[101];
	cin>>T;
	REP(t,T){
		int result=0;
		cin>>N>>S>>p;
		REP(n,N){
			cin>>I[n];
		}
		REP(n,N){
			if(I[n]>=p+2*max(0,p-1)){
				result++;
			}
			else if((I[n]>=p+2*max(0,p-2))&&S>0){
				result++;
				S--;
			}
		}
		printf("Case #%d: %d\n",t+1,result);
	}
}
