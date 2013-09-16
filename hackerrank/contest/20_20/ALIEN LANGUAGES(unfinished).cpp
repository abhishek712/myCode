/*

Alien Languages


Max Score: 60




Josh has discovered several different alien languages. Suprisingly all of these languages have an alphabet, and each of them may contain thousands of characters! Also all words in a language have the same number of characters in it.

However, these aliens enjoy having their words be aesthetically pleasing, which for them means that all words have the requirement that for the ith letter of an n letter alphabet (letters are indexed at 1):

if 2*i > n

the ith letter may be the last letter of a word, and it may be immediately followed by any letter including itself.

if 2*i ¡Ü n

the ith letter can not be the last letter of a word and also can only be immediately followed by jth letter iff j ¡Ý 2*i.

Josh wants to know how many different words there can be in this language. Since the result may be large, he wants it modulo 100000007.

Input

The first line contains t, the number of test cases. The first line is followed by t lines, each line denoting a test case. Each test case will have two space separated integers n,m which denote the number of letters in the language and the length of words in this language respectively.

Output

For each testcase output on its own line the number of possible words modulo 100000007.

Constraints

1 ¡Ü t ¡Ü 5
 1 ¡Ü n ¡Ü 105
 1 ¡Ü m ¡Ü 5*105


Sample Input

3
 1 3
 2 3
 3 2


Sample Output

1
 3
 6


Explanation
 For the first test-case, there¡¯s one letter and all the words consist of 3 letters. There¡¯s only one possibility which is ¡°aaa¡±

For the second test-case, there are two letters (a & b) and all of the words are 3 letters. The possible ones are ¡°abb¡±, ¡°bab¡±, & ¡°bbb¡±. The words can end only with ¡®b¡¯ since 2 * index(b) = 2 * 2 > 2 and for ¡®a¡¯, it¡¯s 2 * index(a) = 2 * 1 <= 2. ¡°aab¡± is not allowed because ¡®a¡¯ can not be followed immediately by ¡®a¡¯. For a word of length 4 and alphabet size 2, ¡°abab¡± would be allowed.

For the third test-case, there are three letters (a, b & c) and all of the words are 2 letters. The words can end only with ¡®b¡¯ or ¡®c¡¯. The possible words are ¡°ab¡±, ¡°ac¡±, ¡°bb¡±, ¡°cc¡±, ¡°bc¡±, ¡°cb¡±
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
int size;
int module=1000000007;

ll M1[16][16],M2[16][16],M3[16][16],M4[16][16];;


void matrixM(ll a[][16],ll b [][16],ll c[][16]){
	memset(c,0,sizeof(ll)*16*16);
	REP(i,size){
		REP(j,size){
			REP(k,size){
				c[i][j]+=(a[i][k]*b[k][j])%module;
			}
		}
	}
}

void matrixCopy(ll a[16][16],ll b [16][16]){
	REP(i,size){
		REP(j,size){
			b[i][j]=a[i][j];
		}
	}
}

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
		int n,m;
		cin>>n>>m;
		size=1;
		int n2=n;
		while(n2!=1){
			n2/=2;size++;
		}
		memset(M1,0,sizeof(M1));
		memset(M2,0,sizeof(M2));
		memset(M3,0,sizeof(M3));
		memset(M4,0,sizeof(M4));
		FOR(i,1,size-1){
			REP(j,i){
				M1[i][j]=1;
			}
		}
		REP(i,size){
			M1[i][size-1]=1;
		}
		REP(i,size){
			M2[i][i]=1;
		}
		m--;
		while(m!=0){
			if(m%2==1){
			matrixM(M1,M2,M3);
			matrixCopy(M3,M2);
			}
			matrixM(M1,M1,M3);
			matrixCopy(M3,M1);
			m/=2;
		}
		ll result=0;
		REP(i,size){
			result=(result+M2[i][size-1])%module;
		}
		result=result*(n-n/2)%module;

		printf("%I64d\n",result);
		//fprintf (stderr, "Case #%d: %f\n",t+1,res);

	}

}
