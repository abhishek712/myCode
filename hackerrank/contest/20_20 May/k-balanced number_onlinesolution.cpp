/*
 * k-balance number
Your task is to calculate the sum (indicated by S) of all the k-balanced integers between [L, R]. An integer is called k-balanced when either of #1 or #2 below holds true.

The length of the integer <= k
Sum of the first k digits (with no leading zeros) is equal to the sum of the last k digits.
Input format
L R k

Output format
S % 1000000007

Constraints
0 < L <= R < 10^18
0 < k <= 18

Sample Input
9 23 1

Sample Output
42

Explanation
9, 11 and 22 are the only 3 integers between 9 and 23 ( both included ) that are k-balanced. Hence, the answer is 9+11+22=42
 *
 */
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


/* Prewritten code begins */
#define LL          long long
#define FILL(a,v)   memset(a,v,sizeof(a))
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
/* Prewritten code ends */

const int MOD = 1000000007, maxD = 18;
int D[maxD], pot[maxD+1] = {1,}, nD, K;
inline void inc_mod(int &a, int b) {
	if((a += b) >= MOD) a -= MOD;
}
int mem_g[maxD+1][maxD+1][2][maxD*2*9+1];
int mem_suma[maxD+1][maxD+1][2][maxD*2*9+1];
int g(int pos, int nzpos, int lo, int sum) {
	int &res = mem_g[pos][nzpos][lo][sum+maxD*9];
	if(res >= 0) return res;
	res = 0;
	if(pos == nD) return res = sum == 0;
	for(int d = lo ? 9 : D[pos]; d >= 0; d--) {
		int tsum = sum;
		int tnzpos = nzpos ? nzpos+1 : d > 0 ? 1 : 0;
		if( tnzpos <= K) tsum += d;
		if( nD-pos <= K) tsum -= d;
		inc_mod(res, g(pos+1, tnzpos, lo || d < D[pos], tsum));
	}
	return res;
}
int suma(int pos, int nzpos, int lo, int sum) {
	int &res = mem_suma[pos][nzpos][lo][sum+maxD*9];
	if(res >= 0) return res;
	res = 0;
	if(pos == nD) return res;
	for(int d = lo ? 9 : D[pos]; d >= 0; d--) {
		int tsum = sum;
		int tnzpos = nzpos ? nzpos+1 : d > 0 ? 1 : 0;
		if( tnzpos <= K) tsum += d;
		if( nD-pos <= K) tsum -= d;
		int cnt = g(pos+1, tnzpos, lo || d < D[pos], tsum);
		inc_mod(res, (LL)d*cnt*pot[nD-1-pos]%MOD);
		inc_mod(res, suma(pos+1, tnzpos, lo || d < D[pos], tsum));
	}
	return res;
}
int f(LL x) {
	FILL(mem_g, 0xFF);
	FILL(mem_suma, 0xFF);

	LL tx = x; nD = 0;
	do {
		D[nD++] = tx%10;
		tx /= 10;
	} while(tx);
	reverse(D,D+nD);

	return suma(0, 0, 0, 0);
}
int main() {
	FOR(i,1,maxD) pot[i] = 10LL*pot[i-1]%MOD;
	LL L, R;
	cin >> L >> R >> K;
	cout << (f(R)-f(L-1)+MOD)%MOD << endl;
	return 0;
}
