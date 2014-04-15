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

int N,M,K,S,G;
int sdis[31234],gdis[31234],x[112],f[112];
vector<P> edges[31234];

void dij(int s,int dis[]){
  bool used[31234];
  int i,j;
  priority_queue<P,vector<P>,greater<P> > que;
  fill(dis,dis+31234,1<<30);
  fill(used,used+31234,0);
  dis[s]=0;
  que.push(P(0,s));

  while(!que.empty()){
    P p=que.top();
    que.pop();
    int v=p.second;
    if(dis[v]<p.first)continue;
    for(i=0;i<edges[v].size();i++){
      P tmp=edges[v][i];
      if(dis[tmp.first]> dis[v]+tmp.second){
    //    cout<<tmp.first<<","<<v<<endl;
        dis[tmp.first]=dis[v]+tmp.second;
        que.push(P(dis[tmp.first],tmp.first));
      }
    }
  }
}

int main(){
  cin>>N>>M>>K>>S>>G;
  int i,j,k,a,b,d;

  for(i=0;i<M;i++){
    scanf("%d %d %d",&a,&b,&d);
    edges[b].push_back(P(a,d));
    edges[a].push_back(P(b,d));
  }
  for(i=0;i<K;i++){
    scanf("%d %d",x+i,f+i);
//    cout<<x[i]<<"<"<<f[i]<<endl;
  }
  dij(S,sdis);
  dij(G,gdis);

  int via,re=(1<<30);
  for(via=0;via<N;via++){
    int sum=0;
//    cout<<"via "<<via;
    for(i=0;i<K;i++){
      if(sdis[via]<x[i])break;
    }
    if(i)sum+=f[i-1];
//cout<<" "<<i;
    for(i=0;i<K;i++){
      if(gdis[via]<x[i])break;
    }
    if(i)sum+=f[i-1];
//cout<<" "<<i<<" "<<sum<<endl;
    re=min(re,sum);
  }
  cout<<re<<endl;
  return 0;
}