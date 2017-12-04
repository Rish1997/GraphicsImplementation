#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <X11/Xlib.h>

void circleDraw(float radius , float xc , float yc){
	float xk , yk , pk;
	//printf("Enter the radius : ");
	//scanf("%f" , &radius);
	//printf("Coordinate of center : ");
	//scanf("%f %f " , &xc , &yc);
	pk = 5/4.0 - radius;
	xk = 0;
	yk = radius;
	
	while(xk <= yk){
		putpixel(xk + xc , yk + yc ,4);
		putpixel((-1 * xk) + xc, yk + yc, 4);
		putpixel(yk + xc, (-1 * xk) + yc ,4);
		putpixel((-1 * yk) + xc, (-1 * xk) + yc,4);
		putpixel(( -1 * xk) +xc, ( -1 * yk ) + yc,4);
		putpixel(xk + xc, (-1 * yk) + yc,4);
		putpixel((-1 * yk) + xc, (xk) + yc,4);
		putpixel(yk + xc, xk + yc,4);
		if(pk < 0){
			xk++;
			yk = yk;
			pk = pk + 2*xk +1;		
		}
		else{
			xk++;
			yk--;
			pk = pk + 2*xk + 1 - 2*yk;
		}
		delay(50);
		
	}

}

void floodFilling(float xc , float yc , int fill , int border ){
	int current = getpixel(xc,yc);
	if(current != border && current != fill){
		putpixel(xc,yc,fill);
		floodFilling(xc+1,yc,fill,border);
		floodFilling(xc-1,yc,fill,border);
		floodFilling(xc,yc+1,fill,border);
		floodFilling(xc,yc-1,fill,border);
		delay(5);
	}	

}


int main(){
	//XInitThreads();
	int gm , gd= DETECT;
	initgraph(&gd,&gm,NULL);
	float radius,xc,yc;
	printf("Enter the radius : ");
	scanf("%f" , &radius);
	printf("Coordinate of center : ");
	scanf("%f %f " , &xc , &yc);
	circleDraw(radius,xc,yc);
	floodFilling(xc,yc,4,8);
	getch();
return 0;
}
