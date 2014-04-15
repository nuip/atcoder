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
typedef long long Int;

ll N,B,MOD=1000000007;

ll poww(ll a,ll b){
  if(b==0)return 1;
  ll tmp=pow(a,b/2);
  return tmp*tmp%MOD*(b%2?a:1)%MOD;
}

// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

int main(){
  ll i,j,k,sum=0,r10[20],keta,inv;
  
  cin>>N;
  vector<ll> a(N),L(N),ln(N);
  for(i=0;i<N;i++){
    cin>>a[i]>>L[i];
    ln[i]=1;
    while(a[i]/ln[i])ln[i]*=10;
  }
  cin>>B;
  keta=1;
  ll aaaa,ue;
  for(i=N-1;i>=0;i--){
    extgcd(ln[i]-1,MOD,inv,aaaa);
    ue=(poww(ln[i],L[i])+MOD-1)%MOD;
 //   cout<<"ln"<<ln[i]<<endl;
  //  cout<<(ln[i]-1)*inv%MOD<<endl;
   // cout<<keta*a[i]<<endl;
    sum+=(keta*a[i]%MOD)*(ue*inv%MOD);
    sum=(sum%MOD+MOD)%MOD;
    keta=(keta*(ue+1))%MOD;
  }
    cout<<sum%MOD<<endl;
  return 0;
}