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
//WAP_Atcoder2

ll N,K;

int main(){
  int i,j,re=0;
  cin>>N>>K;
  if(N>8)return 0;
  vector<int> v;
  for(i=0;i<N;i++)
    v.pb(i);
  do{
    int sum=0;
    for(i=0;i<N;i++)
      sum+=(i!=v[i]);
    if(sum==K)
      re++;
  }while(next_permutation(v.begin(),v.end()));
  cout<<re<<endl;
  return 0;
}