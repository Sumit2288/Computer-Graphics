#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<conio.h>

int xmax,ymax,xmid,ymid,o1,o2,ang;
float rang;
int x1,x2,x3,y1,y2,y3,x,y;

void drawtri(int x1,int x2,int x3,int y1,int y2,int y3)
{

  line(x1+xmid,ymid-y1,xmid+x2,ymid-y2);
  line(x1+xmid,ymid-y1,xmid+x3,ymid-y3);
  line(x3+xmid,ymid-y3,xmid+x2,ymid-y2);
}


void ref()
{
  cout<<"\n Enter coordinates of arbitrary point: "<<endl;
  cin>>x>>y;

  xmid=xmid+x;
  ymid=ymid-y;
  x1=-x1;
  y1=-y1;
  x2=-x2;
  y2=-y2;
  x3=-x3;
  y3=-y3;
  sleep(2);
  drawtri(x1+x,x2+x,x3+x,y1-y,y2-y,y3-y);
  goto label;
 }

void rot()
 {
  cout<<"Rotation\n";
  cout<<"\n Enter coordinates of arbitrary point: "<<endl;
  cin>>x>>y;
  putpixel(x,y,15);
  cout<<"\n Enter angle: ";
  cin>>ang;

  rang=((ang*3.14)/180.0);

  xmid=xmid+x;
  ymid=ymid-y;

  x1=x1*cos(rang)- y1*sin(rang);
  y1=x1*sin(rang)+ y1*cos(rang);
  x2=x2*cos(rang)- y2*sin(rang);
  y2=x2*sin(rang)+ y2*cos(rang);
  x3=x3*cos(rang)- y3*sin(rang);
  y3=x3*sin(rang)+ y3*cos(rang);

  sleep(2);
  drawtri(x1,x2,x3,y1,y2,y3);
}
void main()
{

 cout<<"x1 y1: ";
 cin>>x1>>y1;
 cout<<"x2 y2: ";
 cin>>x2>>y2;
 cout<<"x3 y3: ";
 cin>>x3>>y3;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C://TURBOC3//BGI");

 xmax=getmaxx();
 ymax=getmaxy();
 xmid=xmax/2;
 ymid=ymax/2;

   for(int i=0;i<xmax;i++)
     putpixel(i,ymid+y,YELLOW);
   for(i=0;i<ymax;i++)
     putpixel(xmid-x,i,YELLOW);

  drawtri(x1,x2,x3,y1,y2,y3);

  ref();
  rot();
  getch();
}
