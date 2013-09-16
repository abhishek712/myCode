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
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "B-large-practice"

typedef long long ll;

int N, M,malt[2004];
vector<pair<int,int> > cus[2004];

void remove(int f){
	REP(i,M){
		REP(j,cus[i].size()){
			if(cus[i][j].first==f&&cus[i][j].second!=1){
				swap(cus[i][j],cus[i][cus[i].size()-1]);
				cus[i].pop_back();
			}
		}
	}
}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	int T;
	cin >> T;
	REP(t,T)
	{
		memset(malt, 0, sizeof(malt));
		cin >> N >> M;
		REP(i,M)
		{
			cus[i].clear();
			int input;
			cin >> input;
			REP(j,input)
			{
				int in1, in2;
				cin >> in1 >> in2;
				cus[i].push_back(make_pair(in1-1,in2));
			}
		}
		int found;
		do{
			found=-1;
			REP(i,M){
				if(cus[i].size()==1&&cus[i][0].second==1&&!malt[cus[i][0].first]){
					found=cus[i][0].first;
				}
			}
			malt[found]=1;
			remove(found);

		}while(found!=-1);
		bool bad=0;
		REP(i,M){
			if(cus[i].size()==0)
				bad=1;
		}
		if(bad){
		printf("Case #%d: IMPOSSIBLE\n", t + 1);
		}
		else{
			printf("Case #%d:", t + 1);
			REP(i,N){
				printf(" %d",malt[i]);
			}
			printf("\n");
		}
		cerr << t + 1 << endl;
		fflush(stdout);
	}
}
