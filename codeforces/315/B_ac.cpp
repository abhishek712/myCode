/*
 B. Sereja and Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sereja has got an array, consisting of n integers, a1, a2, ..., an. Sereja is an active boy, so he is now going to complete m operations. Each operation will have one of the three forms:

Make vi-th array element equal to xi. In other words, perform the assignment avi = xi.
Increase each array element by yi. In other words, perform n assignments ai = ai + yi (1 ≤ i ≤ n).
Take a piece of paper and write out the qi-th array element. That is, the element aqi.
Help Sereja, complete all his operations.

Input
The first line contains integers n, m (1 ≤ n, m ≤ 105). The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109) — the original array.

Next m lines describe operations, the i-th line describes the i-th operation. The first number in the i-th line is integer ti (1 ≤ ti ≤ 3) that represents the operation type. If ti = 1, then it is followed by two integers vi and xi, (1 ≤ vi ≤ n, 1 ≤ xi ≤ 109). If ti = 2, then it is followed by integer yi (1 ≤ yi ≤ 104). And if ti = 3, then it is followed by integer qi (1 ≤ qi ≤ n).

Output
For each third type operation print value aqi. Print the values in the order, in which the corresponding queries follow in the input.

Sample test(s)
input
10 11
1 2 3 4 5 6 7 8 9 10
3 2
3 9
2 10
3 1
3 10
1 1 10
2 10
2 10
3 1
3 10
3 9
output
2
9
11
20
30
40
39
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

int a[100005];

int main() {
	int n,m;
	cin>>n>>m;
	int add=0;
	REP(i,n)cin>>a[i];
	REP(i,m){
		int input;
		cin>>input;
		if(input==1){
			int x,y;
			cin>>x>>y;
			a[x-1]=y-add;
		}
		else if(input==2){
			int x;
			cin>>x;
			add+=x;
		}
		else{
			int x;
			cin>>x;
			cout<<a[x-1]+add<<endl;
		}
	}
}
