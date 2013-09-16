/*

A. Malek Dance Club


time limit per test:
1 second

memory limit per test:
256 megabytes

input:
standard input

output:
standard output

As a tradition, every year before IOI all the members of Natalia Fan Club are invited to Malek Dance Club to have a fun night together. Malek Dance Club has 2n members and coincidentally Natalia Fan Club also has 2n members. Each member of MDC is assigned a unique id i from 0 to 2n-1. The same holds for each member of NFC.

One of the parts of this tradition is one by one dance, where each member of MDC dances with a member of NFC. A dance pair is a pair of numbers (a,b) such that member a from MDC dances with member b from NFC.

The complexity of a pairs' assignment is the number of pairs of dancing pairs (a, b) and (c, d) such that a < c and b > d.

You are given a binary number of length n named x. We know that member i from MDC dances with member  from NFC. Your task is to calculate the complexity of this assignment modulo 1000000007 (109 + 7).

Expression  denotes applying «XOR» to numbers x and y. This operation exists in all modern programming languages, for example, in C++ and Java it denotes as «^», in Pascal — «xor».


Input

The first line of input contains a binary number x of lenght n, (1 ≤ n ≤ 100).

This number may contain leading zeros.


Output

Print the complexity of the given dance assignent modulo 1000000007 (109 + 7).

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
#define REP(i,n) for(LL i=0;i<(n);++i)
#define FOR(i,k,n) for (LL i=(k); i<=(LL)(n); ++i)
#define X first
#define Y second
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
typedef pair<int, int> PII;
typedef vector<int> VI;

//#define OPENFILE
#define FILENAME "small"

#define MOD 1000000007

typedef long long LL;
typedef long double LD;

LL m[201];

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	string s;
	cin >> s;
	int n=s.length();
	LL temp=1;
	REP(i,201){
		m[i]=temp;
		temp=(2*temp)%MOD;
	}
	LL ans=0;
	REP(i,n){
		if(s[i]=='1'){
			ans=(ans+m[2*n-i-2])%MOD;//2^i*2^(n-1)*2^(n-1)
		}
	}
	cout<<ans<<endl;

}
