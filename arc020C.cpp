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
typedef long long ll;

ll N,B;

int main(){
  ll i,j,k,sum=0,r10[20],MOD=1000000007,keta;
  r10[0]=1;
  for(i=0;i<10;i++)
    r10[i+1]=r10[i]*10%MOD;
  
  cin>>N;
  vector<ll> a(N),L(N),ln(N);
  for(i=0;i<N;i++){
    cin>>a[i]>>L[i];
    ln[i]=1;
    while(a[i]/ln[i])ln[i]*=10;
  }
  cin>>B;

  keta=1;
  for(i=N-1;i>=0;i--){
    for(j=0;j<L[i];j++){
      sum=(sum+a[i]*keta)%MOD;
      keta=(keta*ln[i])%MOD;
    }
  }
    cout<<sum%MOD<<endl;
  return 0;
}