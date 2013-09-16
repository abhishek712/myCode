/*
C. Magic Five
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a long plate s containing n digits. Iahub wants to delete some digits (possibly none, but he is not allowed to delete all the digits) to form his "magic number" on the plate, a number that is divisible by 5. Note that, the resulting number may contain leading zeros.

Now Iahub wants to count the number of ways he can obtain magic number, modulo 1000000007 (109 + 7). Two ways are different, if the set of deleted positions in s differs.

Look at the input part of the statement, s is given in a special form.

Input
In the first line you're given a string a (1 ≤ |a| ≤ 105), containing digits only. In the second line you're given an integer k (1 ≤ k ≤ 109). The plate s is formed by concatenating k copies of a together. That is n = |a|·k.

Output
Print a single integer — the required number of ways modulo 1000000007 (109 + 7).

Sample test(s)
input
1256
1
output
4
input
13990
2
output
528
input
555
2
output
63
Note
In the first case, there are four possible ways to make a number that is divisible by 5: 5, 15, 25 and 125.

In the second case, remember to concatenate the copies of a. The actual plate is 1399013990.

In the third case, except deleting all digits, any choice will do. Therefore there are 26 - 1 = 63 possible ways to delete digits.
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
#define MOD 1000000007

typedef long long ll;
long long m[100005];
long long m3;
long long m2[50];
string s;

long long solve(long long k){//2^k mode MOD
	long long ans=1;
	int i=1;
	long long temp=2;
	while(k!=0){
		if(k%2==1)ans=(ans*temp)%MOD;
		k/=2;i++;
		temp=(temp*temp)%MOD;
	}
	return ans;
}

//directly calculate 1+2^a+2^2a+2^3a....2^(k-1)a
//an easier solution is using module inverse which I don't use here
int main() {
	cin>>s;
	int a=s.size();
	int k;
	cin>>k;
	m[0]=1;
	REP(i,100000)m[i+1]=(2*m[i])%MOD;
	long long temp=m[a];
	m2[0]=1;
	int y=1;
	for(long long i=1LL;i<=k;i=i<<1){//m2[i]=1+2^1+2^2+2^3+...2^(2^i-1) mod MOD
		m2[y]=(m2[y-1]+temp*m2[y-1])%MOD;
		temp=(temp*temp)%MOD;
		y++;
	}
	m3=0;
	long long x=1;
	int num=0;
	while(x<=k){x=x<<1;num++;}
	x=x>>1;num--;
	long long k2=k;
	while(k2!=0){
		if(k2>=x){m3=(m3+m2[num]*solve((k-k2)*a))%MOD;k2-=x;}
		x=x>>1;num--;
	}
	long long ans=0;
	REP(i,a){
		if(s[i]=='0'||s[i]=='5'){
			ans=(ans+m[i]*m3)%MOD;
		}
	}
	cout<<ans<<endl;
}
