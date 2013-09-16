/*
 * Equal
Christy is interning at HackerRank. One day she had to distribute some chocolates to her colleagues. Biased as she was towards her friends, she may have distributed the chocolates unequally. One of the program managers on getting to know this ordered Christy to make sure everyone got equal number of chocolates.

But to make things difficult for the intern, she was ordered to equalize the number of chocolates for every colleague in the following manner,

For every operation, she can choose one of her colleagues and can do one of the three things.
(i) She can give one chocolate to every colleague other than chosen one.
(ii) She can give two chocolates to every colleague other than chosen one.
(iii) She can give five chocolates to every colleague other than chosen one.

You have to calculate minimum number of such operations needed before every colleague will have the same number of chocolates.

Input Format

1st line contains an integer T denoting the number of testcases. T testcases follow.
Each testcase has 2 lines. 1st line of each testcase has an integer N denoting the number of co-interns. The 2nd line has N integers denoting the number of chocolates each one has currently separated by a single space.

Output Format

T lines, each containing the minimum number of operations needed to make sure all colleagues have the same number of chocolates.

Constraints

1<=T<=100
0<=N<=10000
Number of initial chocolates each intern has < 1000

Sample Input

1
4
2 2 3 7
Sample Output

2
Explanation

First operation Christy increases all elements by 1 except 3rd one
2 2 3 7 -> 3 3 3 8
In second operation Christy increases all element by 5 except last one
3 3 3 8 -> 8 8 8 8
 *
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x[10005];

int solve(int a){
    int ans=0;
    for(int i=0;i<n;i++){
        int temp=x[i]-a;
        ans+=temp/5+temp%5/2+temp%5%2;
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  int t;
    cin>>t;
    while(t--){
        cin>>n;
        int mi=1000;
        for(int i=0;i<n;i++){cin>>x[i];mi=min(mi,x[i]);}
        int res=1e9;
        for(int i=0;i<5;i++)res=min(res,solve(mi-i));
        cout<<res<<endl;
    }


    return 0;
}
