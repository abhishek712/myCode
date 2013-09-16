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
	int n;
	cin>>n;
	int i=1;
	while(n>5*i){
		n-=5*i;
		i*=2;
	}
	if(n<=i)cout<<"Sheldon"<<endl;
	else if(n<=2*i)cout<<"Leonard"<<endl;
	else if(n<=3*i)cout<<"Penny"<<endl;
	else if(n<=4*i)cout<<"Rajesh"<<endl;
	else cout<<"Howard"<<endl;
}
