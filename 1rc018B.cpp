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

int main(){
  ll n,x[123],y[123],i,j,k,ax,ay,bx,by,sum=0;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(k=j+1;k<n;k++){
        ax=x[i]-x[j];
        bx=x[i]-x[k];
        ay=y[i]-y[j];
        by=y[i]-y[k];
       // cout<<(ax*by-ay*bx)<<endl;
        if((ax*by-ay*bx)%2==0 && 0!=(ax*by-ay*bx))
          sum++;
      }
    }
  }
  cout<<sum<<endl;
  return 0;
}