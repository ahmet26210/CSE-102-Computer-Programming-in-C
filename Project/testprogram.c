#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"PROJE.c"
Figure figure();
int main(){
	int i=0;
	int j=0;
	Figure *figures=(Figure*)malloc(5*sizeof(Figure));
	while(i<5){
		figures[i]=figure();
	}
	i=0;	
	j=0;						
	point2D *polyl=(point2D*)malloc(10*sizeof(point2D));
	while(i<10){
		polyl[i].x=j;
		polyl[i].y=j*i;
		j++;
	}
	draw_polyline(&figures[0],polyl,10);

	i=0;
	j=0;						
	point2D *polyg=(point2D*)malloc(10*sizeof(point2D));
	while(i<10){
		polyg[i].x=j;
		polyg[i].y=j*i;
		j++;
	}
	point2D *temp=(point2D*)malloc(sizeof(point2D));
	point2D *temp1=(point2D*)malloc(sizeof(point2D));
	temp1->x=60.0;temp1->y=30.0;
	temp->x=0.0;temp->y=0.0;
	//draw_polygon(&figures[1],polyg,10);
	//draw_ellipse(&figures[2],temp,temp1);
	//draw_fx(&figures[3],sin,0.0,10.0);
	//scale_figure(&figures[3],20.0,20.0);
	//append_figures(&figures[2],&figures[1]);
	//export_eps(&figures[0],"draw_polyline.eps");
	//export_eps(&figures[1],"draw_polygon.eps");
	//export_eps(&figures[2],"draw_ellipse.eps");
	//export_eps(&figures[3],"draw_fx.eps");
	//export_eps(&figures[2],"append.eps");
	return 0;
}
Figure figure(){
	Color color;
	Figure *figure1=start_figure(300,300);
	set_thickness_resolution(figure1,10,0.4);
	color.red=0;color.green=0;color.blue=0;
	set_color(figure1,color);
	return *figure1;
}
