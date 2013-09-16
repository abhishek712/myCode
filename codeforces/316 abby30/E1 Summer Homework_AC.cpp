/*

E1. Summer Homework


time limit per test:
3 seconds

memory limit per test:
256 megabytes

input:
standard input

output:
standard output

By the age of three Smart Beaver mastered all arithmetic operations and got this summer homework from the amazed teacher:

You are given a sequence of integers a1, a2, ..., an. Your task is to perform on it m consecutive operations of the following type:

1. For given numbers xi and vi assign value vi to element axi.
2. For given numbers li and ri you've got to calculate sum , where f0 = f1 = 1 and at i ≥ 2: fi = fi - 1 + fi - 2.
3. For a group of three numbers li ri di you should increase value ax by di for all x (li ≤ x ≤ ri).


Smart Beaver planned a tour around great Canadian lakes, so he asked you to help him solve the given problem.


Input

The first line contains two integers n and m (1 ≤ n, m ≤ 2·105) — the number of integers in the sequence and the number of operations, correspondingly. The second line contains n integers a1, a2, ..., an (0 ≤ ai ≤ 105). Then follow m lines, each describes an operation. Each line starts with an integer ti (1 ≤ ti ≤ 3) — the operation type:
• if ti = 1, then next follow two integers xi vi (1 ≤ xi ≤ n, 0 ≤ vi ≤ 105);
• if ti = 2, then next follow two integers li ri (1 ≤ li ≤ ri ≤ n);
• if ti = 3, then next follow three integers li ri di (1 ≤ li ≤ ri ≤ n, 0 ≤ di ≤ 105).


The input limits for scoring 30 points are (subproblem E1):
• It is guaranteed that n does not exceed 100, m does not exceed 10000 and there will be no queries of the 3-rd type.


The input limits for scoring 70 points are (subproblems E1+E2):
• It is guaranteed that there will be queries of the 1-st and 2-nd type only.


The input limits for scoring 100 points are (subproblems E1+E2+E3):
• No extra limitations.



Output

For each query print the calculated sum modulo 1000000000 (109).


Sample test(s)



Input
5 5
1 3 1 2 4
2 1 4
2 1 5
2 2 4
1 3 10
2 1 5



Output
12
32
8
50



Input
5 4
1 3 1 2 4
3 1 4 1
2 2 4
1 2 10
2 1 5



Output
12
45

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

int n,m;
int a[104];
int b[104];
LL ans;

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	cin>>n>>m;
	b[0]=1;b[1]=1;
	FOR(i,2,103)b[i]=(b[i-1]+b[i-2])%(LL)1e9;
	REP(i,n)
	 	 cin>>a[i];
	REP(i,m){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		if(t1==1){
			a[t2-1]=t3;
		}
		else{
			ans=0;
			REP(j,t3-t2+1)
				ans=(ans+(LL)a[t2+j-1]*b[j])%(LL)1e9;
			cout<<ans<<endl;
		}
	}

}
