/*
C. Ciel and Robot
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fox Ciel has a robot on a 2D plane. Initially it is located in (0, 0). Fox Ciel code a command to it. The command was represented by string s. Each character of s is one move operation. There are four move operations at all:

'U': go up, (x, y)  →  (x, y+1);
'D': go down, (x, y)  →  (x, y-1);
'L': go left, (x, y)  →  (x-1, y);
'R': go right, (x, y)  →  (x+1, y).
The robot will do the operations in s from left to right, and repeat it infinite times. Help Fox Ciel to determine if after some steps the robot will located in (a, b).

Input
The first line contains two integers a and b, ( - 109 ≤ a, b ≤ 109). The second line contains a string s (1 ≤ |s| ≤ 100, s only contains characters 'U', 'D', 'L', 'R') — the command.

Output
Print "Yes" if the robot will be located at (a, b), and "No" otherwise.

Sample test(s)
input
2 2
RU
output
Yes
input
1 2
RU
output
No
input
-1 1000000000
LRRLU
output
Yes
input
0 0
D
output
Yes
Note
In the first and second test case, command string is "RU", so the robot will go right, then go up, then right, and then up and so on.

The locations of its moves are (0, 0)  →  (1, 0)  →  (1, 1)  →  (2, 1)  →  (2, 2)  →  ...

So it can reach (2, 2) but not (1, 2).
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

typedef long long LL;
typedef long double LD;

void main2() {

}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	int x = 0, y = 0;
	string up ("UD");
	string lt ("LR");
	string down ("DU");
	string rt ("RL");
	int m1 = 0, m2 = 0;
	if (a < 0)
		m1 = 1;
	if (b < 0)
		m2 = 1;
	REP(i,s.size())
	{
		if (s[i] == up[m2])
			y++;
		if (s[i] == down[m2])
			y--;
		if (s[i] == lt[m1])
			x--;
		if (s[i] == rt[m1])
			x++;
	}
	a = abs(a);
	b = abs(b);
	LL t=1e10;
	if ((a > 100&&x<=0) || (b > 100&&y<=0)) {
			cout << "No" << endl;
			return 0;
	}
	if(a>100&&x>0){
		t = (LL) ((a - 100) / (x+1e-15));//doesnot devide by 0

	}
	if(b>100&&y>0)
		t =min(t, (LL) ((b - 100) / (y+1e-15)));
	if(t!=1e10){
	a -= x * t;
	b -= y * t;
	}
	REP(j,205)
	{

		REP(i,s.size()){
			if(a==0&&b==0){
						cout << "Yes" << endl;
						return 0;
					}
		if (s[i] == up[m2])
			b--;
		if (s[i] == down[m2])
			b++;
		if (s[i] == lt[m1])
			a++;
		if (s[i] == rt[m1])
			a--;

		}
	}
	cout << "No" << endl;
}

