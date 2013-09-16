/*
 *  Cut Tree
Given a tree T with n nodes, how many subtrees (T¡¯) of T have at most K edges connected to (T - T¡¯)?

Input format
The first line contains two integers n and K followed by n-1 lines each containing two integers a & b denoting that there¡¯s an edge between a & b.

Output format
A single integer which denotes the number of possible subtrees.

Constraints
1 <= K <= n <= 50
Every node is indicated by a distinct number from 1 to n.

Sample input

3 1
2 1
2 3
Sample output

6
Explanation

There are 2^3 possible sub-trees:

{} {1} {2} {3} {1, 2} {1, 3} {2, 3} {1, 2, 3}

But:
the sub-trees {2} and {1,3} are not valid. {2} isn¡¯t valid because it has 2 edges connecting to it¡¯s complement {1,3} whereas K = 1 in the sample test-case {1,3} isn¡¯t valid because, well, it¡¯s not a sub-tree. The nodes aren¡¯t connected.
 */
#include<iostream>
#include<string.h>
using namespace std;

#define MAXN 100
int first[MAXN], next1[MAXN], v[MAXN];
int edgeindex;
int n, k;
long long dp[MAXN][MAXN];
bool vis[MAXN];

void addedge(int a, int b)
{
	v[edgeindex] = b;
	next1[edgeindex] = first[a];
	first[a] = edgeindex++;
}

void solve(int cur, int root)
{
	if(vis[cur])
	    return;

	for(int i = first[cur]; i != -1; i = next1[i])
	{
		if(v[i] == root)
			continue;
		solve(v[i], cur);
		for(int j = k; j > 0; --j)
		{
			int tmp = 0;
			for(int x = j; x > 0; x--)
			{
				dp[cur][j] += dp[cur][j-x] * dp[v[i]][x];
			}
			dp[cur][j] += dp[cur][j-1];
		}
	}
	return;
}

int main()
{
	while(cin>>n>>k)
	{
		edgeindex = 0;
		memset(first, -1, sizeof(first));
		memset(dp, 0, sizeof(dp));
		memset(vis, false, sizeof(vis));
		int a, b;
		for(int i = 1; i < n; ++i)
		{
			cin>>a>>b;
			addedge(a, b);
			addedge(b, a);
		}

		for(int i = 1; i <= n; ++i)
		{
			dp[i][0] = 1;
		}

		solve(1, -1);

		long long ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 0; j < k; ++j)
			{
				ans += dp[i][j];
			}
		}
		ans += dp[1][k];
		cout<<ans+1<<endl;
	}
}
