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


int main(){
  string str;
  long long re=0,i,j,sum;
  sum=0;
  cin>>str;

  for(i=0;i<(str.size()+1)/2;i++)
    sum+=(str[i]!=str[str.size()-1-i]);
  if(sum==0){
    re=25*(str.size()/2)*2;
  }else if(sum==1){
    re=25*str.size()-2;
  }else{
    re=25*str.size();
  }

  cout<<re<<endl;
  
  return 0;
}