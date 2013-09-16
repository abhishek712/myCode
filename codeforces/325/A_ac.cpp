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

pair<int,int>  l[6],r[6];

bool comp1(pair<int,int> p1,pair<int,int> p2){
	if(p1.first!=p2.first)return p1.first<p2.first;
	return p1.second<p2.second;
}

bool comp2(pair<int,int> p1,pair<int,int> p2){
	if(p1.first!=p2.first)return p1.first>p2.first;
	return p1.second>p2.second;
}

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n;
	cin>>n;
	REP(i,n){
		cin>>l[i].first>>l[i].second>>r[i].first>>r[i].second;
	}
	LL area=0;
	REP(i,n){
		area+=(r[i].second-l[i].second)*(r[i].first-l[i].first);
	}
	sort(l,l+n,comp1);
	sort(r,r+n,comp2);
	REP(i,n){
		if(l[i].first<l[0].first||l[i].second<l[0].second){
			cout<<"NO";
			return 0;
		}
		if(r[i].first>r[0].first||r[i].second>r[0].second){
			cout<<"NO";
			return 0;
		}
	}
	LL area2=(r[0].first-l[0].first)*(r[0].second-l[0].second);
	if(area2!=area||(r[0].first-l[0].first)!=(r[0].second-l[0].second)){
		cout<<"NO";
	}
	else cout<<"YES";

}
