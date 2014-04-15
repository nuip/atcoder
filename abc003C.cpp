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
typedef __int64 ll;

int N,K;
int r[112];

int main(){
  cin>>N>>K;
  int i,j,k;
  double re;
  for(i=0;i<N;i++)
    cin>>r[i];
  sort(r,r+N);
  re=0;
  for(i=N-K;i<N;i++)
    re=(re+r[i])/2;

  printf("%.7f\n",re);
  return 0;
}