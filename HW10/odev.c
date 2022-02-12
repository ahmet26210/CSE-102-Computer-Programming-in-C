
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define PI 3.14159265358979323846

typedef struct points
{
	char name[10];
	double x;
	double y;
}points;

typedef struct line
{
	char name[10];
	struct points endpoint;
	struct points startpoint;
	double lengthofline;
}line;

typedef struct polygons
{
	char name[10];
	struct points nokta1[20];
	struct line line1[20];
}polygons;
void control2(char temp[20][5],int number1,int kosesayisi,polygons dizi2[100],points dizi[100],line dizi1[100]);
void control1(char temp[20][5],int number1,line dizi1[100],points dizi[100]);
void control(char temp[20][5],int number1,points dizi[100]);
double distance_point(points point1,points point2);
double distance_p_l(points point1,line line1);
double angle(line L1,line L2);
void length_line(line L1);
double find_area(polygons PG,int kosesayisi);
double perimeter(polygons PG,int kosesayisi);
int main()
{
	points dizi[100];
	line dizi1[100];
	polygons dizi2[100];
	int i=0,j=0,k=0,sayi,number=0,number1=0,number2=0,sayi1;
	int number3=0,number4=0,number5=0,number6=0;
	char temp[20][5],temp1[1][10],temp2[1][10],temp3[3][20],numbers,num;
	char ch='a',temp5[10];
	int kosesayisi;
	double dispoi=0.0,displ=0.0,anglesonuc=0.0,area=0.0,peri=0.0;
	FILE *fp;
	if((fp=fopen("commands.txt", "r"))==NULL)
	{
		printf("reading error!!\n");
		//exit(0); 	
	}
	fscanf(fp,"%s",temp1[j]);
	fscanf(fp,"%s",temp1[j]);
	sayi=(numbers-'\0');
	printf("HATAYI ÇÖZEMEDIM HOCAM :/\n");
	for(i=0;i<10;i++){
		for(k=0;k<20;k++){
			ch='a';
			fscanf(fp,"%s",temp[k]);
			if(temp[k][0]=='P'&&temp[k][1]=='G'){
				while(ch!='\n'){
					fscanf(fp,"%c",&ch);
				}
				kosesayisi=k;
				break;
			}
			else if(temp[k][0]=='P'){
				while(ch!='\n'){
					fscanf(fp,"%c",&ch);	
				}
				break;	
			}
			else if(temp[k][0]=='L'){
				while(ch!='\n'){
					fscanf(fp,"%c",&ch);		
				}
				break;
			}
		}
			
		if(temp[k][0]=='P'&&temp[k][0]=='G'){
				control2(temp,number2,kosesayisi,dizi2,dizi,dizi1);
			number2++;
		}
		else if(temp[k][0]=='P'){
			control(temp,number,dizi);
			number++;
		}
		else if(temp[k][0]=='L'){
			control1(temp,number1,dizi1,dizi);
			number1++;
		}
	}
	
	fscanf(fp,"%s",temp1[j]);
	fscanf(fp,"%s",temp1[j]);
	fscanf(fp,"%s",temp1[j]);
	sayi1=(num-'\0');
	for(i=0;i<2;i++){
		fscanf(fp,"%s",temp3[k]);
		while(ch!='\n'){
			fscanf(fp,"%c",&ch);	
		}
	}
	if(temp3[0][0]=='D'){
		for(j=0;j<100;j++){
			if(dizi[j].name==temp3[1]){
				number3=j;
			}	
		}
		for(j=0;j<100;j++){
			if(dizi[j].name==temp3[2]){
				number4=j;
			}	
		}				
		dispoi=distance_point(dizi[number3],dizi[number4]);
		printf("Distance(%s,%s)=%lf",temp3[1],temp3[2],dispoi);
	}
	for(i=0;i<5;i++){
		fscanf(fp,"%s",temp3[0]);
		fscanf(fp,"%s",temp3[1]);
		if(temp3[0][0]=='D'&&temp3[1][0]=='P'){
			fscanf(fp,"%s",temp3[2]);
			for(j=0;j<100;j++){
				if(dizi[j].name==temp3[1]){
					number3=j;
				}	
			}
			for(j=0;j<100;j++){
				if(dizi[j].name==temp3[2]){
					number4=j;
				}	
			}				
		dispoi=distance_point(dizi[number3],dizi[number4]);
		printf("Distance(%s,%s)=%lf",temp3[1],temp3[2],dispoi);
		}
		else if(temp3[0][0]=='D'&&temp3[2][0]=='L'){
			fscanf(fp,"%s",temp3[2]);
			for(j=0;j<100;j++){
				if(dizi[j].name==temp3[1]){
					number3=j;
				}		
			}
			for(j=0;j<100;j++){
				if(dizi1[j].name==temp3[2]){
					number4=j;
				}
						
			}
		displ=distance_p_l(dizi[number3],dizi1[number4]);
		printf("Distance(%s,%s)=%lf",temp3[1],temp3[2],displ);
		}
		else if(temp3[0][0]=='A'&&temp3[0][1]=='N'){
			fscanf(fp,"%s",temp3[2]);
			for(j=0;j<100;j++){
				if(dizi1[j].name==temp3[1]){
					number3=j;
				}	
			}
			for(j=0;j<100;j++){
				if(dizi1[j].name==temp3[2]){
					number4=j;
				}	
			}	
			anglesonuc=angle(dizi1[number3],dizi1[number4]);
		printf("Angle(%s,%s)=%lf",temp3[1],temp3[2],anglesonuc);
		}	
		else if(temp3[0][0]=='L'&&temp3[1][0]=='L'){
			for(j=0;j<100;j++){
				if(dizi2[j].name==temp3[1]){
					number3=j;
				}	
			}
			length_line(dizi1[number3]);
		}
		else if(temp3[0][0]=='A'&&temp3[0][1]=='R'){
			for(j=0;j<100;j++){
				if(dizi2[j].name==temp3[1]){
					number3=j;
				}	
			}
			area=find_area(dizi2[number3],kosesayisi);
			printf("Area(%s)=%lf",temp3[1],area);
		}
		else if(temp3[0][0]=='L'&&temp3[1][0]=='P'){
			for(j=0;j<100;j++){
				if(dizi2[j].name==temp3[1]){
					number3=j;
				}	
			}
			
			peri=perimeter(dizi2[number3],kosesayisi);
			printf("Area(%s)=%lf",temp3[1],peri);
		}
	}
	fclose(fp);
	return 0;
}

