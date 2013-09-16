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

int a[210];
int n1,n2;
int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n;
	cin>>n;
	REP(i,2*n-1){
		int in;
		cin>>in;
		if(in>=0){
			a[i]=in;n1++;
		}
		else{
			a[i]=-in;n2++;
		}
	}
	int ans=0;
	if(n%2==1||n2%2==0){
		REP(i,2*n-1)ans+=a[i];
		cout<<ans<<endl;
		return 0;
	}
	sort(a,a+2*n-1,greater<int>());
	REP(i,2*n-2)ans+=a[i];
	cout<<ans-a[2*n-2]<<endl;
	return 0;
}
