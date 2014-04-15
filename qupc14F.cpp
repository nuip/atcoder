#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
typedef pair<int,int> P;
typedef long long ll;

int N,T,M,d[112];
ll dp[112][11234],tmp[112][11234],MOD=1000000009;

void prnt(){
  int i,k;
  for(i=0;i<=N;i++){
    for(k=0;k<=T;k++){
      cout<<tmp[i][k]<<" ";
    }cout<<endl;
  }
}

int main(){
  int i,j,k;
  cin>>N>>T>>M;
  for(i=0;i<N;i++)
    cin>>d[i];

  dp[0][0]=1;
  for(i=0;i<N;i++){
//    fill(tmp,tmp+sizeof(tmp),0ll);
    memset(tmp,0,sizeof(tmp));
    for(k=0;k<=N;k++){
      for(j=0;j<=T;j++){
        if(dp[k][j])if(j+d[i]<=T)
          tmp[k+1][j+d[i]]=(tmp[k+1][j+d[i]]+dp[k][j])%MOD;
      }
    }
    for(k=0;k<=N;k++)
      for(j=0;j<=T;j++)
        dp[k][j]=(dp[k][j]+tmp[k][j])%MOD;
    //prnt();cout<<endl;
  }

  int re=0;
  for(i=M;i<=N;i++){
    for(j=0;j<=T;j++){
      re=(re+dp[i][j])%MOD;
      //cout<<dp[i][j]<<" ";
    }//cout<<endl;
  }
  cout<<re<<endl;
  return 0;
}