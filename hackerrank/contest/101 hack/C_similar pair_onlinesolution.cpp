/*
 * Similar Pair
You are given a tree where each node is labeled from 1, 2, бн, n. How many similar pairs(S) are there in this tree?

A pair (A,B) is a similar pair iff

node A is the ancestor of node B
abs(A - B) <= T.
Input format:
The first line of the input contains two integers n and T. This is followed by n-1 lines each containing two integers si and ei where node si is a parent to node ei.

Output format:
Output a single integer which denotes the number of similar pairs in the tree

Constraints:

1 <= n <= 100000
0 <= T <= n
1 <= si, ei <= n.

Sample Input:

5 2
3 2
3 1
1 4
1 5
Sample Output:

4
Explanation:
The similar pairs are: (3, 2) (3, 1) (3, 4) (3, 5)

You can have a look at the tree image here
 *
 *
 *
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, aib[200005];

inline int lsb(int & x){
    return x & -x;
}

void update(int val, int pos){
    for(int i = pos; i <= n * 2; i += lsb(i))
        aib[i] += val;
}

int query(int pos){
    int rval = 0;
    for(int i = pos; i > 0; i -= lsb(i))
        rval += aib[i];
    return rval;
}

vector<int> graph[100005];
int t, dad[100005];
long long ans;

void dfs(int x){
    ans += (long long)query(x + t) - query(x - t - 1);
    update(1, x);
    for(int i = 0; i < graph[x].size(); ++i)
        dfs(graph[x][i]);
    update(-1, x);
}

int main() {
    cin >> n >> t;
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        dad[y] = x;
        graph[x].push_back(y);
    }
    for(int i = 1; i <= n; ++i)
        if(!dad[i])
            dfs(i);
    cout << ans;
    return 0;
}
