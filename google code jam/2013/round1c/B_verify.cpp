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
//#define OPENFILE
#define FILENAME "small"

typedef long long ll;

int main() {
#ifdef OPENFILE
		char INPUTF[30]=FILENAME;
		char INPUTF2[30]=FILENAME;
		freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
		freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
#endif
		REP(i,50){
			string s;
			cin>>s;
			int x=0,y=0;
			REP(j,s.length()){
				if(s[j]=='E')
					x+=j+1;
				if(s[j]=='W')
									x-=j+1;
				if(s[j]=='N')
									y+=j+1;
				if(s[j]=='S')
									y-=j+1;
			}
			cout<<x<<y<<endl;
		}
}
