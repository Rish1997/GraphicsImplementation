#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <X11/Xlib.h>

float scale(float x1 , float factor){
	return x1*factor;
		
}

void plot(float xk, float yk, float xc, float yc){
		putpixel(xk + xc , yk + yc ,4);
		putpixel((-1 * xk) + xc, yk + yc, 4);
		putpixel(yk + xc, (-1 * xk) + yc ,4);
		putpixel((-1 * yk) + xc, (-1 * xk) + yc,4);
		putpixel(( -1 * xk) +xc, ( -1 * yk ) + yc,4);
		putpixel(xk + xc, (-1 * yk) + yc,4);
		putpixel((-1 * yk) + xc, (xk) + yc,4);
		putpixel(yk + xc, xk + yc,4);
}

void circleDraw(float radius , float xc , float yc , float factor){
	cleardevice();
	float xk , yk , pk;
	//printf("Enter the radius : ");
	//scanf("%f" , &radius);
	//printf("Coordinate of center : ");
	//scanf("%f %f " , &xc , &yc);
	pk = 5/4.0 - radius;
	xk = 0;
	yk = radius;
	
	while(xk <= yk){
		plot(xk*factor,yk*factor,xc,yc);
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
		//delay(50);
		
	}
	delay(2000);
}

int main(){
	int gm , gd= DETECT,i;
	initgraph(&gd,&gm,NULL);
	float radius, x1 , y1 , factor;
	printf("Enter Radius : ");
	scanf("%f" , &radius);
	printf("\nEnter Center Coordinates : "); 
	scanf("%f %f" , &x1, &y1);
	printf("\nEnter Factor by which to scale : ");
	scanf("%f",&factor);
	for(i =1 ; i < factor;i++){
		circleDraw(radius,x1,y1,i);
		delay(4000);
	}
	
	
	
	
return 0;
}
