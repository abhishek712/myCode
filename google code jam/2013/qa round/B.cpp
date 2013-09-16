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
#define FILENAME "B-large"

typedef long long ll;
int a[104][104];

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
		int N,M;
		bool flag[104];
		int limit[104];//if flag=0,>=limit;if flag=1;==limit
		cin>>N>>M;
		REP(i,N){
			REP(j,M){
				cin>>a[i][j];
			}
		}
		printf("Case #%d: ",t+1);
		if(M==1||N==1){
			printf("YES\n");
			continue;
		}
		memset(flag,0,sizeof(flag));
		int maxx=0;
		REP(i,M){
			if(a[0][i]>maxx)maxx=a[0][i];
		}
		REP(i,M){
			if(a[0][i]==maxx)
				limit[i]=maxx;
			else{
				flag[i]=1;
				limit[i]=a[0][i];
			}
		}
		FOR(j,1,N-1){
			maxx=0;
			REP(i,M){
				if(a[j][i]>maxx)maxx=a[j][i];
			}
			REP(i,M){
				if(a[j][i]==maxx){
					if(flag[i]){
						if(a[j][i]>limit[i]){
							printf("NO\n");
							goto done;
						}	}
					else{
						limit[i]=max(limit[i],maxx);
					}
				}
				else{
					if(flag[i]){
						if(a[j][i]!=limit[i]){
							printf("NO\n");
							goto done;
						}	}
					else{
						if(a[j][i]<limit[i]){
							printf("NO\n");
							goto done;
						}
						else{
						limit[i]=a[j][i];
						flag[i]=1;
						}
					}
				}
			}

			//fprintf (stderr, "Case #%d: %f\n",t+1,res);
		}
		printf("YES\n");
		done:;
	}
}
