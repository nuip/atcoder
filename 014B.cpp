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

int n;
set<string> cnt;

int main(){
  cin>>n;
  int i,j;
  string str,pstr;
  cnt.clear();
  
  i=0;
  cin>>pstr;
//  cout<<pstr;
  cnt.insert(pstr);
  i++;
  for(;i<n;i++){
    cin>>str;
//    cout<<str<<endl;
    if(cnt.find(str)!=cnt.end()){
//      cout<<(*(cnt.find(str)))<<"!!"<<str<<endl;
      break;
    }else{
      if(pstr.at(pstr.size()-1)!=str.at(0)){
 //       cout<<"?"<<endl;
        break;
      }
      cnt.insert(str);
      pstr=str;
    }
  }
  if(i==n){
    cout<<"DRAW"<<endl;
  }else{
    cout<<( (i%2)?"WIN":"LOSE")<<endl;
  }
  return 0;
}