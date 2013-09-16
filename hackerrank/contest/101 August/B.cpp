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

int num[26][10002];
int target[26];
int n;

bool possible(int index){
	REP(i,26){
		if(num[i][n]-num[i][index]<target[i])
			return false;
	}
	return true;
}

int main() {
	freopen("small.in", "r", stdin); //redirects standard input
	freopen("small.out", "w", stdout);//redirects standard output
	string s;
	cin>>s;
	n=s.size();
	string ans;
	reverse(s.begin(),s.end());
	REP(i,s.size()){
		REP(j,26){
			if(s[i]-'a'==j)
				num[j][i+1]=num[j][i]+1;
			else
				num[j][i+1]=num[j][i];
		}
	}
	REP(i,26){
		target[i]=num[i][n]/2;
	}
	bool finish=0;
	int pos=0;
	while(!finish){
		for(int i=0;i<26;i++){
			if(target[i]==0)continue;
			int pos2=pos;
			while(pos2<n&&s[pos2]-'a'!=i)pos2++;
			if(pos2!=n&&possible(pos2)){
				ans.push_back('a'+i);
				target[i]--;
				pos=pos2+1;
				break;
			}
		}
		finish=1;
		REP(i,26){
			if(target[i]!=0)
				finish=0;
		}
	}
	cout<<ans<<endl;
}
