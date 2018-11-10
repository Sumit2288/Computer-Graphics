#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
void DDAline(int x1, int y1, int x2, int y2)
{
	int dx = x2-x1;
	int dy = y2-y1;
	int step;
	if(abs(dx)>abs(dy))
	step = abs(dx);
	else
	step = abs(dy);
	float xi = dx/step;
	float yi = dy/step;
	putpixel(x1,y1,15);
	for(int i=1;i<=step;i++)
	{
		x1 = x1 + xi;
		y1 = y1 + yi;
		putpixel(x1,y1,15);
	}
}
void main()
{
	clrscr();
	int gdriver = DETECT;
	int gmode = 0;
	initgraph(&gdriver,&gmode,"c://turboc3//bgi");
	int x1,y1,x2,y2;
	cout<<"\t\t DDA LINE DRAWING ALGORITHM \t\t"<<endl;
	cout<<"Enter the coordinates of first point"<<endl;
	cin>>x1>>y1;
	cout<<"Enter the coordinates of second point"<<endl;
	cin>>x2>>y2;
	DDAline(x1,y1,x2,y2);
	outtextxy(x1,y1,"(x1,y1)");
	outtextxy(x2,y2,"(x2,y2)");
	getch();
}
