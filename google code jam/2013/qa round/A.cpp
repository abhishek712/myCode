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
#define FILENAME "A-large"


typedef long long ll;

char board[4][4];

bool jud(char z){
	REP(i,4){
		int numz=0;
		int numt=0;
		REP(j,4){
			if(board[i][j]==z)
				numz++;
			if(board[i][j]=='T')
				numt++;
		}
		if(numz==4||(numz==3&&numt==1))return 1;
	}
	REP(i,4){
		int numz=0;
		int numt=0;
		REP(j,4){
			if(board[j][i]==z)
				numz++;
			if(board[j][i]=='T')
				numt++;
		}
		if(numz==4||(numz==3&&numt==1))return 1;
	}
	int numz=(board[0][0]==z)+(board[1][1]==z)+(board[2][2]==z)+(board[3][3]==z);
	int numt=(board[0][0]=='T')+(board[1][1]=='T')+(board[2][2]=='T')+(board[3][3]=='T');
	if(numz==4||(numz==3&&numt==1))return 1;
	numz=(board[0][3]==z)+(board[1][2]==z)+(board[2][1]==z)+(board[3][0]==z);
	numt=(board[0][3]=='T')+(board[1][2]=='T')+(board[2][1]=='T')+(board[3][0]=='T');
	if(numz==4||(numz==3&&numt==1))return 1;
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
		bool finish=1;
		REP(i,4){
			REP(j,4){
				cin>>board[i][j];
				if(board[i][j]=='.')finish=0;
			}
		}
		printf("Case #%d: ",t+1);
		if(jud('X'))printf("X won\n");
		else if(jud('O'))printf("O won\n");
		else if(finish)printf("Draw\n");
		else printf("Game has not completed\n");
	}
	//fprintf (stderr, "Case #%d: %f\n",t+1,res);

}


