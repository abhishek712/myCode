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

int a,b;

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n,m;
	cin>>n>>m;
	REP(i,n){
		int input;
		cin>>input;
		if(input==1)a++;
		else b++;
	}
	REP(i,m){
		int in1,in2;
		cin>>in1>>in2;
		int num=in2-in1+1;
		if(num%2==1)cout<<0<<endl;
		else{
			if(a<num/2||b<num/2)cout<<0<<endl;
			else cout<<1<<endl;
		}
	}
}
