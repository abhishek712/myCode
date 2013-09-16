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
#define FILENAME "A-large-practice"
//#define FILENAME "small";

typedef long long ll;
bool G[1004][1004];
short V[1004];
int N;

bool visit(int i){
	V[i]=1;
	REP(j,N){
		if(G[i][j]){
			if(V[j]==0){
				if(visit(j))
					return 1;
			}
			else if(V[j]==2)
				return 1;
		}
	}
	V[i]=2;
	return 0;
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
		memset(G,0,sizeof(G));
		cin>>N;
		REP(i,N){
			int input;
			cin>>input;
			REP(j,input){
				int input2;
				cin>>input2;
				G[i][input2-1]=1;
				}
		}
		bool flag=0;
		REP(i,N){
			//if(V[i]==0)
				memset(V,0,sizeof(V));
				if(visit(i)){
					flag=1;
					break;
				}

		}
		if(flag)
			printf("Case #%d: Yes\n",t+1);
		else
			printf("Case #%d: No\n",t+1);
		//fprintf (stderr, "Case #%d: %f\n",t+1,res);

	}

}
