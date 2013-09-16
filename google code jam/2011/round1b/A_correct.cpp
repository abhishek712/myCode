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

string s[101];
int N;
double WP[101],OWP[101],OOWP[101];

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
		int win[101],mat[101];
		cin>>N;
		memset(win,0,sizeof(win));
		memset(mat,0,sizeof(mat));
		REP(n,N)cin>>s[n];
		REP(i,N){
			REP(j,N){
				if(s[i][j]=='1')win[i]++;
				if(s[i][j]!='.')mat[i]++;
			}
		}
		REP(i,N){
			double temp=0.0;
			REP(j,N){
				if(s[i][j]=='1'){
					temp+=(win[j])/(mat[j]-1.0);
				}
				if(s[i][j]=='0'){
					temp+=(win[j]-1.0)/(mat[j]-1.0);
				}
			}
			OWP[i]=temp/mat[i];
		}
		REP(i,N){
			double temp=0.0;
			REP(j,N){
				if(s[i][j]!='.')
				temp+=OWP[j];
			}
			OOWP[i]=temp/mat[i];
			WP[i]=(win[i]+0.0)/mat[i];
		}


		printf("Case #%d:\n",t+1);
		REP(i,N){
			printf("%0.9f\n",0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i]);
		}
		//fprintf (stderr, "Case #%d: %f\n",t+1,res);

	}

}
