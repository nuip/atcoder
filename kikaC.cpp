#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int monx[100005],mony[100005],monN;


int isClockwise(int x,int y,int p,int q){
  int dpx=monx[p]-x,dpy=mony[p]-y,dqx=monx[q]-x,dqy=mony[q]-y;
  cout<<dpx<<","<<dpy<<"|"<<dqx<<","<<dqy<<"->"<<(dpx*dqy>dpy*dqx)<<endl;

  if(dpx*dqy>dpy*dqx)
    return 1;
  else if(dpx*dqy<dpy*dqx){
    return -1;
  }else{
    return 0;
  }
}

bool isInside(int x,int y,int p,int q,int r){
//  cout<<x<<y<<endl;
  //cout<<monx[p]<<","<<mony[p]<<endl;
  //cout<<isClockwise(x,y,p,q)<<"&"<<isClockwise(x,y,q,r)<<"&"<<isClockwise(x,y,r,q)<<endl;
  return isClockwise(x,y,p,q)==isClockwise(x,y,q,r)
    && isClockwise(x,y,p,q)==isClockwise(x,y,r,p);
}

int main(){
  int N;
  int i,j,a,b,c,tmpx,tmpy;
  char str[100];
  bool flag;

  monN=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%s %d %d",str,&tmpx,&tmpy);
    if(!strcmp(str,"MONITOR")){
      monx[monN]=tmpx;
      mony[monN]=tmpy;
      monN++;
    }else{
      flag=0;
      for(a=0;a<monN;a++){
        for(b=a+1;b<monN;b++){
          for(c=b+1;c<monN;c++){
      //      cout<<isInside(0,0,a,b,c)<<"=?"<<isInside(tmpx,tmpy,a,b,c)<<endl;
            if(isInside(0,0,a,b,c)!=isInside(tmpx,tmpy,a,b,c))
              flag=1;
            /*if(isClockwise(tmpx,tmpy,a,b)==isClockwise(tmpx,tmpy,b,a)
               ||isClockwise(tmpx,tmpy,b,c)==isClockwise(tmpx,tmpy,c,b)
               ||isClockwise(tmpx,tmpy,a,c)==isClockwise(tmpx,tmpy,c,a))
              flag=1;*/
          }
        }
      }
      printf((flag)?"DANGER\n":"SAFE\n");
    }
  }

  return 0;
}