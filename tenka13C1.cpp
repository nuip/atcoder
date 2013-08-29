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


using namespace std;
typedef __int64 ll;

int M,N;

int ng[5][5][5];

ll count(int cnt){
  ll re=0;
  int m=cnt/N,n=cnt%N;
  int i,j,k;
  if(m==M-1 && n==N-1){
    //cout<<ng[1][m][n]<<","<<ng[2][m][n]<<","<<ng[3][m][n]<<endl;
    for(i=1;i<=3;i++){
      
      re+=(ng[i][m][n]==0);
    }
    return re;
  }
  
  for(i=1;i<=3;i++){
    if(ng[i][m][n])continue;
    //cout<<"("<<m<<","<<n<<")"<<i<<endl;
    for(j=m;j<5&&j<=m+i;j++){
      ng[i][j][n]++;
    }
    for(j=n;j<5&&j<=n+i;j++){
      ng[i][m][j]++;
    }
    re+=count(cnt+1);
    for(j=m;j<5&&j<=m+i;j++){
      ng[i][j][n]--;
    }
    for(j=n;j<5&&j<=n+i;j++){
      ng[i][m][j]--;
    }
  }
  return re;
}

int main(){
  scanf("%d %d",&M,&N);
  memset(ng,0,sizeof(ng));
  cout<<count(0)<<endl;
  return 0;
}