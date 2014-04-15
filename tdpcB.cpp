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
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

P dp[1123][1123];
int a[1123],b[1123],A,B;

int main(){
  int i,j,k;
  cin>>A>>B;
  for(i=0;i<A;i++)
    cin>>a[i];
  for(i=0;i<B;i++)
    cin>>b[i];

  for(i=0;i<=A;i++)
    dp[i][B+1]=P(1000000*((i+B)%2),0);
  for(i=0;i<=B;i++)
    dp[A+1][i]=P(1000000*((A+i)%2),0);

  dp[A][B]=P(0,0);
  for(i=A;i>=0;i--){
    for(j=B;j>=0;j--){
      if(i+j==A+B)continue;
      P R=dp[i][j+1],D=dp[i+1][j];
      if((i+j)%2){
        R.Y-=b[j];
        D.Y-=a[i];
        dp[i][j]=min(R,D);
      }else{
        R.X+=b[j];
        D.X+=a[i];
        dp[i][j]=max(R,D);
      }
    }
  }
   /*
  for(i=0;i<=1+A;i++){
    for(j=0;j<=1+B;j++)
      cout<<"("<<dp[i][j].X<<","<<dp[i][j].Y<<") ";
    cout<<endl;
  }*/
  cout<<dp[0][0].X<<endl;
  return 0;
}