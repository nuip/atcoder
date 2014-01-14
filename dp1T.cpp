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
#define MOD (1000000007)

using namespace std;
typedef __int64 ll;

//==============================================================
//下のコードを消す
//桁あふれチェック
//==============================================================

ll gyo[1003][1003];
ll K,N;

int x(ll gyo1[1003][1003],ll gyo2[1003][1003],ll gyoA[1003][1003]){
  ll i,j,k,l;
  for(i=0;i<K;i++){
    for(j=0;j<K;j++){
      gyoA[i][j]=0;
      for(k=0;k<K;k++){
        gyoA[i][j]+=gyo1[i][k]*gyo2[k][j];
        gyoA[i][j]%=MOD;
      }
    }
  }

  return 0;
}

void pow(ll gyor[1003][1003],ll cnt,ll gyoA[1003][1003]){
  if(cnt==1){
    for(i=0;i<K;i++){
      for(j=0;j<K;j++){
        gyoA[i][j]=gyor[i][j];
      }
    }
  }
  if(cnt%2){
    int powGyo[1003][1003];
    pow(gyor[1003][1003],cnt-1,powGyo[1003][1003]);
    x(gyor,powGyo,gyoA);
  }else{
    int powGyo[1003][1003];
    x(gyor,gyor,powGyo);
    pow(powGyo,cnt/2,gyoA);
  }
  return;
}

int main(){
  int ansG[1003][1003];
  cin>>K>>N>>endl;

  ll i,j,sum=0;

  for(i=0;i<K;i++){
    gyo[i][i+1]=1;
  }
  for(i=0;i<K;i++){
    gyo[K-1][i]=1;
  }

  if(N>K){
    pow(gyo,N-K,ansG);
    for(i=0;i<K;i++){
      sum+=ansG[K-1][i];
      sum%=MOD;
    }
    cout<<sum%MOD<<endl;
  }else{
    cout<<1<<endl;
  }
  return 0;
}