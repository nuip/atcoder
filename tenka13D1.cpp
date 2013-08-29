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

string S,str;
ll B,L,N,cnt,slen,clen;
int scount(){
  int lcnt=0;
  while(cnt<S.length()){
    if(S[cnt]==')'){
      return lcnt;
    }else if(S[cnt]=='('){
      cnt++;
      int tmp=scount();
      cnt++;
      int num=0;
      while(cnt<S.length()){
        if('0'>S[cnt]||S[cnt]>'9'){
          cnt--;
          break;
        }
        num*=10;
        num+=S[cnt]-'0';
        cnt++;
      }
      lcnt+=tmp*(num);
    }else{
      lcnt++;
    }
    cnt++;
  }
  return lcnt;
}
string slove(){
  string re;
  int rei=0;
  while(cnt<S.length()){
    if(S[cnt]==')'){
      return re;
    }else if(S[cnt]=='('){
      cnt++;
      string tmp=slove();
      cnt++;
      int num=0;
      while(cnt<S.length()){
        if('0'>S[cnt]||S[cnt]>'9'){
          cnt--;
          break;
        }
        num*=10;
        num+=S[cnt]-'0';
        cnt++;
      }
      if(clen+tmp.length()*(num-1)>=B)
      for(int i=0;i<num;i++){
        re+=tmp;
        if(clen+tmp.length()*i>B+L)break;;
      }
      re=re.substr(B-clen);
      //if(re.length()>L)re=re.substr(0,L);
      clen+=tmp.length()*(num-1);
      if(clen>B+L)return re;
    }else{
      if(clen>=B && clen<B+L)
      re+=S[cnt];
      clen++;
      if(clen>B+L)return re;
    }
    cnt++;
  }
  return re;
}

int main(){
  cin>>B>>L>>N>>S;
  cnt=slen=0;

  slen=scount();
  if(B<0)B+=slen;
  cnt=clen=0;
  str=slove();
  cout<<str<<endl;
  cout<<str.length()<<"="<<slen<<endl;
  //cout<<str<<endl;
  return 0;
}