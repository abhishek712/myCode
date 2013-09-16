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
		set<string> exi;
		set<string> cre;
		int N,M;
		cin>>N>>M;
		REP(i,N){
			string s;
			cin>>s;
			exi.insert(s);
			FOR(j,1,s.length()-1){
				if (s[j]=='/')
						exi.insert(s.substr(0,j));
			}
		}
		REP(i,M){
			string s;
			cin>>s;
			if(exi.count(s)==0)
				cre.insert(s);
			FOR(j,1,s.length()-1){
				if (s[j]=='/'){
					string s2=s.substr(0,j);
					if(exi.count(s2)==0)
								cre.insert(s2);
				}
			}
		}

		printf("Case #%d: %d\n",t+1,cre.size());
		cerr<<t+1<<endl;
	}
}
