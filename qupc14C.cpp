#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<utility>

using namespace std;

//typedef pair<int,int> P;

map<char,pair<int,int> > mp;
string str;

int main(){
  int n,m,q;
  
  cin>>n>>m>>q;
  int i,j,k;


  for(i=0;i<n;i++){
    cin>>str;
    for(j=0;j<m;j++){
      if(str[j]=='*')
        continue;
      mp.insert(make_pair(str[j],make_pair(i,j)));
    }
  }
  map<char,pair<int,int> >::iterator it;
  char ch;
  for(i=0;i<q;i++){
    cin>>ch;
    it=mp.find(ch);
    if(it==mp.end()){
      cout<<"NA"<<endl;
    }else{
      cout<<(it->second.first)+1<<" "<<(it->second.second)+1<<endl;
    }
    //cout<<ch;
  }
  return 0;
}