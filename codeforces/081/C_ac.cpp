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

typedef long long LL;

int m[100005];

int main() {
	//freopen("small.in", "r", stdin); //redirects standard input
	//freopen("small.out", "w", stdout);//redirects standard output
	int n, a, b;
	cin >> n >> a >> b;
	REP(i,n)
		cin >> m[i];
	int small = a <= b ? 1 : 2;
	if (a < b) {
		REP(i,5)
			REP(j,n)
			{
				if (m[j] == 5 - i) {
					m[j] = -1;
					a--;
					if (a == 0)
						goto done;
				}
			}
	} else if(a>b){
		REP(i,5)
			for (int j = n - 1; j >= 0; j--) {
				if (m[j] == 5 - i) {
					m[j] = -1;
					b--;
					if (b == 0)
						goto done;
				}
			}
	}
	done: ;
	if (a != b) {
		REP(i,n)
		{
			if (m[i] == -1)
				cout << small << " ";
			else
				cout << 3 - small << " ";
		}
	} else {
		REP(i,a)cout<<1<<" ";
		REP(i,b)cout<<2<<" ";
	}
}
