#include<graphics.h>
#include<iostream.h>
#include<conio.h>
void drawcircle(int x,int y, int xc, int yc)
{
	putpixel(y+xc,x+yc,15);
	putpixel(y+xc,-x+yc,15);
	putpixel(-y+xc,x+yc,15);
	putpixel(-y+xc,-x+yc,15);
	putpixel(x+xc,-y+yc,15);
	putpixel(-x+xc,y+yc,15);
	putpixel(-x+xc,-y+yc,15);
}
void mid_point_circle(int r, int xc, int yc)
{
	int P,x,y;
	x = 0;
	y = r;
	P = 1 - r;
	putpixel(x+xc,y+yc,15);
	while(x<=y)
	{
		if(P<0)
		{
			P = P + (2*x) + 3;
			x = x + 1;
			y = y;
			putpixel(x+xc,y+yc,15);
			drawcircle(x,y,xc,yc);
		}
		else
		{
			P = P + (2*x) - (2*y) + 5;
			x = x + 1;
			y = y - 1;
			putpixel(x+xc,y+yc,15);
			drawcircle(x,y,xc,yc);
		}
	}
}
void main()
{
	clrscr();
	int gdriver = DETECT;
	int gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	cout<<"\t\t Mid Point Circle Drawing Algorithm \t\t"<<endl;
	int r,xc,yc;
	cout<<"Enter the radius of the circle"<<endl;
	cin>>r;
	cout<<"Enter the centre co-ordinates of the circle"<<endl;
	cin>>xc>>yc;
	putpixel(xc,yc,15);
	outtextxy(xc,yc,"(xc,yc)");
	mid_point_circle(r,xc,yc);
	getch();
}
