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
#define openfile 0

typedef long long ll;

int main() {
	if (openfile) {
		freopen("input.txt", "r", stdin); //redirects standard input
		freopen("output.txt","w",stdout);//redirects standard output
		}
		int T;
		cin>>T;
		REP(t,T) {
			int A,B;
			cin>>A>>B;
			ll result=0;
			int digit=0;
			int a=A;
			while(a/10>=1){
				digit++;
				a=a/10;
			}
			int m=1;
			REP(i,digit){
				m*=10;
			}
			FOR(n,A,B){
				int a=n;
				int b=n;
				a=a/10+(a%10)*m;
				for(int k=0;k<digit&&a!=n;k++){
					if(a>=A&&a<=B&&a>b){
						result++;
					}
					a=a/10+(a%10)*m;
				}
			}
			printf("Case #%d: %lld\n",t+1,result);

}
}

