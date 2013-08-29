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

int compA(int a, int b,int c,int d){
  int re=(y[a]-y[b])*(x[c]-x[d])-(x[a]-x[b])*(y[c]-y[d]);
  if((a<0) != (c<0))re*=-1;
  return re;
}

int main(){
  int i,j,ox,oy,oi,min1,min2,outCnt=0;
  memset(used,0,sizeof(used));
  for(i=1;i<=300;i++){
    scanf("%d %d",x+i,y+i);
    trees.insert(map<int,int>::value_type(x[i],i));
  }

  bool flag0=0;
  for(it=trees.begin();it!=trees.end();it++){
    oi=(*it).second;
    if(used[oi])continue;
    used[oi]=1;
    for(i=1,j=0;i<=300;i++){
      if(used[i])continue;
      if(x[i]==x[oi])continue;
      j++;
      if(j==1){
        min1=i;
        if(x[i]==x[oi])flag0=1;
      }else if(j==2){
        min2=i;
        if(x[i]==x[oi]){
          swap(min1,min2);
          flag0=1;
        }else{
        if(compA(oi,min1,oi,min2)>0)
          swap(min1,min2);
        }
      }else{
        if(x[oi]==x[i]){
          min2=min1;
          min1=i;
          flag0=1;
        }else if(compA(oi,i,oi,min2)<0){
          min2=min1;
          if(flag0){
            min2=i;
          }else if(compA(oi,i,oi,min1)>0){
            min1=i;
          }else{
            min2=i;
          }
        }
      }
    }
    if(j<2)break;
    printf("%d %d %d\n",oi,min1,min2);
    used[min1]=used[min2]=1;
    outCnt++;
    if(outCnt>=10)break;
  }

  return 0;
}