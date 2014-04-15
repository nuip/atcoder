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


int main(){
  int ch[256],i,j;
  ch['O']=ch['D']=0;
  ch['I']=1;
  ch['Z']=2;
  ch['S']=5;
  ch['B']=8;
  for(i=0;i<10;i++)
    ch[i+'0']=i;

  string str;
  cin>>str;

  for(i=0;i<str.size();i++){
    cout<<ch[str[i]];
  }
  cout<<endl;
    
  return 0;
}