#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
typedef pair<int,int> P;
typedef long long ll;

int N,M,cx,cy,cr,bx,by,w,h;

int main(){
  int i,j,k,m=0,d2;
  cin>>N>>M;
  if(N*M!=1)return 0;
  cin>>cx>>cy>>cr>>bx>>by>>w>>h;

  m=(bx<=cx)+(bx+w<cx)+3*(by<=cy)+3*(by+h<cy);
  if(m==4){
    d2=0;
  }else if(m==3){
    d2=cx-bx;
    d2*=d2;
  }else if(m==5){
    d2=cx-bx-w;
    d2*=d2;
  }else if(m==1){
    d2=cy-by;
    d2*=d2;
  }else if(m==7){
    d2=cy-by-h;
    d2*=d2;
  }else{
    int dx,dy;
    dx=bx+w*(m%3>0)-cx;
    dy=by+h*(m>5)-cy;
    d2=dx*dx+dy*dy;
  }
//cout<<d2<<endl;
  cout<<(d2<=cr*cr)*2*(w+h)<<endl;
  return 0;
}