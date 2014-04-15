#include<iostream>

using namespace std;

int main(){
  cout<<500<<" "<<100<<" "<<100<<" "<<10<<endl;
  int i,j;
  for(i=1;i<=10;i++)
    cout<<i<<" ";
  cout<<endl;

  for(i=1;i<=50;i++){
    for(j=51;j<=60;j++){
      cout<<i<<" "<<j<<" "<<100<<endl;
    }
  }

  return 0;
}