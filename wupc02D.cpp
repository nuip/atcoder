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

int N,a[112][112],dp[112][112];

int main(){
  cin>>N;
  int i,j,k;

  for(i=0;i<N;i++)
    for(j=0;j<=i;j++)
      cin>>a[i][j];

  dp[0][0]=a[0][0];
  for(i=0;i<N;i++){
    for(j=0;j<=i;j++){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i+1][j]);
      dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+a[i+1][j+1]);
    }
  }
  int re=0;
  for(i=0;i<N;i++)
    re=max(re,dp[N-1][i]);

  cout<<re<<endl;
  return 0;
}