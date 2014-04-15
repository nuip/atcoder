#include<cstdio>
#include<iostream>

using namespace std;

int a,b,c,d,e[20][20];

int main(){
  int i,j;
  cin>>a>>b>>c>>d;
  for(i=0;i<c;i++){
    for(j=0;j<a;j++){
      cin>>e[i][j];
    }
  }

  int sum,n,score;
  for(score=0;score<=101;score++){
    sum=0;
    for(i=0;i<c;i++){
      for(j=n=0;j<a;j++){
        n+=(score<=e[i][j]);
      }
      sum+=(b<=n);
    }
    if(sum<d)break;
  }
  cout<<score-1<<endl;

}