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

#define PI 3.14159265359
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "A-large-practice"

typedef long long ll;

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
		int R,C;
		cin>>R>>C;
		char til[52][52];
		REP(i,R){
			REP(j,C){
				cin>>til[i][j];
			}
		}
		REP(i,R-1){
			REP(j,C-1){
				if(til[i][j]=='#'&&til[i+1][j]=='#'&&til[i][j+1]=='#'&&til[i+1][j+1]=='#'){
					til[i][j]='/';
					til[i+1][j]='\\' ;
					til[i][j+1]='\\' ;
					til[i+1][j+1]='/';
				}
			}
		}
		bool pro=1;
		REP(i,R){
			REP(j,C){
				if(til[i][j]=='#')pro=0;
			}
		}
		printf("Case #%d:\n",t+1);
		if(pro){
			REP(i,R){
				REP(j,C)
					printf("%c",til[i][j]);
					printf("\n");
			}
		}
		else printf("Impossible\n");
		cerr<<t+1<<endl;
	}
}
