/*

B. Ping-Pong (Easy Version)


time limit per test:
2 seconds

memory limit per test:
256 megabytes

input:
standard input

output:
standard output

In this problem at each moment you have a set of intervals. You can move from interval (a, b) from our set to interval (c, d) from our set if and only if c < a < d or c < b < d. Also there is a path from interval I1 from our set to interval I2 from our set if there is a sequence of successive moves starting from I1 so that we can reach I2.

Your program should handle the queries of the following two types:

1. "1 x y" (x < y) — add the new interval (x, y) to the set of intervals. The length of the new interval is guaranteed to be strictly greater than all the previous intervals.


• "2 a b" (a ≠ b) — answer the question: is there a path from a-th (one-based) added interval to b-th (one-based) added interval?


Answer all the queries. Note, that initially you have an empty set of intervals.


Input

The first line of the input contains integer n denoting the number of queries, (1 ≤ n ≤ 100). Each of the following lines contains a query as described above. All numbers in the input are integers and don't exceed 109 by their absolute value.

It's guaranteed that all queries are correct.


Output

For each query of the second type print "YES" or "NO" on a separate line depending on the answer.


Sample test(s)



Input
5
1 1 5
1 5 11
2 1 2
1 2 9
2 1 2



Output
NO
YES

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

int itv[101][2];
int num;

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	int t;cin>>t;
	REP(i,t){
		int input;
		cin>>input;
		if(input==1){
			cin>>itv[num][0]>>itv[num][1];
			num++;
		}
		else if(input==2){
			int a,b;
			cin>>a>>b;
			a--;b--;
			queue<int> q;
			set<int> s;
			q.push(a);
			s.insert(a);
			while(!q.empty()){
				int temp=q.front();
				q.pop();
				REP(j,num){
					if(s.count(j)==0)
						if((itv[j][0]<itv[temp][0]&&itv[temp][0]<itv[j][1])||(itv[j][0]<itv[temp][1]&&itv[temp][1]<itv[j][1])){
							if(j==b){cout<<"YES"<<endl;goto e;}
							q.push(j);
							s.insert(j);
						}
				}
			}
			cout<<"NO"<<endl;
		}
		e:;
	}
}
