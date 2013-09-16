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

int n,m;
string s[155];
int r[2][155];

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	cin>>n>>m;
	REP(i,n)cin>>s[i];
	REP(i,n){
		while(r[0][i]<m&&s[i][r[0][i]]!='W')r[0][i]++;
		r[1][i]=m-1;
		while(r[1][i]>=0&&s[i][r[1][i]]!='W')r[1][i]--;
	}
	int row=n-1;
	while(row>=0&&r[0][row]==m)row--;
	int ans=0,pos=0,dt=1;//dt=0 right,1 left
	REP(i,row){
		dt=1-dt;
		//if(i==0)ans++;
		if(r[0][i]==m&&r[0][i+1]==m){ans++;continue;}
		if(dt==0){
			int npos=max(r[1][i],r[1][i+1]);
			ans+=abs(npos-pos);
			pos=npos;
		}
		else{
			int npos=min(r[0][i],r[0][i+1]);
			ans+=abs(pos-npos);
			pos=npos;
		}
		ans++;
	}
	if(row>=0){
		dt=1-dt;
		if(dt==1){
			ans+=abs(pos-r[0][row]);
		}
		else{
			ans+=abs(r[1][row]-pos);
		}
	}
	cout<<ans<<endl;
}
