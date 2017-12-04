#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <X11/Xlib.h>

float* matrixMultiplication(float a[][] , float b[][]){

}

void rotate(float x1 , float y1 , float radian){

float rotationMatrix = {{cos((radian*3.14)/180),-1*sin((radian*3.14)/180),0},{sin((radian*3.14)/180),cos((radian*3.14)/180),0},{0,0,1}};
float variables = {x1,y1,0};

return matrixMultiplication(rotationMatrix,variables);	
}



int main(){
	int gm , gd= DETECT,i;
	initgraph(&gd,&gm,NULL);
	getch();
return 0;
}
