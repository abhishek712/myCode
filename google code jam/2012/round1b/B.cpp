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
#define FILENAME "small"

#define MX 110

typedef long long LL;
typedef long double LD;

int h,n,m,c[MX][MX],f[MX][MX];

double cost(double t, PII p1,PII p2){
	if(c[p2.X][p2.Y]-50<f[p2.X][p2.Y]||c[p1.X][p1.Y]-50<f[p2.X][p2.Y]||c[p2.X][p2.Y]-50<f[p1.X][p1.Y])
		return 1.0e9;


}


void main2() {

	cin>>h>n>>m;
	REP(i,n)REP(j,m)cin>>c[i][j];
	REP(i,n)REP(j,m)cin>>f[i][j];
	priority_queue<pair<double,PII> > q;


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
