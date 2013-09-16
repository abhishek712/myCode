/*
Anagram
Sid is obsessed about reading short stories. Being a CS student, he is doing some interesting frequency analysis with the books. From two short story books, he choses strings having length a from the first and strings having length b from the second one. The strings are such that the difference of length is <= 1

i.e.

|a-b|<=1, where |x| represents a modulus function.
He believes that both the strings should be anagrams based on his experiment. Your challenge is to help him find the minimum number of characters of the first string he needs to change to make it an anagram of the second string. Neither can he add a character nor delete a character from the first string. Only replacement of the characters with new ones is allowed.

Input Format

First line will contain an integer T representing the number of test cases Each test case will contain a string having length (a+b) which will be concatenation of both the strings described in problem. The string will only contain small letters and without any spaces.

Output Format

An integer corresponding to each test case is printed in a different line i.e., the number of changes required for each test case. Print ¡®-1¡¯ if it is not possible.

Constraints

1<=T<=100
length of input string i.e. 1<=a+b<=10000

Sample Input

5
aaabbb
ab
abc
mnop
xyyx
Sample Output

3
1
-1
2
0
Explanation

In fifth test case, first string will be ¡°xy¡± while second string will be ¡°yx¡± . so a = 2 and b = 2, where a and b are length of strings. As we can see that a and b are following relation

|a-b|<=1
and both strings are anagrams.So number of changes required = 0.
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
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int n=s.size();
		if(n%2!=0){cout<<-1<<endl;continue;}
		multiset<char> st;
		REP(i,n/2){
			st.insert(s[i]);
		}
		int res=0;
		REP(i,n/2){
			if(st.count(s[i+n/2]))st.erase(st.find(s[i+n/2]));
			else res++;
		}
		cout<<res<<endl;

	}

}

