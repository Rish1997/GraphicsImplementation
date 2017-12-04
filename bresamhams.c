#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <X11/Xlib.h>

int main(){
	int gm , gd= DETECT;
	initgraph(&gd,&gm,NULL);
	float x1 , x2 , y1 , xk , yk , y2 , dx , dy , diff2, p0 , pk;
	printf("Enter first coordinate : " );
	scanf("%f %f" , &x1 , &y1);
	printf("Enter second coordinate : " );
	scanf("%f %f" , &x2 , &y2);
	printf("line between (%f,%f) and (%f,%f)",x1,y1,x2,y2);
	xk = x1;
	yk = y1;
	dx = x2-x1;
	dy = y2-y1;
	diff2 = 2*dy - 2*dx;
	p0 = 2*dy - dx;
	pk = p0;
	putpixel(xk,yk ,1);
	int i = 0 , steps;
	if(dx > dy){
		steps = (int)dx;
		printf("%d" , steps);
		while(i++ <= dx){
			if(pk < 0){
				xk+=1;
				yk = yk;
				pk = pk + 2*dy;
			}
			else{
				xk+=1;
				yk+=1;
				pk = pk + 2*dy - 2*dx;
			}
			//printf("(%f %f)\n", xk ,yk);	
			putpixel(xk , yk , 1);
			delay(100);
		}
	}
	else{
		steps = (int)dy;
		printf("%d" , steps);
		while(i++ <= dy){
			if(pk < 0){
				yk+=1;
				xk = yk;
				pk = pk + 2*dx;
			}
			else{
				xk+=1;
				yk+=1;
				pk = pk + 2*dx - 2*dy;
			}	
			//printf("(%f %f)\n", xk ,yk);
			putpixel(xk , yk , 1);
			delay(100);
		}
	
	}
getch();		
return 0;	
}
