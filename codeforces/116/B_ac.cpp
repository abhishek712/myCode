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

string s[11];
int n,m;

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output

	cin>>n>>m;
	REP(i,n)cin>>s[i];
	int ans=0;
	REP(i,n)REP(j,m){
		if(s[i][j]=='P'){
			if(i-1>=0&&s[i-1][j]=='W'){s[i-1][j]='.';s[i][j]='.';ans++;}
			else if(j-1>=0&&s[i][j-1]=='W'){s[i][j-1]='.';s[i][j]='.';ans++;}
			else if(i+1<n&&s[i+1][j]=='W'){s[i+1][j]='.';s[i][j]='.';ans++;}
			else if(j+1<m&&s[i][j+1]=='W'){s[i][j+1]='.';s[i][j]='.';ans++;}
		}
	}
	cout<<ans<<endl;
}
