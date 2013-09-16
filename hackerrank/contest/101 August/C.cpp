#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[2][2004];
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[1][i];
        }
        for(int i=0;i<n;i++){
            cin>>a[0][i];
        }
        int ans=abs(a[0][0]-a[1][0])-1;
        for(int i=1;i<n;i++){
        ans^=(abs(a[0][i]-a[1][i])-1);
        }
        if(ans){
        cout<<"player-2"<<endl;
        }
        else{ cout<<"player-1"<<endl;}
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
