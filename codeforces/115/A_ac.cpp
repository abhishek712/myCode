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

vector<int> edge[2005];
vector<int> root;

int height(int rt){
	if(edge[rt].size()==0)return 1;
	int ans=0;
	REP(j,edge[rt].size()){
		ans=max(ans,height(edge[rt][j]));
	}
	return ans+1;
}

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n;
	cin>>n;
	REP(i,n){
		int input;
		cin>>input;
		if(input!=-1)edge[input-1].push_back(i);
		else root.push_back(i);
	}
	int ans=0;
	REP(i,root.size()){
		ans=max(ans,height(root[i]));
	}
	cout<<ans<<endl;
}