double distance_point(points point1,points point2){
	double sonuc;
	sonuc=sqrt((point1.x-point2.x)*(point1.x-point2.x)-(point1.y-point2.y)*(point1.y-point2.y));
	
	if(sonuc<0){
		sonuc=-sonuc;
	}
	return sonuc;
}
double distance_p_l(points point1,line line1){
	double sonuc,sonuc1;
	sonuc=(line1.startpoint.x+line1.endpoint.x)/2;
	sonuc1=sonuc-point1.x;
	return sonuc1;
}
double angle(line L1,line L2){
	//<u.v>=|u|.|v|.cosa
	double sonuc,sonuc1,sonuc2,sonuc3,result;
	
	sonuc1=sqrt(L1.startpoint.x*L1.startpoint.x+L1.startpoint.y*L1.startpoint.y);
	sonuc2=sqrt(L2.startpoint.x*L2.startpoint.x+L2.startpoint.y*L2.startpoint.y);
	sonuc3=L1.startpoint.x*L2.startpoint.x+L1.startpoint.y*L2.startpoint.y;
	sonuc=sonuc3/(sonuc1*sonuc2);
	return 180*(acos(sonuc)/PI);

}
void length_line(line L1){
	distance_point(L1.endpoint,L1.startpoint);
	
}
double perimeter(polygons PG,int kosesayisi){
	int i=1;
	double sonuc=0.0;
	double result;
	int turn=TRUE;
	while(turn=TRUE){
		if(i=kosesayisi){
			result=distance_point(PG.nokta1[i],PG.nokta1[1]);
			sonuc+=result;
			turn=FALSE;
		}
		else{
			result=distance_point(PG.nokta1[i],PG.nokta1[i+1]);
			sonuc+=result;	
		}
		i++;
	}
	return sonuc;
}
double find_area(polygons PG,int kosesayisi){
	double sonuc=0.0;
	double result;
	int i=1,j=2,k=1;
	int turn=TRUE;
	while(turn=TRUE){
		if(k=kosesayisi){
	result=PG.nokta1[i].x*PG.nokta1[1].y-PG.nokta1[i].y*PG.nokta1[1].x;
		sonuc+=result;
			turn=FALSE;
		}
		else{
	result=PG.nokta1[i].x*PG.nokta1[j].y-PG.nokta1[i].y*PG.nokta1[j].x;
		sonuc+=result;
		}
		i++;
		j++;
		k++;
	}
	return sonuc/2;
}
void control(char temp[20][5],int number1,points dizi[100]){
	int i=0;
	double arrey[1];
	sscanf(temp[0],"%lf",&arrey[0]);
	sscanf(temp[1],"%lf",&arrey[1]);
	
	dizi[number1].x=arrey[0];
	dizi[number1].y=arrey[1];
	strcpy(dizi[number1].name,temp[2]);
}
void control1(char temp[20][5],int number1,line dizi1[100],points dizi[100]){
	int i=0,sayi,sayi1;
	for(i=0;i<100;i++){
		if(dizi[i].name==temp[0]){
			sayi=i;
			break;
		}				
	}
	for(i=0;i<100;i++){
		if(dizi[i].name==temp[1]){
			sayi1=i;
			break;
		}	
	}
	dizi1[number1].startpoint=dizi[sayi];
	dizi1[number1].endpoint=dizi[sayi1];
	strcpy(dizi1[number1].name,temp[2]);
}
void control2(char temp[20][5],int number1,int kosesayisi,polygons dizi2[100],points dizi[100],line dizi1[100]){
	int i,j,sayi;
	for(i=0;i<kosesayisi;i++){
		if(temp[0][0]=='P'){
			if(i=kosesayisi){
				strcpy(dizi2[number1].name,temp[i]);
			}
			else{
				for(j=0;j<100;j++){
					if(dizi[j].name==temp[i]){
						sayi=j;
						break;
					}				
				}
				dizi2[number1].nokta1[i+1]=dizi[sayi];
			}
		}
		else if(temp[0][0]=='L'){
			if(i=kosesayisi){
				strcpy(dizi2[number1].name,temp[i]);
			}
			else{
				for(j=0;j<100;j++){
					if(dizi1[j].name==temp[i]){
						sayi=j;
						break;
					}				
				}
				dizi2[number1].line1[i+1]=dizi1[sayi];
			}
		}		
	}
}
