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
	freopen("male2.txt", "r", stdin); //redirects standard input
	freopen("male2.out", "w", stdout);//redirects standard output
	cout<<"{";
	REP(i,12649){
		string s;
		cin>>s;
		cout<<"\""<<s<<"\",";
	}
	string s;
			cin>>s;
			cout<<"\""<<s<<"\"};"<<endl;
}
