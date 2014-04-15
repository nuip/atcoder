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

int dp[112345];

int main(){
  ll n,i,j;
  vector<ll> f;
  fill(dp,dp+112345,1<<30);

  cin>>n;
  if(n>1000000)return 0;
  
  f.pb(1),f.pb(2);
  i=1;
  while(f[i]<=n){
    f.pb(f[i]+f[i-1]);
    i++;
  }

  dp[0]=0;
  for(i=0;i<=n;i++){
    for(j=0;j<f.size();j++){
      if(i+f[j]>n)break;
      dp[i+f[j]]=min(dp[i+f[j]],dp[i]+1);
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}