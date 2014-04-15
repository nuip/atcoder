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
typedef vector<int> V;
//WAP_Atcoder2

string board[8];

int dfs(int i,V x,V y,V p,V m){
  int j,re=0;
  if(i==8){
    for(j=0;j<8;j++)
      cout<<board[j]<<endl;
    return 1;
  }
  if(y[i])return dfs(i+1,x,y,p,m);
  y[i]=1;
  for(j=0;j<8;j++){
    if(x[j]+p[j+i]+m[8-i+j])
      continue;
    x[j]=p[j+i]=m[8-i+j]=1;
    board[i][j]='Q';
    if(dfs(i+1,x,y,p,m))return 1;
    x[j]=p[j+i]=m[8-i+j]=0;
    board[i][j]='.';
  }
  return re;
}
int main(){
  int i,j;
  V x(8),y(8),p(16),m(16);
  for(i=0;i<8;i++){
    cin>>board[i];
    for(j=0;j<8;j++){
      if(board[i][j]=='Q'){
        if(x[j]+y[i]+p[i+j]+m[8-i+j]){
           cout<<"No Answer"<<endl;
          return 0;
        }
        x[j]=y[i]=p[i+j]=m[8-i+j]=1;
      }
    }
  }
  if(dfs(0,x,y,p,m)==0)
    cout<<"No Answer"<<endl;
  return 0;
}