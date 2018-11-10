#include<graphics.h>
#include<iostream.h>
#include<conio.h>
void ffill(int x, int y, int bcol, int fcol)
{
	int ccol = getpixel(x,y);
	if(ccol==bcol)
	{
		putpixel(x,y,fcol);
		ffill(x+1,y,bcol,fcol);
		ffill(x,y+1,bcol,fcol);
		ffill(x-1,y,bcol,fcol);
		ffill(x,y-1,bcol,fcol);
	}
}
void main()
{
	clrscr();
	int gdriver = DETECT;
	int gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	cout<<"\t\t Flood Fill Algorithm \t\t"<<endl;
	setcolor(GREEN);
	line(200,200,250,150);
	setcolor(RED);
	line(250,150,300,200);
	setcolor(BLUE);
	line(300,200,200,200);
	int x,y;
	cout<<"Enter the co-ordinates of the interior point"<<endl;
	cin>>x>>y;
	ffill(x,y,0,YELLOW);
	getch();
}
