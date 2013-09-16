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
#define REP(i,n) for(LL i=0;i<(n);++i)
#define FOR(i,k,n) for (LL i=(k); i<=(LL)(n); ++i)
#define X first
#define Y second
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
typedef pair<int, int> PII;
typedef vector<int> VI;

//#define OPENFILE
#define FILENAME "small"

#define MX 110

typedef long long LL;
typedef long double LD;

int m,n;

LD cal(int x,int y){
	LD ans=1;
	REP(i,y)ans*=(x-i);
	REP(i,y)ans/=(i+1);
	return ans;
}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	LD res=0;
	LD d=0;
	int T;
	cin>>T;
	while(T--){
		cin>>m>>n;
		res=0;d=0;
		if(m<=n){
		res=cal(n,m);
		d=res;}
		FOR(i,1,m-1){
			//int a=min(m-i,n+0LL),b=max(1LL,m-n-i+1);
			int a=m-i,b=1;
			while(a>n){a-=i;b++;}
			LD temp1=cal(a,b);
			LD temp2=cal(n,a);
			LD tempres=temp1*temp2;

			//if(m-n>1)a=m-i+(m-n);
			while(a-1>=b+1&&a-1>=0){
				temp1*=(a-b);
				temp1*=(a-b-1);
				temp1/=a;
				temp1/=(b+1);
				temp2/=(n-a+1);
				temp2*=a;
				tempres+=temp1*temp2;
				a-=i;b++;
			}
			res+=(i+1)*tempres;
			d+=tempres;
		}
		cout<<res/d<<endl;

	}


}
