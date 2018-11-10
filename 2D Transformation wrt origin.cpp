#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	clrscr();
	int gdriver = DETECT;
	int gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	cout<<"\t\t2-D Transformation\t\t"<<endl;
	int x1=300,y1=100,x2=380,y2=150;
	rectangle(x1,y1,x2,y2);
	outtextxy(x2,y2,"Before 2-D Transformation");
	float angle;
	int choice;
	do{
	cout<<"Press 1 for translation."<<endl;
	cout<<"Press 2 for scaling."<<endl;
	cout<<"Press 3 for rotation."<<endl;
	cout<<"Press 4 for exit."<<endl;
	cin>>choice;
	switch(choice)
	{
	  case 1:
		 int tx,ty;
		 cout<<"Enter the translating co-ordinates"<<endl;
		 cin>>tx>>ty;
		 rectangle(x1+tx,y1+ty,x2+tx,y2+ty);
		 outtextxy(x2+tx,y2+ty,"After translation");
		 break;

	  case 2:
		 float sx,sy;
		 cout<<"Enter the scaling co-ordinates"<<endl;
		 cin>>sx>>sy;
		 rectangle(x1*sx,y1*sy,x2*sx,y2*sy);
		 outtextxy(x2*sx,y2*sy,"After scaling");
		 break;

	  case 3:
		 cout<<"Enter the angle by which object is to be rotated"<<endl;
		 cin>>angle;
		 angle = angle*3.14/180;
		 int xx1,xx2,xx3,xx4,yy1,yy2,yy3,yy4;
		 xx1 = x1*cos(angle) - y1*sin(angle);
		 yy1 = x1*sin(angle) + y1*cos(angle);
		 xx2 = x2*cos(angle) - y1*sin(angle);
		 yy2 = x2*sin(angle) + y1*cos(angle);
		 xx3 = x1*cos(angle) - y2*sin(angle);
		 yy3 = x1*sin(angle) + y2*cos(angle);
		 xx4 = x2*cos(angle) - y2*sin(angle);
		 yy4 = x2*sin(angle) + y2*cos(angle);
		 line(xx1,yy1,xx2,yy2);
		 line(xx2,yy2,xx4,yy4);
		 line(xx3,yy3,xx4,yy4);
		 line(xx3,yy3,xx1,yy1);
		 outtextxy(xx2,yy2,"After rotation");
		 break;
	}
	}while(choice!=4);
	getch();
}
