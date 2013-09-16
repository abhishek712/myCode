/*
 *
A. Magic Numbers


time limit per test:
2 seconds

memory limit per test:
256 megabytes

input:
standard input

output:
standard output

A magic number is a number formed by concatenation of numbers 1, 14 and 144. We can use each of these numbers any number of times. Therefore 14144, 141414 and 1411 are magic numbers but 1444, 514 and 414 are not.

You're given a number. Determine if it is a magic number or not.


Input

The first line of input contains an integer n, (1 ≤ n ≤ 109). This number doesn't contain leading zeros.


Output

Print "YES" if n is a magic number or print "NO" if it's not.


Sample test(s)



Input
114114



Output
YES



Input
1111



Output
YES



Input
441231



Output
NO
 *
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
	string s;
	cin>>s;
	int temp=0;
	bool b=1;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]=='1'){temp=0;continue;}
		else if(s[i]=='4'){
			if(temp<=1)temp++;
			else{ b=0;break;}
		}
		else{
			b=0;
			break;
		}
	}
	if(temp!=0)b=0;
	if(b)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}
