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

map<int,int> m1,m2;
set<int> si;

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n,m,k;
	cin>>n>>m>>k;
	int a;
	REP(i,n){
		cin>>a;
		m1[a]++;
		si.insert(a);
	}
	REP(i,m){
		cin>>a;
		m2[a]++;
		si.insert(a);
	}
	int temp=0;
	for(set<int>::reverse_iterator it=si.rbegin();it!=si.rend();it++){
		if(m2[*it]>0)temp+=m2[*it];
		if(m1[*it]>0){
			if(temp>=m1[*it])
				temp-=m1[*it];
			else{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
}
