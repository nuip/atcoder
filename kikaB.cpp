#include<cstdio>
#include<cmath>

using namespace std;

int main(){
  int n,x[104],y[104];
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",x+i,y+i);
  }
  if(x[0]<0)x[0]*=-1;
  printf("%d\n",x[0]);
  return 0;
}