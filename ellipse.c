#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <X11/Xlib.h>

void plot(float xc , float yc , float x1 , float y1){
	putpixel(xc+x1,yc+y1,1);
	putpixel(xc-x1,yc+y1,1);
	putpixel(xc+x1,yc-y1,1);
	putpixel(xc-x1,yc-y1,1);	
}

int main(){
	int gm , gd= DETECT;
	initgraph(&gd,&gm,NULL);
	float xk , yk , xc , yc , rx , ry , pk;
	printf("Enter the coordinates of Center  : " );
	scanf("%f %f", &xc,&yc);
	printf("Enter horizontal and vertical radius of ellipse : ");
	scanf("%f %f" , &rx , &ry);
	pk = ry * ry + 0.25 * rx* rx - rx*rx*ry;
	xk = 0;
	yk = ry;
	plot(xc , yc, xk , yk);
	//p20 = rx*rx*ry*ry + rx*ry*ry - 2*ry*rx*rx +rx*rx + ry*ry/2;
	while(xk < yk ){
		xk+=1;
		if(pk<0){
			pk = pk + 2*ry*ry*rx + ry*ry;
		}
		else{
			yk-=1;
			pk = pk + 2*ry*ry*rx - 2*rx*rx*ry + ry*ry;
		}
		plot(xc,yc,xk,yk)	;	
	}  	
	pk = ry*ry*(xk+0.5)*(xk+0.5) + rx*rx*(yk-1)*(yk-1) - rx*rx*ry*ry;
	while(yk>0){
		yk--;
		if(pk >0){
			pk = pk - 2*rx*rx*ry + rx*rx*ry*ry;
		}
		else{
			xk+=1;
			pk = pk + 2*ry*ry*rx - 2*rx*rx*ry + rx*rx*ry*ry;
		}
		plot(xc , yc , xk , yk);
	}

getch();
return 0;
}
