/*
B. Ciel and Flowers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fox Ciel has some flowers: r red flowers, g green flowers and b blue flowers. She wants to use these flowers to make several bouquets. There are 4 types of bouquets:

To make a "red bouquet", it needs 3 red flowers.
To make a "green bouquet", it needs 3 green flowers.
To make a "blue bouquet", it needs 3 blue flowers.
To make a "mixing bouquet", it needs 1 red, 1 green and 1 blue flower.
Help Fox Ciel to find the maximal number of bouquets she can make.

Input
The first line contains three integers r, g and b (0 ≤ r, g, b ≤ 109) — the number of red, green and blue flowers.

Output
Print the maximal number of bouquets Fox Ciel can make.

Sample test(s)
input
3 6 9
output
6
input
4 4 4
output
4
input
0 0 0
output
0
Note
In test case 1, we can make 1 red bouquet, 2 green bouquets and 3 blue bouquets.

In test case 2, we can make 1 red, 1 green, 1 blue and 1 mixing bouquet.
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

#define MX 110

typedef long long LL;
typedef long double LD;




int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	LL a[3];
	LL res=0;
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	REP(i,min(3LL,a[0]+1))
		res=max(res,i+(a[0]-i)/3+(a[1]-i)/3+(a[2]-i)/3);
	cout<<res<<endl;


}

