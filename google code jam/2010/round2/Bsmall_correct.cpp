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
#define FILENAME "B-small-practice"

#define MX 110

typedef long long LL;
typedef long double LD;

int m[1028];
int pri[12][514];
int buy[12][514];

void main2() {
	int p;
	cin>>p;
	REP(i,pow(2,p))cin>>m[i];
	REP(i,p)REP(j,pow(2,p-1-i))cin>>pri[i][j];
	CLR(buy);
	REP(i,pow(2,p)){
		REP(j,p-m[i]){
			int temp=i/pow(2,p-j);
			buy[p-1-j][temp]=1;
		}
	}
	int ans=0;
	REP(i,p)REP(j,pow(2,p-1-i)){
		if(buy[i][j]==1)ans++;
	}
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
