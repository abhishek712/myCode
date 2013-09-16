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
int a[1001],b[1001];
int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		REP(i,n){
			cin>>a[i];
		}
		REP(i,n){
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n,greater<int>());
		REP(i,n){
			if(a[i]+b[i]<k){
				cout<<"NO"<<endl;
				goto done;
			}
		}
		cout<<"YES"<<endl;
		done:;
	}
}
