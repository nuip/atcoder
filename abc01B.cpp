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

int m,vv;

int main(){
  cin>>m;
  if(m<100);else if(m<=5000){
    vv=m/100;
  }else if(m<=30000){
    vv=m/1000+50;
  }else if(m<=70000){
    vv=( (m/1000)-30 )/5+80;
  }else{
    vv=89;
  }

  printf("%02d\n",vv);
  return 0;
}