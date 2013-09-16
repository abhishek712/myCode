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

int P,K,L;
int fre[1005];

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
		cin>>P>>K>>L;
		REP(i,L){
			cin>>fre[i];
		}
		sort(fre,fre+L,greater<int>());
		ll res=0;
		int num=0;
		REP(i,L/K)
			REP(j,K){
			res+=(i+1)*fre[num];
			num++;
		}
		REP(i,L%K){
			res+=(L/K+1)*fre[num];
			num++;
		}
		printf("Case #%d: %lld\n",t+1,res);
		cerr<<t+1<<endl;
		fflush(stdout);
	}
}
