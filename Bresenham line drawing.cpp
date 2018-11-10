#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	int gd=DETECT,gm,x1,x2,y1,y2,dx,dy;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	cout<<"\t\t BRESENHAM LINE DRAWING ALGORITHM \t\t"<<endl;
	cout<<"Enter the coordinates of first point"<<endl;
	cin>>x1>>y1;
	cout<<"Enter the coordinates of second point"<<endl;
	cin>>x2>>y2;
	dx=x2-x1;
	dy=y2-y1;
	int p= 2*dy-dx;
	cout<<"Required line is :"<<endl;
	putpixel(x1,y1,15);
	for(int i=1;i<dy;i++)
	{
		x1=x1+1;
		if(p<0)
		{
			p=p+2*dy;
		}
		else
		{
			p=p+2*dy-2*dx;
			y1=y1+1;
		}
		putpixel(x1,y1,15);
	}
getch();
}
