#include<graphics.h>
#include<iostream.h>
#include<conio.h>
void bfill(int x, int y, int bcol, int fcol)
{
	int ccol = getpixel(x,y);
	if(ccol!=fcol && ccol!=bcol)
	{
		putpixel(x,y,fcol);
		bfill(x+1,y,15,10);
		bfill(x,y+1,15,10);
		bfill(x-1,y,15,10);
		bfill(x,y-1,15,10);
	}
}
void main()
{
	clrscr();
	int gdriver = DETECT;
	int gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	cout<<"\t\t Boundary Fill Algorithm \t\t"<<endl;
	int left,top,right,bottom;
	cout<<"Enter the co-ordinates of rectangle"<<endl;
	cin>>left>>top>>right>>bottom;
	rectangle(left,top,right,bottom);
	int x,y;
	cout<<"Enter the co-ordinates of the interior point"<<endl;
	cin>>x>>y;
	bfill(x,y,15,10);
	getch();
}
