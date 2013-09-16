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

#define OPENFILE
#define FILENAME "B-large-practice"

#define MOD 210

typedef long long LL;
typedef long double LD;

LL dp[42][MOD];
string s;


void main2() {
	cin>>s;
	CLR(dp);
	dp[0][s[0]-'0']=1;
	FOR(i,1,s.length()-1){
		int temp=1;
		int lat=0;
		REP(i2,i){
			lat=(lat+(s[i-i2]-'0')*temp)%MOD;
			REP(j,MOD){
			dp[i][(j+lat)%MOD]+=dp[i-1-i2][j];
			dp[i][(j-lat+MOD)%MOD]+=dp[i-1-i2][j];
			}
			temp=(temp*10)%MOD;
		}
		lat=(lat+(s[0]-'0')*temp)%MOD;
		dp[i][(lat)%MOD]+=1;

	}
	LL ans=0;
	REP(i,MOD)
		if(i%2==0||i%3==0||i%5==0||i%7==0)ans+=dp[s.length()-1][i];
	cout<<ans<<endl;

}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	int TN;
	cin >> TN;
	REP(tn,TN)
	{
		printf("Case #%I64d: ", tn + 1);
		cerr << tn + 1 << endl;
		main2();
		fflush(stdout);
	}
}
