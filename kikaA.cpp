#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<cstring>

using namespace std;

int x[303],y[303];
bool used[303];
multimap<int,int> trees;
multimap<int,int>::iterator it;

int main(){
  int i,j,ox,oy,oi,min1,min2,outCnt=0,out[3];
  memset(used,0,sizeof(used));
  for(i=1;i<=300;i++){
    if(scanf("%d %d",x+i,y+i)==EOF)break;
    trees.insert(map<int,int>::value_type(x[i],i));
  }

  bool flag0=0;
  printf("100\n");
  for(it=trees.begin(),i=0;it!=trees.end();it++,i++){
    oi=(*it).second;
    out[i%3]=oi;
    if(i%3==2){
      printf("%d %d %d\n",out[0],out[1],out[2]);
      outCnt++;
    }
  }

  return 0;
}