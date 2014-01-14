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
#define MOD (1000000007)

using namespace std;
typedef __int64 ll;

//==============================================================
//下のコードを消す
//桁あふれチェック
//==============================================================

long nums[2][1000005],K,N,sum;

int main(){
  cin>>N>>K;
  nums[1][1]=1;
  long i,j;

  for(i=2;i<=N;i++){
    nums[i%2][0]=0;
    for(j=0;j<K;j++){
      nums[i%2][0]+=nums[(i+1)%2][j];
      nums[i%2][0]%=MOD;
    }
    for(j=1;j<K;j++){
      nums[i%2][j]=nums[(i+1)%2][j-1];
    }
  }

  sum=0;
  for(i=1;i<K;i++){
    sum+=nums[N%2][i];
    sum%=MOD;
  }
  cout<<sum<<endl;
  return 0;
}