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

bool scores[10010];
int n,num;

int main(){
  scanf("%d",&n);
  int i,j;

  scores[0]=1;

  for(i=0;i<n;i++){
    scanf("%d",&num);
    for(j=10000;j>=0;j--){
      if(scores[j]){
        scores[j+num]=1;
      }
    }
  }

  int ans=0;
  for(j=0;j<=10000;j++){
    if(scores[j]){
      ans++;
    }
  }

  cout<<ans<<endl;
  return 0;
}