#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string n,re;
string name[]={"nil",	"nilium",
"un"  ,"unium",
"bi"  ,"bium",
"tri" ,"trium",
"quad","quadium",
"pent","pentium",
"hex" ,"hexium",
"sept","septium",
"oct","octium",
  "enn","ennium"};

int main(){
  int i,j;
  cin>>n;

  for(i=0;i<n.size();i++){
    if(i){
      if(re[re.size()-1]=='n'
         && re[re.size()-2]=='n'
         && n[i]=='0'){
        re=re.substr(0,re.size()-1);
      }
    }
    re+=name[(n[i]-'0')*2+(i+1==n.size())];
  }
  re[0]+='A'-'a';
  cout<<re<<endl;

  return 0;
}