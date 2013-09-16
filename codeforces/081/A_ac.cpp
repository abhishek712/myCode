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

int next[200005];
int prev[200005];
int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	string s;
	cin>>s;
	int num=s.size();
	REP(i,num+1)next[i]=i+1;
	REP(i,num+1)prev[i]=i-1;
	int i=1;
	while(next[i]!=num+1){
		if(s[i-1]==s[next[i]-1]){
			int f=prev[i],l=next[next[i]];
			prev[l]=f;next[f]=l;
			i=f;
		}
		else i=next[i];
	}
	i=next[0];
	while(i!=num+1){
		cout<<s[i-1];
		i=next[i];
	}
}
