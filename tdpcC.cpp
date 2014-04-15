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

double rate[19][1224];
int K;

int main(){
  int i,j,k;
  cin>>K;
  for(i=0;i<(1<<K);i++)
    cin>>rate[K][i];
  double l,r;
  for(i=K-1;i>=0;i--){
    for(j=0;j<(1<<i);j++){
      l=rate[i+1][2*j], r=rate[i+1][2*j+1];
      rate[i][j]=l*(1+pow(10,(l-r)/400));
      rate[i][j]+=r*(1+pow(10,(r-l)/400));
      rate[i][j]/=2+pow(10,(r-l)/400)+pow(10,(l-r)/400);
    }
  }

  for(i=0;i<=K;i++){
    for(j=0;j<(1<<i);j++){
      printf("%.6f ",rate[i][j]);
    }printf("\n");
  }

  for(i=0;i<(1<<K);i++){
    double tmp=1,p=rate[K][i],P;
    for(j=K;j>0;j--){
      P=rate[j][(i>>(K-j))^1];
      tmp/=1+pow(10,(P-p)/400);
      cout<<P<<" ";
    }
    cout<<tmp<<endl;
  }
  return 0;
}