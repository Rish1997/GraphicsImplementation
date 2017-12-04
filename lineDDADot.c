#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <X11/Xlib.h>
int main(){
	XInitThreads();
	int gm , gd= DETECT;
	initgraph(&gd,&gm,NULL);
	float xi, i , yi, xf, yf , dx, dy , xoff , yoff , steps , x ,y;
	printf("Enter the initial values of x and y respectively : ");
	scanf("%f %f" , &xi , &yi);
	printf("Enter the final values of x and y : ");
	scanf("%f %f" , &xf , &yf);
	dx = abs(xf-xi);
	dy = abs(yf-yi);
	if(dx > dy)
		steps = dx;
	else 
		steps = dy;
	xoff = dx/steps;
	yoff = dy/steps;
	x = xi + 0.5*floor(dx);
	y = yi + 0.5*floor(dy);
	i=1;
	while(i<steps){
		if((int)i%2 == 0)
		putpixel(x,y,BLACK);
		else
		putpixel(x,y,5);
		x = x + xoff;
		y = y + yoff;
		i++;	
	}
getchar();
return 0;
} 
