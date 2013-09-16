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

int a[100005];
//int b[100005];

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n,m;
	cin>>n>>m;
	a[0]=0;
	REP(i,n){
		int c,t;
		cin>>c>>t;
		a[i+1]=a[i]+c*t;
	}
	int lo=0,hi=n;
	REP(i,m){
		int in;
		cin>>in;
		while(hi-lo>1){
			int mid=(lo+hi)/2;
			if(a[mid]>=in)hi=mid;
			else lo=mid;
		}
		cout<<lo+1<<endl;
		hi=n;
	}
}
