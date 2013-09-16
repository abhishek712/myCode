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
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define OPENFILE 1
#define FILENAME "large"

typedef long long ll;

pair<int,int> star[1004];
int played[1004];

bool comp(pair<int,int> a, pair<int,int> b){
	return (a.second<b.second);
}

int main() {
	if(OPENFILE){
		char INPUTF[30]=FILENAME;
		char INPUTF2[30]=FILENAME;
		freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
		freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
	}
	int T;
	cin>>T;
	REP(t,T){
		int totalstar=0;
		int playtime=0;
		memset(played,0,sizeof(played));
		int N;
		cin>>N;
		REP(n,N){
			cin>>star[n].first>>star[n].second;
		}
		sort(star,star+N,comp);
		int last=0;
		int p=1;
		while(last!=N&&p){
			if(star[last].second<=totalstar){
				totalstar+=2-played[last];
				played[last]=2;
				last++;
				playtime++;
			}
			else{
				int flag=0;
				for(int i=N-1;i>=last;i--){
					if(star[i].first<=totalstar&&played[i]==0){
						totalstar+=1;
						played[i]=1;
						flag=1;
						playtime++;
						break;
					}
				}
				if(flag==0){
					p=0;break;
				}
			}
		}
		if(p==1){
		printf("Case #%d: %d\n",t+1,playtime);
		fprintf(stderr,"Case #%d: %d\n",t+1,playtime);
		}
		else{
			printf("Case #%d: Too Bad\n",t+1);
			fprintf(stderr,"Case #%d: Too Bad\n",t+1);
		}
		//fprintf (stderr, "Case #%d: %f\n",t+1,res);
	}
}
