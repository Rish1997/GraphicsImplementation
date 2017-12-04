#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <X11/Xlib.h>

int main(){
	int gm , gd= DETECT;
	initgraph(&gd,&gm,NULL);
	float radius , xc , yc , xk , yk , pk;
	printf("Enter the radius : ");
	scanf("%f" , &radius);
	printf("Coordinate of center : ");
	scanf("%f %f " , &xc , &yc);
	pk = 5/4.0 - radius;
	xk = 0;
	yk = radius;
	
	while(xk <= yk){
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
		putpixel(xk + xc , yk + yc ,RED);
		putpixel((-1 * xk) + xc, yk + yc, BLUE);
		putpixel(yk + xc, (-1 * xk) + yc ,GREEN);
		putpixel((-1 * yk) + xc, (-1 * xk) + yc,WHITE);
		putpixel(( -1 * xk) +xc, ( -1 * yk ) + yc,GREEN);
		putpixel(xk + xc, (-1 * yk) + yc,YELLOW);
		putpixel((-1 * yk) + xc, (xk) + yc,CYAN);
		putpixel(yk + xc, xk + yc,RED);
	}
	getch();
return 0;
}
