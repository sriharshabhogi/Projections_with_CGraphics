#include<iostream>
#include<graphics.h>
#include<conio.h>

using namespace std;
class point
{
	public:
		int x,y,z;
};

class lyne
{
	public:
		point start,end;
		
};

point newpoint(int x1,int y1,int z1)
		{
			point idi;
			idi.x=x1;
			idi.y=y1;
			idi.z=z1;
			return idi;
		}
		
lyne newlyne(int x1,int y1,int z1,int x2,int y2,int z2)
		{
			lyne idi;
			idi.start.x=x1;
			idi.start.y=y1;
			idi.start.z=z1;
			idi.end.x=x2;
			idi.end.y=y2;
			idi.end.z=z2;
			return idi;
		}
		


int main()
{
   int gd = DETECT,gm;
   int i;
   point per=newpoint(0,0,-500); //initial perspective point
   char opt;
   int x31,y31,x32,y32;
   float s31,w31,s32,w32;
   float x1,y1,z1,x2,y2,z2;
   float zed=0;
   
   lyne lyn[12];
   lyn[0]=newlyne(-100,-100,-100,100,-100,-100);
   lyn[1]=newlyne(-100,-100,-100,-100,-100,100);
   lyn[2]=newlyne(-100,-100,-100,-100,100,-100);
   
   lyn[3]=newlyne(100,100,100,-100,100,100);
   lyn[4]=newlyne(100,100,100,100,-100,100);
   lyn[5]=newlyne(100,100,100,100,100,-100);
   
   lyn[6]=newlyne(100,100,-100,100,-100,-100);
   lyn[7]=newlyne(-100,100,-100,100,100,-100);
   lyn[8]=newlyne(-100,100,-100,-100,100,100);
   lyn[9]=newlyne(-100,100,100,-100,-100,100);
   lyn[10]=newlyne(-100,-100,100,100,-100,100);
   lyn[11]=newlyne(100,-100,-100,100,-100,100);
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   
   do
   {
   for(i=0;i<12;i++)
   {
   	    
   	    x1=lyn[i].start.x;
   	    y1=lyn[i].start.y;
   	    z1=lyn[i].start.z;
   	    x2=lyn[i].end.x;
   	    y2=lyn[i].end.y;
   	    z2=lyn[i].end.z;
   	    s31=(z1*per.x-x1*per.z+zed*(x1-per.x))/(z1-per.z);
   	    w31=(z1*per.y-y1*per.z+zed*(y1-per.x))/(z1-per.z);
   	    s32=(z2*per.x-x2*per.z+zed*(x2-per.x))/(z2-per.z);
   	    w32=(z2*per.y-y2*per.z+zed*(y2-per.x))/(z2-per.z);
   	    x31=s31;
   	    y31=w31;
   	    x32=s32;
   	    y32=w32;
    	line(x31+300,y31+200,x32+300,y32+200);
   }
   opt=getch();
   if(opt==43)
   {
   	zed+=50;
   	per.z+=50;
   }
   else if(opt==45)
   {
   	{
   	zed-=50;
   	per.z-=50;
   }
   }

   cleardevice();
   }
   while(opt==43||opt==45);
   getch();
   closegraph();
   return 0;
}
