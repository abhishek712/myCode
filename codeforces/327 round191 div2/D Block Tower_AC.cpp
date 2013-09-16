/*
D. Block Tower
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
After too much playing on paper, Iahub has switched to computer games. The game he plays is called "Block Towers". It is played in a rectangular grid with n rows and m columns (it contains n × m cells). The goal of the game is to build your own city. Some cells in the grid are big holes, where Iahub can't build any building. The rest of cells are empty. In some empty cell Iahub can build exactly one tower of two following types:

Blue towers. Each has population limit equal to 100.
Red towers. Each has population limit equal to 200. However, it can be built in some cell only if in that moment at least one of the neighbouring cells has a Blue Tower. Two cells are neighbours is they share a side.
Iahub is also allowed to destroy a building from any cell. He can do this operation as much as he wants. After destroying a building, the other buildings are not influenced, and the destroyed cell becomes empty (so Iahub can build a tower in this cell if needed, see the second example for such a case).

Iahub can convince as many population as he wants to come into his city. So he needs to configure his city to allow maximum population possible. Therefore he should find a sequence of operations that builds the city in an optimal way, so that total population limit is as large as possible.

He says he's the best at this game, but he doesn't have the optimal solution. Write a program that calculates the optimal one, to show him that he's not as good as he thinks.

Input
The first line of the input contains two integers n and m (1 ≤ n, m ≤ 500). Each of the next n lines contains m characters, describing the grid. The j-th character in the i-th line is '.' if you're allowed to build at the cell with coordinates (i, j) a tower (empty cell) or '#' if there is a big hole there.

Output
Print an integer k in the first line (0 ≤ k ≤ 106) — the number of operations Iahub should perform to obtain optimal result.

Each of the following k lines must contain a single operation in the following format:

«B x y» (1 ≤ x ≤ n, 1 ≤ y ≤ m) — building a blue tower at the cell (x, y);
«R x y» (1 ≤ x ≤ n, 1 ≤ y ≤ m) — building a red tower at the cell (x, y);
«D x y» (1 ≤ x ≤ n, 1 ≤ y ≤ m) — destroying a tower at the cell (x, y).
If there are multiple solutions you can output any of them. Note, that you shouldn't minimize the number of operations.

Sample test(s)
input
2 3
..#
.#.
output
4
B 1 1
R 1 2
R 2 1
B 2 3
input
1 3
...
output
5
B 1 1
B 1 2
R 1 3
D 1 2
R 1 2
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
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)

typedef long long ll;
char bd[505][502];
int res;
int s[100005][3];

void dfs(int x,int y){
	stack<pair<int, int> > q;
	stack<pair<int, int> > q2;
	q.push(make_pair(x,y));
	while(!q.empty()){
		pair<int,int> p=q.top();
		q.pop();
		if(bd[p.first][p.second]!='.')continue;
		q2.push(p);
		bd[p.first][p.second]='B';
		s[res][0]=(int)'B';s[res][1]=p.first;s[res][2]=p.second;
		res++;
		//cout<<"B "<<p.first<<" "<<p.second<<endl;
		if(bd[p.first+1][p.second]=='.')q.push(make_pair(p.first+1,p.second));
		if(bd[p.first-1][p.second]=='.')q.push(make_pair(p.first-1,p.second));
		if(bd[p.first][p.second+1]=='.')q.push(make_pair(p.first,p.second+1));
		if(bd[p.first][p.second-1]=='.')q.push(make_pair(p.first,p.second-1));
	}
	while(q2.size()!=1){
		pair<int,int> p=q2.top();
		q2.pop();
		bd[p.first][p.second]='R';
		s[res][0]=(int)'D';s[res][1]=p.first;s[res][2]=p.second;
		res++;
		s[res][0]=(int)'R';s[res][1]=p.first;s[res][2]=p.second;
		res++;
		//cout<<"D "<<p.first<<" "<<p.second<<endl;
	//	cout<<"R "<<p.first<<" "<<p.second<<endl;
	}
}

int n,m;
int main() {
	int n,m;
	cin>>n>>m;
	REP(i,n)REP(j,m)cin>>bd[i+1][j+1];
	REP(i,n)REP(j,m){
		if(bd[i+1][j+1]=='.')dfs(i+1,j+1);
	}
	cout<<res<<endl;
	REP(i,res){
		cout<<(char)s[i][0]<<" "<<s[i][1]<<" "<<s[i][2]<<endl;
	}

}

