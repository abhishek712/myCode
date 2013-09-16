/*

Ice Cream Parlor


Max Score: 30




Sunny and Johnny together have C dollars which they intend to use at the ice cream parlour. Among L flavors available, they have to choose two distinct flavors whose cost equals C. Given a list of cost of L flavors, output the indices of two items whose sum equals C. The cost of a flavor (Li) will be no more than 10000.

Input Format

The first line of the input contains T, T test cases follow.
 Each test case follows the format: The first line contains C. The second line contains the number L. The third line contains L single space separated integers denoting the price of each flavor.

Output Format

Output two integers, each of which is a valid index of the flavor. The lower index must be printed first. Indices are indexed from 1 to L.

Constraints

1 ¡Ü T ¡Ü 50
 2 ¡Ü C ¡Ü 10000
 2 ¡Ü L ¡Ü 10000
 1 ¡Ü Li ¡Ü 10000 The prices of two items may be same and each test case has a unique solution.

Sample Input
2
4
5
1 4 5 3 2
4
4
2 2 4 3


Sample Output
1 4
1 2


Explanation

The sample input has two test cases. For the 1st, the amount C = 4 and there are 5 flavors at the store. The flavors indexed at 1 and 4 sums to 4. For the 2nd test case, the amount C = 4 and the flavors indexed at 1 and 2 sums to 4.
*/

#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <math.h>
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

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
//#define OPENFILE
#define FILENAME "small"

typedef long long ll;
int a[10004];

int main() {
#ifdef OPENFILE
		char INPUTF[30]=FILENAME;
		char INPUTF2[30]=FILENAME;
		freopen(strcat(INPUTF,".in"),"r",stdin);//redirects standard input
		freopen(strcat(INPUTF2,".out"),"w",stdout);//redirects standard output
#endif
	int T;
	cin>>T;
	REP(t,T){
		memset(a,0,sizeof(a));
		int C,L;
		cin>>C>>L;
		REP(l,L){

			int input;
			cin>>input;
			if(C-input>0&&a[C-input]!=0){
				printf("%d %d\n",a[C-input],l+1);
				REP(i,L-l-1){
					cin>>input;
				}
				goto done;
			}
			else
				a[input]=l+1;
		}
		//fprintf (stderr, "Case #%d: %f\n",t+1,res);
		done:;
	}

}
