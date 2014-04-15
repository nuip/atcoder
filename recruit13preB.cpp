#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

int T,R,B,rn,bn,rk,bk;
ll dp[1124][100];

bool check(int j,int n,int k){
  int i;
  for(i=0;i<n;i++)
    k-=(j>>i)%2;
  return k<=0;
}

int main(){
  int i,j,k;
  ll MOD=1000000009;
  cin>>T;
  while(T--){
    int r,b;
    r=b=0;
    cin>>R>>B>>rn>>rk>>bn>>bk;
    memset(dp,sizeof(dp),0);
    dp[0][1]=dp[1][1]=1;
    for(i=1;i<R+B;i++){
      for(j=0;j<(1<<min(rn,i));j++){
        if(check(~j,min(i,rn),rk))
          continue;
        int jj=(j<<1);
        if(!check(~jj,min(i,rn),rk)){
          dp[jj][i+1]=(dp[jj][i+1]+dp[j][i])%MOD;
        }
      }
      for(j=0;j<(1<<min(bn,i));j++){
        if(check(j,min(i,bn),bk))continue;
        int jj=(j<<1)+1;
        if(check(jj,min(i,bn),bk)){
          dp[jj][i+1]=(dp[jj][i+1]+dp[j][i])%MOD;
        }
      }
      for(j=0;j<10;j++){
        cout<<dp[j][i]<<"("<<check(~j,min(i,rn),rk)+check(j,min(i,bn),bk)<<") ";
      }
      cout<<endl;
    }
    ll re=0;
    for(i=0;i<(1<<min(max(rn,bn),i));i++){
      if(check(i,min(R+B,rn),rk)||check(i,min(R+B,bn),bk))
        continue;
      re=(re+dp[i][R+B])%MOD;
    }
    cout<<re<<endl;
  }
  return 0;
}