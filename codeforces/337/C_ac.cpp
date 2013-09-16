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
#define MOD 1000000009

typedef long long LL;

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n,m,k;
	cin>>n>>m>>k;
	int a=n/k,b=n%k;
	if(m<=b+a*(k-1)){
		cout<<m<<endl;
	}
	else{
		LL ans=1;
		int temp=m-(b+a*(k-1));
		int i=temp+1;
		LL x=2;
		while(i!=0){
			if(i%2==1){
				ans=(x*ans)%MOD;
			}
			x=(x*x)%MOD;
			i/=2;
		}
		//REP(i,temp){
		//	ans=((ans+k)*2)%MOD;
		//}
		ans=((ans-2)*k+m-temp*k+MOD)%MOD;
		cout<<ans<<endl;
	}
}
