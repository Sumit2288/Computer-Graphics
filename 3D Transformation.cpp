#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void main()
{
	clrscr();
	int choice;
	do
	{
		cout<<"Enter 1. for translation"<<endl;
		cout<<"Enter 2. for scaling"<<endl;
		cout<<"Enter 3. for rotation"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		int gdriver=DETECT;
		int gmode;
		initgraph(&gdriver,&gmode,"c:\\turboC3\\bgi");
		int midx,midy;
		midx = getmaxx()/2;
		midy = getmaxy()/2;
		line(0,midy,midx,midy);
		line(midx,midy,getmaxx(),midy);
		line(midx,0,midx,midy);
		line(midx,midy,midx,getmaxy());
		int l=midx+50,t=midy-70,r=midx+100,b=midy-20,depth=50,topflag=1;
		bar3d(l,t,r,b,depth,topflag);
		switch(choice)
		{
			case 1:
				int tx,ty;
				cout<<"Enter the translating factors"<<endl;
				cin>>tx>>ty;
				bar3d(l+tx,t+ty,r+tx,b+ty,depth,topflag);
				break;
			case 2:
				float sx,sy;
				cout<<"Enter the scaling factors"<<endl;
				cin>>sx>>sy;
				bar3d(l*sx,t*sy,r*sx,b*sy,depth,topflag);
				break;
			case 3:
				float angle;
				cout<<"Enter the angle"<<endl;
				cin>>angle;
				angle=(angle*3.14)/180;
				int l1=l*cos(angle) - t*sin(angle);
				int t1=t*cos(angle) + l*sin(angle);
				int r1=r*cos(angle) - b*sin(angle);
				int b1=b*cos(angle) + r*sin(angle);
				bar3d(l1,t1,r1,b1,depth,topflag);
				break;
		}
	}while(choice!=4);
	getch();
}
