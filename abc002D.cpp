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

bool rel[15][15];
int N,M;

int main(){
  cin>>N>>M;
  int i,j,k,a,b,sum,re=0;
  for(i=0;i<M;i++){
    cin>>a>>b;
    rel[a-1][b-1]=rel[b-1][a-1]=1;
  }

  for(i=0;i<(1<<N);i++){
 //   cout<<"i:"<<i<<endl;
    for(j=0;j<N;j++){
      if(i&(1<<j))
      for(k=0;k<N;k++){
        if(j==k || (i&(1<<k))==0)
          continue;
   //     cout<<j<<","<<k<<":"<<rel[j][k]<<endl;
        if(rel[j][k]==0)
          goto BRK;
      }
    }
BRK:
    sum=0;
    for(j=0;j<N;j++)
      sum+=!!(i&(1<<j));
    if(j==N && k==N)
        re=max(re,sum);
  }
  cout<<re<<endl;
  return 0;
}