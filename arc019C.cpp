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
typedef pair<int,pair<int,int> > T;
typedef pair<int,int> P;

char maps[55][55];
int dists[3][55][55][112];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
ll R,C,K;

void dist(int x,int y,int mode){
  memset(dists[mode],-1,sizeof(dists[mode]));
  queue<T> que;
  T tmp;
  int cnt=0;
  que.push(T(x,P(y,mode)));
  que.push(T(-1,P(0,0)));
  while(que.empty()==0){
    if(que.front().X==-1){
      cnt++;
      que.push(que.front());
      que.pop();
    }else{
      tmp=que.front();
      que.pop();
      if(tmp.Y.Y>K)continue;
      if(dists[mode][tmp.X][tmp.Y.X][tmp.Y.Y]!=-1)
        continue;
      dists[mode][tmp.X][tmp.Y.X][tmp.Y.Y]=cnt;
      for(int i=0;i<4;i++){
        int tmpx=tmp.X+dx[i],tmpy=tmp.Y.X+dy[i];
        if(maps[tmpy][tmpx]=='T')
          continue;
        if(tmpy<0 || R<=tmpy || tmpx<0 || C<=tmpx)
          continue;
        if(tmp.Y.Y+(maps[tmpy][tmpx]=='E')>K)continue;
        if(dists[mode][tmpx][tmpy][tmp.Y.Y+(maps[tmpy][tmpx]=='E')]!=-1)
          continue;
        que.push(T(tmpx,P(tmpy,tmp.Y.Y+(maps[tmpy][tmpx]=='E'))));
        
      }
    }
//    que.pop();
  }
  return;
}
int main(){
  int i,j,sx,sy,cx,cy,gx,gy,re=500000;
  scanf("%I64d %I64d %I64d",&R,&C,&K);
  for(i=0;i<R;i++){
    scanf("%s",maps[i]);
    for(j=0;j<C;j++){
      if(maps[i][j]=='S'){
        sx=j,sy=i;
      }else if(maps[i][j]=='C'){
        cx=j,cy=i;
      }else if(maps[i][j]=='G'){
        gx=j,gy=i;
      }
    }
  }
  dist(sx,sy,0);
  dist(cx,cy,1);
  dist(gx,gy,2);
  return 0;
}