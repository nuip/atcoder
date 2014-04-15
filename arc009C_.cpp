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
bool used[8];

int dfs(int d,int dif){
  int i,j,re=0;
  if(d==N)
    return dif==K;
  for(i=0;i<N;i++){
    if(used[i])continue;
    used[i]=1;
    re+=dfs(d+1,dif+(i!=d));
    used[i]=0;
  }
  return re;
}

int main(){
  int i,j,re=0;
  cin>>N>>K;
  if(N>8)return 0;
  
  cout<<dfs(0,0)<<endl;
  return 0;
}