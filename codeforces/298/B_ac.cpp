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

int ct[4];
string s;
int target[4];

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int t,x1,y1,x2,y2;
	cin>>t>>x1>>y1>>x2>>y2;
	if(x2<x1)target[0]=abs(x1-x2);
	else target[1]=abs(x1-x2);
	if(y2<y1)target[2]=abs(y1-y2);
		else target[3]=abs(y1-y2);
	cin>>s;
	REP(i,t){
		if(s[i]=='W')ct[0]++;
		if(s[i]=='E')ct[1]++;
		if(s[i]=='S')ct[2]++;
		if(s[i]=='N')ct[3]++;
		bool temp=0;
		REP(j,4){
			if(ct[j]<target[j]){
				temp=1;
				break;
			}
		}
		if(temp==0){
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}
