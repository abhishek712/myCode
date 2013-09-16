/*

Mr K marsh


Max Score: 40




Mr K has a rectangular land (m x n). There are marshes in the land where the fence cannot hold. Mr K wants you to find the perimeter of the largest rectangular fence that can be built on this land.

Input format

First line contains m and n. The next m lines contains n characters describing the state of the land. ¡®x¡¯ (ascii value: 120) if it is a marsh and ¡®.¡¯ ( ascii value:46) otherwise.

Constraints

2<=m,n<=500

Output Format

Output contains a single integer - the largest perimeter. If the rectangular fence cannot be built, print ¡°impossible¡± (without quotes)

Sample Input:1
4 5
.....
.x.x.
.....
.....


Output
14


Fence can be put up across the entire land owned by Mr K. The perimeter is 2 * (4-1) + 2 * (5-1) = 14.

Sample Input:2
2 2
.x
x.


Output
impossible


We need minimum of 4 points to place the 4 corners of the fence. Hence, impossible.

Sample Input:3
2 5
.....
xxxx.


Output
impossible
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

typedef long long ll;

int f1[505][505], f2[505][505];
int f3[505][505], f4[505][505];

#define OPENFILE
#define FILENAME "small"

int main() {
#ifdef OPENFILE
		char INPUTF[30]=FILENAME;
		char INPUTF2[30]=FILENAME;
		freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
		freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
#endif
	int m, n;

	cin >> m >> n;
	char ld[505][505];
	REP(i,m)
	{
		REP(j,n)
		{
			cin >> ld[i][j];
		}
	}
	REP(j,m)
		f1[j][n - 1] = (ld[j][n - 1] == '.' ? 1 : 0);
	for (int i = n - 2; i >= 0; i--){
		REP(j,m){
			f1[j][i] = (ld[j][i] == '.' ? 1 + f1[j][i + 1] : 0);}}

	REP(j,m)
		f3[j][0] = (ld[j][0] == '.' ? 1 : 0);
	for (int i = 1; i <= n - 1; i++){
		REP(j,m){
			f3[j][i] = (ld[j][i] == '.' ? 1 + f3[j][i - 1] : 0);}}

	REP(j,n)
		f4[0][j] = (ld[0][j] == '.' ? 1 : 0);
	for (int i = 1; i <= m - 1; i++){
		REP(j,n){
			f4[i][j] = (ld[i][j] == '.' ? 1 + f4[i-1][j] : 0);}}

	REP(j,n)
		f2[m-1][j] = (ld[m-1][j] == '.' ? 1 : 0);
	for (int i = m-2; i>=0; i--){
		REP(j,n){
			f2[i][j] = (ld[i][j] == '.' ? 1 + f2[i+1][j] : 0);}}

	int area = 0, res = 0;
	REP(i1,m)
	{
		REP(i2,n)
		{
				for(int j1=i1+1;j1<=i1+f2[i1][i2]-1;j1++)
				{
					for(int j2=i2+1;j2<=i2+f1[i1][i2]-1;j2++)
					{
						if (f4[j1][j2]>=j1-i1+1&&f3[j1][j2]>=j2-i2+1) {//f3,f4 seems not necessary. can use f1,f2 only. CtCi 18.11
							if (2 * ((j1 - i1) + (j2 - i2)) > res) {
								res=2 * ((j1 - i1) + (j2 - i2));
							}

						}
					}
				}
		}
	}
	if (res == 0)
		cout << string("impossible");
	else
		cout << res;

}
