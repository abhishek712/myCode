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

typedef long long LL;
typedef long double LD;


#define MAX 505
int m[MAX][MAX];
int dp[MAX][MAX];
LL dpx[MAX][MAX];
LL dpy[MAX][MAX];

LL dpf(int x,int y){
if(x<0||y<0)return 0;
return dp[x][y];
}

LL dpxf(int x,int y){
if(x<0||y<0)return 0;
return dpx[x][y];
}

LL dpyf(int x,int y){
if(x<0||y<0)return 0;
return dpy[x][y];
}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	int TN;
	cin >> TN;
	REP(tn,TN)
	{
		int r,c,d;
		cin>>r>>c>>d;
		REP(i,r){
			REP(j,c){
				char input;
				cin>>input;
				m[i][j]=input-'0';
			}
		}
		REP(i,r)dp[i][0]=m[i][0];
		REP(j,r)FOR(i,1,c-1)dp[j][i]=dp[j][i-1]+m[j][i];
		FOR(j,1,r-1)FOR(i,0,c-1)dp[j][i]+=dp[j-1][i];

		REP(i,r)dpx[i][0]=m[i][0]*0;
		REP(j,r)FOR(i,1,c-1)dpx[j][i]=dpx[j][i-1]+m[j][i]*i;
		FOR(j,1,r-1)FOR(i,0,c-1)dpx[j][i]+=dpx[j-1][i];

		REP(i,r)dpy[i][0]=m[i][0]*i;
		REP(j,r)FOR(i,1,c-1)dpy[j][i]=dpy[j][i-1]+m[j][i]*j;
		FOR(j,1,r-1)FOR(i,0,c-1)dpy[j][i]+=dpy[j-1][i];

		int i=min(r,c);
		for(;i>=3;i--){
			REP(x,r-i+1)
					REP(y,c-i+1){
					LL mas=dp[x+i-1][y+i-1]-dpf(x-1,y+i-1)-dpf(x+i-1,y-1)+dpf(x-1,y-1);
					mas-=m[x][y]+m[x][y+i-1]+m[x+i-1][y]+m[x+i-1][y+i-1];

					LL masx=dpx[x+i-1][y+i-1]-dpxf(x-1,y+i-1)-dpxf(x+i-1,y-1)+dpxf(x-1,y-1);
					masx-=m[x][y]*y+m[x][y+i-1]*(y+i-1)+m[x+i-1][y]*(y)+m[x+i-1][y+i-1]*(y+i-1);

					LL masy=dpy[x+i-1][y+i-1]-dpyf(x-1,y+i-1)-dpyf(x+i-1,y-1)+dpyf(x-1,y-1);
					masy-=m[x][y]*x+m[x][y+i-1]*(x)+m[x+i-1][y]*(x+i-1)+m[x+i-1][y+i-1]*(x+i-1);

					if(2*masx==mas*(y+y+i-1)&&2*masy==mas*(x+x+i-1)){
						printf("Case #%I64d: %d\n",tn+1,i);
						goto done;
					}
			}
		}
		printf("Case #%I64d: IMPOSSIBLE\n",tn+1);
		done:
		cerr << tn + 1 << endl;
		fflush(stdout);
	}
}
