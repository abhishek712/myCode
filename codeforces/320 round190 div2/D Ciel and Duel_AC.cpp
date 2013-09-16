/*
D. Ciel and Duel
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fox Ciel is playing a card game with her friend Jiro.

Jiro has n cards, each one has two attributes: position (Attack or Defense) and strength. Fox Ciel has m cards, each one has these two attributes too. It's known that position of all Ciel's cards is Attack.

Now is Ciel's battle phase, Ciel can do the following operation many times:

Choose one of her cards X. This card mustn't be chosen before.
If Jiro has no alive cards at that moment, he gets the damage equal to (X's strength). Otherwise, Ciel needs to choose one Jiro's alive card Y, then:
If Y's position is Attack, then (X's strength)  ≥  (Y's strength) must hold. After this attack, card Y dies, and Jiro gets the damage equal to (X's strength) - (Y's strength).
If Y's position is Defense, then (X's strength)  >  (Y's strength) must hold. After this attack, card Y dies, but Jiro gets no damage.
Ciel can end her battle phase at any moment (so, she can use not all her cards). Help the Fox to calculate the maximal sum of damage Jiro can get.

Input
The first line contains two integers n and m (1 ≤ n, m ≤ 100) — the number of cards Jiro and Ciel have.

Each of the next n lines contains a string position and an integer strength (0 ≤ strength ≤ 8000) — the position and strength of Jiro's current card. Position is the string "ATK" for attack, and the string "DEF" for defense.

Each of the next m lines contains an integer strength (0 ≤ strength ≤ 8000) — the strength of Ciel's current card.

Output
Output an integer: the maximal damage Jiro can get.

Sample test(s)
input
2 3
ATK 2000
DEF 1700
2500
2500
2500
output
3000
input
3 4
ATK 10
ATK 100
ATK 1000
1
11
101
1001
output
992
input
2 4
DEF 0
ATK 0
0
0
1
1
output
1
Note
In the first test case, Ciel has 3 cards with same strength. The best strategy is as follows. First she uses one of these 3 cards to attack "ATK 2000" card first, this attack destroys that card and Jiro gets 2500 - 2000 = 500 damage. Then she uses the second card to destroy the "DEF 1700" card. Jiro doesn't get damage that time. Now Jiro has no cards so she can use the third card to attack and Jiro gets 2500 damage. So the answer is 500 + 2500 = 3000.

In the second test case, she should use the "1001" card to attack the "ATK 100" card, then use the "101" card to attack the "ATK 10" card. Now Ciel still has cards but she can choose to end her battle phase. The total damage equals (1001 - 100) + (101 - 10) = 992.

In the third test case note that she can destroy the "ATK 0" card by a card with strength equal to 0, but she can't destroy a "DEF 0" card with that card.
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


int at[MX];
int df[MX];
int c[MX];
int a,d;

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout);//redirects standard output
#endif
	cout.precision(15);
	int n,m;
	cin>>n>>m;
	a=0;d=0;
	REP(i,n){
		string s;
		cin>>s;
		int input;
		cin>>input;
		if(s=="ATK")at[a++]=input;
		if(s=="DEF")df[d++]=input;
	}
	REP(i,m)cin>>c[i];
	sort(at,at+a);
	sort(df,df+d);
	sort(c,c+m);
	int res1=0,res2=0;
	int i=0,j=m-1;
	while(c[j]>at[i]&&i<a&&j>=0){
		res1+=c[j]-at[i];
		j--;i++;
	}
	multiset<int> s;
	REP(i,m)s.insert(c[i]);
	i=0;j=0;
	while(i<d&&j<m){
		if(c[j]<=df[i])j++;
		else{
			if(s.count(c[j]))s.erase(s.lower_bound(c[j]));
			i++;
			j++;
		}
	}
	if(j==m&&i!=d){cout<<res1<<endl;return 0;}
	i=0;j=0;
	multiset<int>::iterator it=s.begin();
	while(i<a&&it!=s.end()){
		if(*it<at[i])it++;
		else{
			i++;
			it++;
		}
	}
	if(it==s.end()&&i!=a){cout<<res1<<endl;return 0;}
	for(it=s.begin();it!=s.end();it++)
		res2+=*it;
	REP(i,a)
		res2-=at[i];
	cout<<max(res1,res2)<<endl;

}



