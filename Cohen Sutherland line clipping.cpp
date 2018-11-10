#include <iostream.h>
#include<conio.h>
#include<graphics.h>
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000
const int xmax = 400;
const int ymax = 300;
const int xmin = 200;
const int ymin = 200;
int computeCode(double x, double y)
{
    int code = INSIDE;
    if (x < xmin)
	code |= LEFT;
    else if (x > xmax)
	code |= RIGHT;
    if (y < ymin)
	code |= BOTTOM;
    else if (y > ymax)
		code |= TOP;
    return code;
}
void cohenSutherlandClip(double x1, double y1,double x2, double y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;
    while (1)
    {
	if ((code1 == 0) && (code2 == 0))
	{
	    accept = 1;
	    break;
	}
	else if (code1 & code2)
	{
	   break;
	}
	else
	{
	    int code_out;
	    double x, y;
	    if (code1 != 0)
		code_out = code1;
	    else
		code_out = code2;
	    if (code_out & TOP)
	    {
		x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
		y = ymax;
	    }
	    else if (code_out & BOTTOM)
	    {
		x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
		y = ymin;
	    }
	    else if (code_out & RIGHT)
	    {
		y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
		x = xmax;
	    }
	    else if (code_out & LEFT)
	    {
		y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
		x = xmin;
	    }

	    if (code_out == code1)
	    {
		x1 = x;
		y1 = y;
		code1 = computeCode(x1, y1);
	    }
	    else
	    {
		x2 = x;
		y2 = y;
		code2 = computeCode(x2, y2);
	    }
	}
    }
    if (accept)
    {
	line(x1,y1,x2,y2);
	rectangle(xmin,ymin,xmax,ymax);
    }
    else
	cout << "Line rejected" << endl;
	rectangle(xmin,ymin,xmax,ymax);
}
void main()
{   clrscr();
    int gd=DETECT,gm=0;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    double x1,x2,y1,y2;
    cout<<"\t\t Cohem Sutherland Line Clipping Algorithm\n";
    cout<<"Line Coordinates:";
    cin>>x1>>y1>>x2>>y2;
    putpixel(x1,y1,15);
    putpixel(x2,y2,15);
    outtextxy(x1,y1-10,"A");
    outtextxy(x2,y2+5,"B");
    cohenSutherlandClip(x1,y1,x2,y2);
    getch();
}
