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
#define INF 2000000

using namespace std;
typedef __int64 ll;

pair<long,long> dp[1005][1005];
int A,B,a[1005],b[1005],sum;

void printDP(){
  int i,j;
  for(i=0;i<=B;i++){
    for(j=0;j<=A;j++){
      printf("(%3ld %3ld) ",dp[i+1][j+1].X,dp[i+1][j+1].Y);
    }cout<<endl;
  }cout<<endl;
}

int main(){
  int ij,i,j;
  scanf("%d %d",&A,&B);
  for(i=0;i<A;i++){
    scanf("%d",a+i);
    sum+=a[i];
  }
  for(i=0;i<B;i++){
    scanf("%d",b+i);
    sum+=b[i];
  }
  sum-=min(a[A-1],b[B-1]);
  sum=sum/2+abs(a[A-1]-b[B-1]);

  pair<long,long> tmp[2];
  tmp[0].X=tmp[1].Y=-INF;
  tmp[1].X=tmp[0].Y=INF;
  for(i=0;i<=1002;i++){
    dp[0][i]=dp[i][0]=tmp[i%2];
  }
  dp[1][1]=pair<long,long>(0,0);
  pair<long,long> up,lft;
  for(ij=2;ij<=A+1+B+1;ij++){
    for(j=1;j<ij;j++){
      i=ij-j;
      if(i==1 && j==1)continue;
      up=dp[i-1][j];
      lft=dp[i][j-1];
      if((i+j)%2){
        up.X+=b[i-2];
        lft.X+=a[j-2];

        int sumtmp;
   /*     if( (A+B)%2==0){
          sumtmp=abs(a[i-2]-b[j-1])+(max(a[i-2],b[j-1])+(dp[i-1][j].X+dp[i-1][j].Y))/2;
        }*/
        //if( (up.X>lft.X)/*&&((A+B)%2==1) ||( (A+B)%2==0 )&&(abs(up.X-sumtmp)<abs(lft.X-sumtmp))*/){
        if(up.X-up.Y > lft.X-lft.Y){
          dp[i][j]=up;
        }else{
          dp[i][j]=lft;
        }
      }else{
        up.Y+=b[i-2];
        lft.Y+=a[j-2];
        
       //if(up.X<lft.X){
        if(up.Y-up.X > lft.Y-lft.X){
          dp[i][j]=up;
        }else{
          dp[i][j]=lft;
        }
      }printDP();
    }
  }

  cout<<dp[B+1][A+1].X<<endl;
  return 0;
}