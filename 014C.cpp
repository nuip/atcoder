#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<string>
#include<queue>

using namespace std;

string in;
int n;
map<string ,int> state;
map<string ,int>::iterator it;
queue<string> que;

int main(){
  int i,j,min=10;
  string temp;
  cin>>n;
 // cout<<n<<endl;
  //state[""]=0;
  que.push("");
  que.push("A");

  cin>>in;
//  cout<<in<<":"<<que.front()<<endl;
  for(i=0;i<n;i++){
 //   cout<<in.at(i)<<endl;
    for(;que.front()!="A";que.pop()){
 //     cout<<que.front()<<" ";
 //     cout<<"ok1"<<endl;
      if(que.front().size()>5){
        continue;
      }
  //    cout<<que.front().size()<<"ok2"<<endl;
      if(que.front().size())
      if(que.front().at(0)==in.at(i)){
        que.push(que.front().substr(1));
        continue;
      }else if(que.front().at(que.front().size()-1)==in.at(i)){
        que.push(que.front().substr(0,que.front().size()-1));
        continue;
      }
 //     cout<<"hogeee"<<endl;
      temp=que.front();
//      cout<<"hoge"<<endl;
      temp.append(1,in.at(i));
//      cout<<"hogee"<<endl;
      que.push(temp);
      temp.clear();
      temp.append(1,in.at(i));
      temp.append(que.front());
      que.push(temp);

   //   cout<<"aaa"<<endl;
      

   }
    //     cout<<"okey"<<i<<endl;
    que.pop();
    que.push("A");
  }

  while(que.front()!="A"){
    if(que.front().size()<min){
      min=que.front().size();
    }
    que.pop();
  }
  cout<<min<<endl;
  return 0;
}
    /*for(it=state.begin();it!=state.end();it++){
      if((*it).second!=i-1)continue;
      if((*it).first.at(0)==in.at(i)){
        que.push((*it).first.substr(1));
      }else if((*it).first.at((*it).first.size()-1)==in.at(i)){
        que.push((*it)
      }else{
        que.push((*it).first+in.at(i));
        que.push(in.at(i)+(*it).first);
      }*/