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
//typedef __int64 ll;

int times[3000],s,e,n;

int main(){
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d-%d",&s,&e);
    s=s/5*5;
    e=(e+4)/5*5;
    if(e%100==60)e+=40;
   // cout<<s<<","<<e<<endl;
    times[s]++;
    times[e]--;
  }
  int sum=0;
  for(i=0;i<=2400;i+=5){
    //cout<<sum<<endl;
    if(sum==0 && sum+times[i]>0){
      printf("%04d-",i);
    }else if(sum>0 && sum+times[i]==0){
      printf("%04d\n",i);
    }
    sum+=times[i];
  }

  return 0;
}