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
#define OPENFILE
#define FILENAME "B-large-practice"

typedef long long ll;

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	int T;
	cin >> T;
	REP(t,T)
	{
		string s;
		cin >> s;
		printf("Case #%d: ", t + 1);
		char c[25];

		REP(i,s.length())
			c[i] = s[i];
		if (!next_permutation(c, c + s.length())) {
			char a;
			REP(i,s.length())
			{
				if (c[i] != '0') {
					a = c[i];
					c[i] = '0';
					break;
				}
			}
			printf("%c", a);
			REP(i,s.length())
			{
				printf("%c", c[i]);
			}
			printf("\n");
		} else {
			REP(i,s.length())
			{
				printf("%c", c[i]);
			}
			printf("\n");
		}
		cerr << t + 1 << endl;
		fflush(stdout);
	}
}
