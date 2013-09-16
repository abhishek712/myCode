/*

Common Child


Max Score: 30




Given two strings a and b of equal length, what¡¯s the longest string (S) that can be constructed such that S is a child to both a and b.

String x is said to be a child of string y if x can be formed by deleting 0 or more characters from y

Input format

Two strings a and b with a newline separating them

Constraints

All characters are upper-cased and lie between ascii values 65-90 The maximum length of the strings is 5000

Output format

Length of the string S

Sample Input #0
HARRY
SALLY


Sample Output #0
2


The longest possible subset of characters that is possible by deleting zero or more characters from HARRY and SALLY is AY, whose length is 2.

Sample Input #1
AA
BB


Sample Output #1
0


AA and BB has no characters in common and hence the output 0
*/



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

int dp[5005][5005];
string s1,s2;

int solve(int x,int y){
	if(x<0||y<0)
		return 0;
	if(dp[x][y]>=0)
		return dp[x][y];
	dp[x][y]=max(solve(x,y-1),solve(x-1,y));
	if(s1[x]==s2[y])
		dp[x][y]=max(solve(x,y),1+solve(x-1,y-1));//dp[x][y]=max(dp[x][y],1+solve(x-1,y-1));
	return dp[x][y];
}

int main() {
#ifdef OPENFILE
		char INPUTF[30]=FILENAME;
		char INPUTF2[30]=FILENAME;
		freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
		freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
#endif
	cin>>s1>>s2;
	memset(dp,-1,sizeof(dp));
	cout<<solve(s1.length()-1,s2.length()-1);
}
