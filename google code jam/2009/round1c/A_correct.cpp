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
		string s;
		cin>>s;
		int num[70],order[70];
		REP(i,70){
			order[i]=i;
			num[i]=-1;
		}
		order[0]=1;order[1]=0;
		int p=0;
		REP(i,s.size()){
			if(num[i]==-1){
				num[i]=order[p];
				p++;
				FOR(j,i+1,s.size()-1){
					if(s[j]==s[i]){
						num[j]=num[i];
					}
				}
			}
		}
		if(p==1)p=2;
		ll res=0LL,temp=1LL;
		for(int i=s.size()-1;i>=0;i--){
			res+=temp*num[i];
			temp*=p;
		}
		printf("Case #%d: %lld\n",t+1,res);
		cerr<<t+1<<endl;
		fflush(stdout);
	}
}
