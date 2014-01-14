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

string degs[16]={"N","NNE","NE","ENE",
"E","ESE","SE","SSE",
"S","SSW","SW","WSW","W","WNW","NW","NNW"};
double diss[15]=
{0, 0.25, 1.55, 3.35,
  5.45, 7.95, 10.75, 13.85,
  17.15, 20.75, 24.45, 28.45,32.65,22222};

int main(){
  int deg,dish,w;
  string dir;
  cin>>deg>>dish;
  double dis=double(dish)/60.0;
  dir=degs[int((double(deg)+112.5) /225)%16];
  for(w=0;w<=12&&dis>=diss[w+1];w++);

  cout<<(w?dir:string("C"))<<" "<<w<<endl;
  return 0;
}