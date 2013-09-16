/*
 A. Sereja and Bottles
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sereja and his friends went to a picnic. The guys had n soda bottles just for it. Sereja forgot the bottle opener as usual, so the guys had to come up with another way to open bottles.

Sereja knows that the i-th bottle is from brand ai, besides, you can use it to open other bottles of brand bi. You can use one bottle to open multiple other bottles. Sereja can open bottle with opened bottle or closed bottle.

Knowing this, Sereja wants to find out the number of bottles they've got that they won't be able to open in any way. Help him and find this number.

Input
The first line contains integer n (1 ≤ n ≤ 100) — the number of bottles. The next n lines contain the bottles' description. The i-th line contains two integers ai, bi (1 ≤ ai, bi ≤ 1000) — the description of the i-th bottle.

Output
In a single line print a single integer — the answer to the problem.

Sample test(s)
input
4
1 1
2 2
3 3
4 4
output
4
input
4
1 2
2 3
3 4
4 1
output
0
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
int a[105],b[105];
multiset<int> s;

int main() {
	int n;
	cin>>n;
	REP(i,n)cin>>a[i]>>b[i];
	REP(i,n)s.insert(b[i]);
	int ans=n;
	REP(i,n)if(s.count(a[i])>1||(s.count(a[i])==1&&b[i]!=a[i]))ans--;
	cout<<ans<<endl;

}

