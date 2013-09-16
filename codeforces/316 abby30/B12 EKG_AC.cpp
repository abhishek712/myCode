/*

B1. EKG


time limit per test:
1 second

memory limit per test:
256 megabytes

input:
standard input

output:
standard output

In the rush of modern life, people often forget how beautiful the world is. The time to enjoy those around them is so little that some even stand in queues to several rooms at the same time in the clinic, running from one queue to another.

(Cultural note: standing in huge and disorganized queues for hours is a native tradition in Russia, dating back to the Soviet period. Queues can resemble crowds rather than lines. Not to get lost in such a queue, a person should follow a strict survival technique: you approach the queue and ask who the last person is, somebody answers and you join the crowd. Now you're the last person in the queue till somebody else shows up. You keep an eye on the one who was last before you as he is your only chance to get to your destination) I'm sure many people have had the problem when a stranger asks who the last person in the queue is and even dares to hint that he will be the last in the queue and then bolts away to some unknown destination. These are the representatives of the modern world, in which the ratio of lack of time is so great that they do not even watch foreign top-rated TV series. Such people often create problems in queues, because the newcomer does not see the last person in the queue and takes a place after the "virtual" link in this chain, wondering where this legendary figure has left.

The Smart Beaver has been ill and he's made an appointment with a therapist. The doctor told the Beaver the sad news in a nutshell: it is necessary to do an electrocardiogram. The next day the Smart Beaver got up early, put on the famous TV series on download (three hours till the download's complete), clenched his teeth and bravely went to join a queue to the electrocardiogram room, which is notorious for the biggest queues at the clinic.

Having stood for about three hours in the queue, the Smart Beaver realized that many beavers had not seen who was supposed to stand in the queue before them and there was a huge mess. He came up to each beaver in the ECG room queue and asked who should be in front of him in the queue. If the beaver did not know his correct position in the queue, then it might be his turn to go get an ECG, or maybe he should wait for a long, long time...

As you've guessed, the Smart Beaver was in a hurry home, so he gave you all the necessary information for you to help him to determine what his number in the queue can be.


Input

The first line contains two integers n (1 ≤ n ≤ 103) and x (1 ≤ x ≤ n) — the number of beavers that stand in the queue and the Smart Beaver's number, correspondingly. All willing to get to the doctor are numbered from 1 to n.

The second line contains n integers a1, a2, ..., an (0 ≤ ai ≤ n) — the number of the beaver followed by the i-th beaver. If ai = 0, then the i-th beaver doesn't know who is should be in front of him. It is guaranteed that values ai are correct. That is there is no cycles in the dependencies. And any beaver is followed by at most one beaver in the queue.

The input limits for scoring 30 points are (subproblem B1):
• It is guaranteed that the number of zero elements ai doesn't exceed 20.


The input limits for scoring 100 points are (subproblems B1+B2):
• The number of zero elements ai is arbitrary.



Output

Print all possible positions of the Smart Beaver in the line in the increasing order.


Sample test(s)



Input
6 1
2 0 4 0 6 0



Output
2
4
6



Input
6 2
2 3 0 5 6 0



Output
2
5



Input
4 1
0 0 0 0



Output
1
2
3
4



Input
6 2
0 0 1 0 4 5



Output
1
3
4
6

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

int n,x;
int a[1005];
bool c[1005];
int pos=1;
VI b;
set<int> comb;

int visit(int m){
	if(a[m]==0)return m==x?9999:1;
	int ans=1+visit(a[m]);
	if(m==x)
	{
		pos=ans;
		return 9999;
	}
	return ans;
}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	cin>>n>>x;
	REP(i,n){
		cin>>a[i+1];
		c[a[i+1]]=1;
	}
	REP(i,n){
		if(c[i+1]==0){
			int t=visit(i+1);
			if(t<9999)b.PB(t);
		}
	}
	comb.insert(0);
	REP(i,b.size()){
		VI temp;
		set<int>::iterator beg=comb.begin();
		REP(j,comb.size()){
		temp.PB(*beg+b[i]);
		beg++;
		}
		comb.insert(temp.begin(),temp.end());
	}
	for(set<int>::iterator beg=comb.begin();beg!=comb.end();beg++){
		cout<<pos+*beg<<endl;
	}
}

