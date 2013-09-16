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
	string s1,s2;
	cin>>s1>>s2;
	int num1=0,num2=0;
	REP(i,s1.size())if(s1[i]=='1')num1++;
	REP(i,s2.size())if(s2[i]=='1')num2++;
	if(num1+num1%2>=num2)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
