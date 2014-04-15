#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
typedef pair<int,int> P;
typedef long long ll;

int N,M,p,G,s[20];
vector<P> edges[600];
int maxin[600],memo[600];

int solve(int node,int val){
  if(node==0)return val;
  if(maxin[node]>=val)
    return memo[node];
  int i,re=0;
  for(i=0;i<edges[node].size();i++){
    P tmp=edges[node][i];
    re=max(re,solve(tmp.first,min(val,tmp.second)));
  }
  maxin[node]=val;
  return memo[node]=re;
}

int main(){
  cin>>N>>M>>p>>G;
  int i,j,k,f,t,cap;
  for(i=0;i<G;i++)
    scanf("%d",s+i);
  for(i=0;i<N;i++){
    scanf("%d %d %d",&f,&t,&cap);
    edges[f].push_back(P(t,cap));
  }

  int maxcap=0;
  for(i=0;i<G;i++){
    //fill(maxin,maxin+600,0);
    maxin[s[i]]=(1<<30);
    maxcap=max(maxcap,solve(s[i],1<<30));
  }
  cout<<maxcap<<endl;
  cout<<(p<=maxcap?"Yes":"No")<<endl;
  return 0;
}