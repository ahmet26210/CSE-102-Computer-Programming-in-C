#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct point2D
{
	double x;
	double y;
	struct point2D *nextp;
}point2D;

typedef struct Color
{	
	double red;
	double blue;
	double green;
}Color;
typedef struct Figure
{
	double llx,lly,urx,ury;
	double resolution;
	double thickness;	
	Color color;
	point2D *point;
}Figure;

Figure *start_figure(double width,double height);
void set_thickness_resolution(Figure *figure1,double thickness,double resolution);
double pos_ellipse_func(double x);
double neg_ellipse_func(double x);
void draw_polyline(Figure *figure1,point2D *poly_line,int n);
void draw_polygon(Figure *figure1,point2D *poly_line,int n);
void scale_figure(Figure *figure1,double scale_x,double scale_y);
void append_figures(Figure *figure1,Figure *figure2);
void resize_figure(Figure *figure1,point2D *start_roi,point2D *end_roi);
void insert_point(point2D *headp,double x,double y);
void set_color(Figure *figure1,Color c);
void draw_fx(Figure *figure1,double f(double x),double start_x,double end_x);
Figure *start_figure(double width,double height){
	Figure *figure1;
	figure1=(Figure*)malloc(sizeof(Figure));
	figure1->urx=width/2.0;
	figure1->ury=height/2.0;
	figure1->llx=-width/2.0;
	figure1->lly=-height/2.0;
	return figure1;
}
void set_thickness_resolution(Figure *figure1,double thickness,double resolution){
	figure1->thickness=thickness;
	figure1->resolution=resolution;
}
void set_color(Figure *figure1,Color c){
	figure1->color.red=c.red;
	figure1->color.blue=c.blue;
	figure1->color.green=c.green;
}
void insert_point(point2D *headp,double x,double y){//add the newp end of the list
	point2D *tempp,*newp;
	tempp=headp;
	while(tempp->nextp!=NULL){
		tempp=tempp->nextp;
	}
	newp=(point2D*)malloc(sizeof(point2D));
	newp->x=x;
	newp->y=y;
	newp->nextp=NULL;
	tempp->nextp=newp;
}
void draw_fx(Figure *figure1,double f(double x),double start_x,double end_x){
	double temp,temp1;
	point2D *headp=(point2D*)malloc(sizeof(point2D));;
	headp->x=start_x;
	headp->y=f(start_x);
	temp=start_x;
	temp1=(1.0/figure1->resolution);
	for(temp;temp<=end_x;temp+=temp1){
		insert_point(headp,temp,f(temp));
	}
	figure1->point=headp;	
}
void draw_polyline(Figure *figure1,point2D *poly_line,int n){
	int sayac=0,i,j=0;
	point2D *point=(point2D*)malloc(sizeof(point2D));
	point->x=poly_line[i].x;
	point->y=poly_line[i].y;
	for(i=1;i<n;i++){
		insert_point(point,poly_line[i].x,poly_line[i].y);
	}
	figure1->point=point;
}
void draw_polygon(Figure *figure1,point2D *poly_line,int n){
	int sayac=0,i,j=0;
	point2D *point=(point2D*)malloc(sizeof(point2D));
	point->x=poly_line[i].x;
	point->y=poly_line[i].y;
	for(i=1;i<n;i++){
		insert_point(point,poly_line[i].x,poly_line[i].y);
	}
	poly_line[i].nextp=point->nextp;
	figure1->point=point;
}
void draw_ellipse(Figure *figure1,point2D *center,point2D *width_height){
	double start_x,end_x;
	Figure *figure2=(Figure*)malloc(sizeof(Figure));
	point2D *cursor;
	double a=width_height->x;
	double b=width_height->y;
	double pos_ellipse_func(double x){
		return sqrt((1-((x*x))/(a*a))*(b*b));
	}
	double neg_ellipse_func(double x){
		return -sqrt((1-((x*x))/(a*a))*(b*b));
	}
	figure2->llx=figure1->llx;
	figure2->lly=figure1->lly;
	figure2->urx=figure1->urx;
	figure2->ury=figure1->ury;
	figure2->resolution=figure1->resolution;
	figure2->thickness=figure1->thickness;
	start_x=-width_height->x;
	end_x=width_height->x;
	draw_fx(figure1,pos_ellipse_func,start_x,end_x);
	draw_fx(figure2,neg_ellipse_func,start_x,end_x);
	append_figures(figure1,figure2);
	if(center->x!=0||center->y!=0){
		cursor=figure1->point;
		while(cursor!=NULL){
			cursor->x+=center->x;
			cursor->y+=center->y;
			cursor=cursor->nextp;
		}
	}
}
void resize_figure(Figure *figure1,point2D *start_roi,point2D *end_roi){
	figure1->llx=start_roi->x;
	figure1->lly=start_roi->y;
	figure1->urx=end_roi->x;
	figure1->ury=end_roi->y;
}
void scale_figure(Figure *figure1,double scale_x,double scale_y){
	point2D *tempp=figure1->point;
	while(tempp->nextp!=NULL){
		tempp->x*=scale_x;
		tempp->y*=scale_y;
		tempp=tempp->nextp;
	}
}
void append_figures(Figure *figure1,Figure *figure2){
	point2D *tempp=figure1->point;
	insert_point(figure1->point,figure2->point->x,figure2->point->y);
	while(tempp->nextp!=NULL){
		tempp=tempp->nextp;	
	}
	tempp->nextp=figure2->point->nextp;
}
void export_eps(Figure *figure1,char *file_name){
	FILE *fp=fopen(file_name,"wt");
	point2D *tempp;
	fprintf(fp,"%%!PS-adobe-3.0 EPSF-3.0\n");
	fprintf(fp,"%%%%BoundingBox: %d %d %d %d\n",(int)figure1->llx,(int)figure1->lly,(int)figure1->urx,(int)figure1->ury);
	fprintf(fp,"%d setlinewidth\n",(int)figure1->thickness);
	fprintf(fp,"%lf %lf %lf colors\n",figure1->color.red,figure1->color.blue,figure1->color.green);
	fprintf(fp,"%lf %lf moveto\n",figure1->point->x,figure1->point->y);
	for(tempp=figure1->point->nextp;tempp!=NULL;tempp=tempp->nextp){
		fprintf(fp,"%lf %lf\n",tempp->x,tempp->y);
		fprintf(fp,"lineto\n");
	}
	fprintf(fp,"stroke\n");
	fclose(fp);
}
