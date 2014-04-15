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

int main(){
  ll n,m,x0,a,p,i,j,pre,seki[1123][1123],srt[1123456],re=0;
  vector<ll> mae[1123],ato[1123];
  bool usd[1123456];
  memset(usd,0,sizeof(usd));
  cin>>n>>m>>x0>>a>>p;

  pre=srt[0]=seki[0][0]=x0;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(i+j==0)continue;
      srt[i*m+j]=seki[i][j]=pre=(pre+a)%p;
    }
  }
  sort(srt,srt+n*m);
// cout<<"3"; 
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      int tmp=(lower_bound(srt,srt+n*m,seki[i][j])-srt);
      while(usd[tmp])tmp++;
      usd[tmp]=1;
      if(tmp/m==i)continue;
      re+=abs(tmp/m-i);
//      cout<<i<<","<<tmp/m<<endl;
      mae[i].pb(j);
      ato[tmp/m].pb(j);
    }
  }
//cout<<"5";
  for(i=0;i<n;i++){
 //   if(mae[i].size()!=ato[i].size())
 //     cout<<i<<":"<<mae[i].size()<<"!="<<ato[i].size()<<endl;
    sort(mae[i].begin(),mae[i].end());
    sort(ato[i].begin(),ato[i].end());
    for(j=0;j<mae[i].size();j++){
      re+=abs(mae[i][j]-ato[i][j]);
    }
  }
  cout<<re<<endl;
  return 0;
}