#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <math.h>
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

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "B-small-attempt4"

typedef long long ll;
int a[12][12];
int N,M;

bool checkline(int x,int y){//whether all 1
	REP(i,M){
		if(a[x][i]!=1)
			return 0;
	}
	return 1;
}

bool checkrow(int x,int y){//whether all 1
	REP(i,N){
		if(a[i][y]!=1)
			return 0;
	}
	return 1;
}

int main() {
#ifdef OPENFILE
	char INPUTF[30]=FILENAME;
	char INPUTF2[30]=FILENAME;
	freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
	freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
#endif
	int T;
	cin>>T;
	REP(t,T){
		cin>>N>>M;
		REP(i,N){
			REP(j,M){
				cin>>a[i][j];
			}
		}
		printf("Case #%d: ",t+1);
		REP(i,N){
			REP(j,M){
				if(a[i][j]==1){
					if(!(checkline(i,j)||checkrow(i,j))){
						printf("NO\n");
					goto done;}
				}
			}
		}
		printf("YES\n");
		done:;
	}
}
