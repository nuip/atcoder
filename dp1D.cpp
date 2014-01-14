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
typedef long long ll;

int dice[7][3]={
  {0,0,0},
  {0,0,0},
  {1,0,0},
  {0,1,0},
  {2,0,0},
  {0,0,1},
  {1,1,0}};
double prob[102][61][40][30];

int main(){
  int i,j,k,l,m,N;
  ll D;
  cin>>N>>D;

  prob[0][0][0][0]=1;
  for(i=0;i<N;i++){
    for(j=0;j<=60;j++){
      for(k=0;k<=38;k++){
        for(l=0;l<=26;l++){
          if(prob[i][j][k][l]==0)continue;
       //   cout<<j<<","<<k<<","<<l<<":"<<prob[i][j][k][l]<<endl;
          for(m=1;m<=6;m++){
            prob[i+1][j+dice[m][0]][k+dice[m][1]][l+dice[m][2]]+=prob[i][j][k][l]/6;
          }
        }
      }
    }
  }

  int ni,san,go;
  ni=san=go=0;
  while(D%2==0){
    D/=2;
    ni++;
  }
  while(D%3==0){
    D/=3;
    san++;
  }
  while(D%5==0){
    D/=5;
    go++;
  }
  if(D!=1){
    cout<<0<<endl<<"!!!";
  }else{
    double ans=0;
    
    for(j=ni;j<=60;j++){
      for(k=san;k<=38;k++){
        for(l=go;l<=26;l++){
          ans+=prob[i][j][k][l];
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}