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

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if((a+0.0)/b>=(c+0.0)/d){
		int res1=a*d-b*c;
		int res2=d*a;
		cout<<res1/__gcd(res1,res2)<<"/"<<res2/__gcd(res1,res2)<<endl;
	}
	else{
		int res1=b*c-a*d;
		int res2=b*c;
		cout<<res1/__gcd(res1,res2)<<"/"<<res2/__gcd(res1,res2)<<endl;

	}
}
