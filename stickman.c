#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <X11/Xlib.h>

void lineDraw(float xi , float yi, float xf , float yf){
	float i, dx, dy , xoff , yoff , steps , x ,y;
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
		//if((int)i%5 == 0)
		//putpixel(x,y,BLACK);
		//else
		putpixel(x,y,5);
		x = x + xoff;
		y = y + yoff;
		i++;	
	}
//getch();

}

void floodFilling(float xc , float yc , int fill , int border ){
	int current = getpixel(xc,yc);
	if(current != border && current != fill){
		putpixel(xc,yc,fill);
		floodFilling(xc+1,yc,fill,border);
		floodFilling(xc-1,yc,fill,border);
		floodFilling(xc,yc+1,fill,border);
		floodFilling(xc,yc-1,fill,border);
	}	

}

void snow(){
	line(0,160,500,160);
	line(0,170,500,170);
	line(500,160,500,170);
	line(0,160,0,170);
	//floodFilling(300,165,WHITE,5);
}



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
		//delay(50);
		
	}

}

void move1(int i , int j){
	cleardevice();
	circleDraw(20,50+i , 50+j);
	//circleDraw(5,40+i,40+j);	
	circleDraw(5,60+i,40+j);
	line(50+i,70+j,50+i,120+j);
	line(50+i,90+j,70+i,100+j);
	line(50+i,90+j,30+i,100+j);
	line(50+i,120+j,70+i,160+j);
	line(50+i,120+j,30+i,160+j);
	snow();	
	delay(100);
}

void move2(int i , int j){
	cleardevice();
	circleDraw(20,50+i , 50+j);
	//circleDraw(5,40+i,40+j);	
	circleDraw(5,60+i,40+j);
	line(50+i,70+j,50+i,120+j);
	line(50+i,90+j,70+i,90+j);
	line(50+i,90+j,30+i,90+j);
	line(50+i,120+j,50+i,160+j);
	//line(50+i,120+j,30+i,160+j);
	snow();	
	delay(100);
}

void move3(int i , int j){
	cleardevice();
	circleDraw(20,50+i , 50+j);
	circleDraw(5,40+i,40+j);	
	circleDraw(5,60+i,40+j);
	line(50+i,70+j,50+i,120+j);
	line(50+i,90+j,70+i,100+j);
	line(50+i,90+j,30+i,100+j);
	line(50+i,120+j,70+i,160+j);
	line(50+i,120+j,30+i,160+j);
	snow();
	delay(500);
}



int main(){

	int gm , gd= DETECT;
	initgraph(&gd,&gm,NULL);
	int i,j;
		//move();
	
	for(i = 0 ; i < 100; i++){
		for(j = 1 ; j < 300 ; j++){
			snow();
			if(j%2 == 0)
				move2(j,i);
			else
				move1(j,i);
			if(j%10 == 0)
				move3(j,i);
		}
	}
getch();
}
