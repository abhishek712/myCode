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
int temp;

int main() {
	int b, d;
	cin >> b >> d;
	string a, c;
	cin >> a >> c;
	int sza = a.size(), szc = c.size();
	int i = 0, j = 0, numa = 1, numc = 1;
	while (i<sza*b) {
		if(i%sza==0){
		if(i>=sza&&temp==j){cout<<0<<endl;return 0;}
		temp=j;
		}
		if (a[i%sza] == c[j%szc]) {
			j++;
		}
		i++;
		if (i%sza == 0&& j%szc == 0)
					break;
	}
	numa=(i)/sza;
	numc=(j)/szc;
	int ans = b / numa * numc;
	b = b % numa;
	i = 0, j = 0;
	REP(k,b*sza)
	{
		if (a[k%sza] == c[j]) {
			j++;
			if (j >= szc) {
				j -= szc;
				ans++;
			}
		}
	}
	cout<<ans/d<<endl;

}
