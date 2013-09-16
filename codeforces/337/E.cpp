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

typedef long long LL;

vector<int> prime;
bool p[1000006];

LL nprime(LL x){
	LL ans=0,i=0;
	while(x!=1){
		if(x%prime[i]==0){
			x/=prime[i];
			ans++;
		}
		else i++;
	}
	return ans;
}

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	for(int i=2;i<=1000000;i++){
		if(p[i]==0){
			prime.push_back(i);
			for(int j=2*2;j<=1000000;j+=i)p[j]=1;
		}
	}
	int n;
	cin>>n;
	LL a[8];
	REP(i,n)cin>>a[i];
	sort(a,a+n);
	//	vector<int> vi[8];
	//	REP(i,n){
	//		FOR(j,i+1,n-1){
	//			if(a[j]%a[i]==0){
	//				vi[j].push_back(i);
	//			}
	//		}
	//	}
	int prob[]={0,1,2,3,4,5,6,7};
	LL ans=1000000000000;
	LL mux=1;
	REP(i,n)mux*=a[i];
	do {
		LL total=mux;
		//LL temp=0;
		LL b[8];
		REP(i,n)b[i]=a[i];
		REP(i,n){
			FOR(j,i+1,n-1){
				if(b[j]%a[i]==0&&prob[j]<prob[i]){
					b[j]/=a[i];
					total/=b[i];
					b[i]=1;
				}
			}
		}
		if(nprime(total)==6){
			cout<<endl;
		}
		ans=min(ans,nprime(total)+n);
	} while ( next_permutation(prob,prob+n) );
	cout<<ans<<endl;
}
