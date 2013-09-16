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

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n;
	cin>>n;
	string s;
	cin>>s;
	int mi=0,ma=n-1;
	while(s[mi]=='.'&&mi<n)mi++;
	while(s[ma]=='.'&&ma>=0)ma--;
	bool ln=0,rn=0;
	FOR(i,mi,ma){
		if(s[i]=='L')ln=1;
		if(s[i]=='R')rn=1;
		if(ln&&rn)break;
	}
	if(!ln){
		cout<<ma+1<<" "<<ma+1+1<<endl;
		return 0;
	}
	if(!rn){
		cout<<mi+1<<" "<<mi<<endl;
		return 0;
	}
	int pos=mi;
	while(s[pos]=='R')pos++;
	cout<<pos+1<<" "<<pos-1+1<<endl;
}
