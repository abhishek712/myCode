//So this strategy works as long as no single person is both left-limited and
//right-limited. (If that happened, he would not be able to go both left and
//right at the same time, and the strategy would be impossible.) So let's
//suppose xi,j = X = xj,k. If you just write down the equation, you'll see
//xi,k is exactly equal to xi,j + xj,k. But this means xi,k = 2X > X, and we
//have a contradiction(previously, we assume X is the max). Therefore, no single person is ever both left-limited
//and right-limited, and the proof is complete!

//Be careful that m should be long long

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
		ll C,D;
		vector<pair<int,int> > p;
		cin>>C>>D;
		REP(i,C){
			int in1,in2;
			cin>>in1>>in2;
			p.push_back(make_pair(in1,in2));
		}
		ll m=0LL;
		for(vector<pair <int,int> >::iterator it=p.begin();it<p.end();it++){
			ll num;
			for(vector<pair <int,int> >::iterator it2=it;it2<p.end();it2++){
				if(it2==it){
					m=max(m,D*(it->second-1));
					num=it->second;
				}
				else{
					num+=it2->second;
					m=max(m,D*(num-1)-(it2->first-it->first));
				}
			}
		}
		printf("Case #%d: %f\n",t+1,m/2.0);
		cerr<<t+1<<endl;

	}

}
