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
#define A 77777

using namespace std;
typedef long long ll;
typedef ll Int;
//WAP_Atcoder2

ll N,K;

Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

int main(){
  ll kc[A],i,j,re=0,sum,mod=1777777777,nc[A],inv,hoge,per[A];
cout<<"!";
  cin>>N>>K;
  nc[0]=per[0]=kc[0]=1;
  for(i=1;i<=K;i++){
    nc[i]=nc[i-1]*(N-i+1)%mod;
    extgcd(i,mod,inv,hoge);
    nc[i]=(mod+nc[i]*inv)%mod;
    per[i]=per[i-1]*i%mod;
    kc[i]=(kc[i-1]*(N+i))%mod;
    kc[i]=(kc[i]*inv)%mod;
  }

///  for(i=0;i<=K;i++)
//    cout<<i<<":"<<(mod+nc[i])%mod<<endl;
//cout<<endl;
 // for(i=0;i<=K;i++)
   // cout<<i<<":"<<(mod+kc[i])%mod<<endl;
  re=nc[K]*per[K]%mod;
  sum=0;
  for(i=0;i<K;i++){
    if(i==1)continue;
    ll tmp=nc[i]*per[i]%mod*kc[i]%mod-sum;
    sum=(sum+tmp)%mod;
    re=(mod+re-tmp)%mod;
    
  }
  cout<<re<<endl;
  return 0;
}