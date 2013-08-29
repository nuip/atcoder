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


int main(){
  int N,sum,temp,re=0;
  int i,j;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    sum=0;
    for(j=0;j<5;j++){
      scanf("%d",&temp);
      sum+=temp;
    }
    re+=(sum<20);
  }
  cout<<re<<endl;
  return 0;
}