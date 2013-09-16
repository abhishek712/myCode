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

#define OPENFILE
#define FILENAME "A-large-practice"

#define MX 110

typedef long long LL;
typedef long double LD;

string dia[MX];
int k;

bool checkVer(int x) {
	bool ans = 1;
	REP(i,2*k-1)
	{
		for (int j = 1; (x + j) < 2 * k - 1 && (x - j) >= 0; j++) {
			if (dia[i][x + j] != dia[i][x - j]&&dia[i][x + j]!=' '&&dia[i][x - j]!=' ') {
				ans = 0;
				return ans;
			}
		}
	}
	return ans;
}

bool checkHor(int x) {
	bool ans = 1;
	REP(i,2*k-1)
	{
		for (int j = 1; (x + j) < 2 * k - 1 && (x - j) >= 0; j++) {
			if (dia[x + j][i] != dia[x - j][i]&&dia[x + j][i]!=' '&&dia[x - j][i]!=' ') {
				ans = 0;
				return ans;
			}
		}
	}
	return ans;
}

void main2() {
	cin >> k;
	getchar();
	REP(i,2*k-1)
	{

		getline(cin, dia[i]);
		while ((int) dia[i].size() < 2 * k - 1)
			dia[i] += ' ';
	}
	int m = k - 1, n = k - 1;
	REP(i,k)
	{
		if (checkVer(m + i)||checkVer(m - i)) {
			m +=i;
			break;
		}
	}
	REP(i,k)
	{
		if (checkHor(n + i)||checkHor(n - i)) {
			n += i;
			break;
		}
	}
	if(m==k-1&&n==k-1)cout<<'0'<<endl;
	else cout<<(m+n-k+1+1)*(m+n-k+1+1)-k*k<<endl;




}

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	int TN;
	cin >> TN;
	REP(tn,TN)
	{
		printf("Case #%I64d: ", tn + 1);
		cerr << tn + 1 << endl;
		main2();
		fflush(stdout);
	}
}
