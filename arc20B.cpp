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

int n,c,a[100];

int main(){
  int i,j,l,r,sum,minn=1<<30;
  cin>>n>>c;
  for(i=0;i<n;i++)
    cin>>a[i];

  for(l=1;l<=10;l++){
    for(r=1;r<=10;r++){
      if(l==r)continue;
      sum=0;
      for(i=0;i<n;i++){
        sum+=(a[i]!=(i%2?r:l));
      }
      minn=min(minn,sum);
    }
  }
  cout<<minn*c<<endl;
  return 0;
}