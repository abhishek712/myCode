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
//#define OPENFILE
#define FILENAME "C-large-1"

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
		ll A,B;
		cin>>A>>B;
		int a=ceil(sqrt(A));
		int b=floor(sqrt(B));
		int k=0;
		FOR(i,a,b){
			//fprintf (stderr, "%d\n",i);
			int n=i;
			int rev=0;
			while(n>0){
				int d=n%10;
				rev=rev*10+d;
				n/=10;
			}
			if(rev!=i)continue;
			ll n2=i*i;
			ll rev2=0;
			while(n2>0){
				ll d2=n2%10;
				rev2=rev2*10+d2;
				n2/=10;
			}
			if(rev2==i*i){
				k++;
				fprintf (stderr, "%d\n",i);
			}
		}
		printf("Case #%d: %d\n",t+1,k);
		//fprintf (stderr, "Case #%d: %f\n",t+1,res);
	}

}
