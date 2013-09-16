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

int a[105];
int x[105],y[105];

int dis(int n1,int n2){
	return abs(x[n1]-x[n2])+abs(y[n1]-y[n2]);
}

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n,d;
	cin>>n>>d;
	REP(i,n-2)cin>>a[i+1];
	REP(i,n)cin>>x[i]>>y[i];
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0,0));
	set<int> visited;
	int ans=0;
	a[0]=0;
	while(!pq.empty()){
		pair<int,int> p=pq.top();
		pq.pop();
		if(visited.count(p.second)>0)continue;
		visited.insert(p.second);
		if(p.first<0&&p.first<ans)ans=p.first;
		if(p.second==n-1){
			cout<<-ans<<endl;
			return 0;
		}
		REP(i,n){
			if(visited.count(i)==0)
				pq.push(make_pair(p.first-dis(p.second,i)*d+a[p.second],i));
		}
	}
}
