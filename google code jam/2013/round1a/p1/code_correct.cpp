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
#define FILENAME "A-large-practice"
#define PI 3.14159265359

typedef long long ll;

ll r,t;

bool test(ll mid){
	ll x=(2*r+2*mid-1);
	if((double)x*(double)mid>2e18)return 1;
	else if(x*mid>t)
		return 1;
	return 0;
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
	REP(tt,T){
		cin>>r>>t;
		ll lef=1LL,rig=1000000001;
		ll mid=(lef+rig+1)/2;
		while(lef<rig){
			if(test(mid)){
				rig=mid-1;
			}
			else
				lef=mid;
			mid=(lef+rig+1)/2;

		}
		printf("Case #%d: %lld\n",tt+1,rig);
		//fprintf (stderr, "Case #%d: %f\n",t+1,res);

	}

}
