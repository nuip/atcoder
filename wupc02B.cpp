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

string s;
int N;

int main(){
  int i,j,dp[112];
  fill(dp,dp+112,999999);
  cin>>N>>s;

  dp[0]=0;
  for(i=0;i<N;i++){
    for(j=1;j<=3;j++){
      if(i+j<N)
        dp[j+i]=min(dp[i+j],dp[i]+(s[i+j]=='X'));
    }
  }
//for(i=0;i<N;i++)cout<<dp[i]<<"";
  cout<<dp[N-1]<<endl;
  return 0;
}