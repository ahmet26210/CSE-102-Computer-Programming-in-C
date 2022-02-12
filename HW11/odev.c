#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
typedef struct sayi
{
	int sayi1;
	int sayi2;
}sayi;
int* fill_array();
node* fill_linkedlist();
sayi* find_diff(int *arrey,node *element,int *counter);
float* stats_array(int *arrey,int counter);
node* read_linkedlist(char *filename,int *counter);
int* read_array(char *filename,int *counter);
float* stats_linkedlist(node *element,int counter);
int main(){
	int *number,byte1=0,counter=0,byte2=0,counter1=0,i,*number1,counter3;
	double time_taken1,time_taken4,time_taken2,time_taken3,sonuc1=0.0;
	double sonuc2=0.0,sonuc3=0.0,sonuc4=0.0;
	char *filename="list.txt";
	float *arrey,*arrey1;
	arrey=(float*)malloc(4*sizeof(float));//for min max mean std
	number=read_array(filename,&byte1);
	counter=byte1/4;
	arrey=stats_array(number,counter);
	printf("------------------------------------------------------------------------------\n");
	printf("For (*read_array)\n");
	printf("Number of byte used :%d\n",byte1);
	printf("Min			 Max		Mean			STD\n");
	printf("%5.2f		%5.2f		%5.2f		%5.2f\n",arrey[0],arrey[1],arrey[2],arrey[3]);
	printf("------------------------------------------------------------------------------\n");
	printf("\n\n");

	node *temp1;
	temp1=(node*)malloc(sizeof(node));//for return value
	arrey1=(float*)malloc(4*sizeof(float));
	temp1=read_linkedlist(filename,&byte2);
	counter1=byte2/16;//for finding the number in fp
	arrey1=stats_linkedlist(temp1,counter1);
	printf("------------------------------------------------------------------------------\n");
	printf("For (*read_linkedlist)\n");
	printf("Number of byte used :%d\n",byte2);
	printf("Min			 Max		Mean			STD\n");
	printf("%5.2f		%5.2f		%5.2f		%5.2f\n",arrey1[0],arrey1[1],arrey1[2],arrey1[3]);
	printf("------------------------------------------------------------------------------\n");
	for(i=0;i<4;i++){//find the average time of function 
		clock_t t;
		t=clock();
		read_array(filename,&byte1);
		t=clock()-t;
		time_taken1=((double)t)/CLOCKS_PER_SEC;
		sonuc1+=time_taken1;
	}
	sonuc1=sonuc1/4;

	for(i=0;i<4;i++){//find the average time of function
		clock_t t1;
		t1=clock();
		read_linkedlist(filename,&byte2);
		t1=clock()-t1;
		time_taken2=((double)t1)/CLOCKS_PER_SEC;
		sonuc2+=time_taken2;
	}
	sonuc2=sonuc2/4;

	for(i=0;i<4;i++){//find the average time of function
		clock_t t2;
		t2=clock();
		stats_array(number,counter);
		t2=clock()-t2;
		time_taken3=((double)t2)/CLOCKS_PER_SEC;
		sonuc3+=time_taken3;
	}
	sonuc3=sonuc3/4;

	for(i=0;i<4;i++){//find the average time of function
		clock_t t3;
		t3=clock();
		stats_linkedlist(temp1,counter1);
		t3=clock()-t3;
		time_taken4=((double)t3)/CLOCKS_PER_SEC;
		sonuc4+=time_taken4;
	}
	sonuc4=sonuc4/4;
	printf("Average Time (Calculated 4 Time) Passed in (*read_array) %lf (s)\n",sonuc1);
	printf("Average Time (Calculated 4 Time) Passed in (*stats_array) %lf(s)\n",sonuc3);
	printf("Average Time (Calculated 4 Time) Passed in (*read_linkedlist) %lf (s)\n",sonuc2);
	printf("Average Time (Calculated 4 Time) Passed in (*stats_linkedlist) %lf (s)\n",sonuc4);
	
	printf("\n\n\n");
	printf("------------PART2---------\n");
	number1=fill_array();
	node *temp2;
	sayi *temp3;
	temp2=(node*)malloc(sizeof(node));
	temp2=fill_linkedlist();
	temp3=find_diff(number1,temp2,&counter3);
	for(int k=0;k<counter3;k++){
		printf("Different numbers are %d %d\n",temp3[k].sayi1,temp3[k].sayi2);	
	}
	return 0;
}
int* read_array(char *filename,int *counter){//we did int* for return arrey
	int *p,sayac=0,i,sayi;
	char ch;
	p=(int*)malloc(2*sizeof(int));
	if(p==NULL){
		printf("yer açılamadı");
	}
	FILE *fp;
	fp=fopen(filename,"r");
	while(!feof(fp)){
		fscanf(fp,"%d",&sayi);
		fscanf(fp,"%c",&ch);
		p[sayac]=sayi;
		sayac++;
		p=(int*)realloc(p,(sayac+2)*sizeof(int));//for opening the place
	}
	*counter=(sayac-1)*4;//for finding the byte used 
	p[sayac-1]=-1;
	return p;
	free(p);//for clearing the arrey and its adress
	fclose(fp);
}
node* read_linkedlist(char *filename,int *counter){//we did node* for return structure
	int number;
	int sayac=0;
	char ch;
	node *temp;
	node *element=(node*)malloc(sizeof(node));
	temp=element;//for reaching the start of the linked list
	FILE *fp;
	fp=fopen(filename,"r");
	while(!feof(fp)){
		fscanf(fp,"%d",&number);
		fscanf(fp,"%c",&ch);
		element->data=number;
		element->next=(node*)malloc(sizeof(node));
		element=element->next;
		sayac++;
	}
	*counter=(sayac-1)*16;//for finding the byte used for linked list
	element->data=-1;
	element->next=NULL;
	element=temp;//we reach the start of linked list
	fclose(fp);
	return element;
}

float* stats_array(int *arrey,int counter){//we did *float for return float arrey
	int sayac=0;
	float mean,Std=0.0,standartdeviation=0.0;
	float sonuc=0.0,max,min;
	float *arrey1;
	arrey1=(float*)malloc(4*sizeof(float));
	max=arrey[0];
	min=arrey[0];
	while(arrey[sayac]==-1){
		sayac++;
		arrey=(int*)realloc(arrey,(sayac+2)*sizeof(int));
	}
	for(int i=0;i<counter;i++){
		if(arrey[i]>max){
			max=arrey[i];
		}
		else if(arrey[i]<min){
			min=arrey[i];
		}
		sonuc+=arrey[i];
	}
	mean=sonuc/counter;
	for(int j=0;j<counter;j++){
		Std+=(arrey[j]-mean)*(arrey[j]-mean);
	}
	standartdeviation=sqrt(Std/counter);
	arrey1[0]=max;
	arrey1[1]=min;
	arrey1[2]=mean;
	arrey1[3]=standartdeviation;
	return arrey1;
	free(arrey);
}
float* stats_linkedlist(node *element,int counter){//we did float* for return float arrey
	int sayac=0,i=0;
	float mean,Std=0.0,standartdeviation=0.0;
	float sonuc=0.0,max,min;
	float *arrey1;
	arrey1=(float*)malloc(4*sizeof(float));//for float arrey
	node *temp1;
	temp1=element;
	max=element->data;
	min=element->data;
	while(element->data!=-1){
		sayac++;
		if(element->data>max){
			max=element->data;
		}
		else if(element->data<min){
			min=element->data;
		}
		sonuc+=element->data;
		element=element->next;
		i++;
	}
	mean=sonuc/counter+1;
	element=temp1;
	for(int j=0;j<counter;j++){
		Std+=(element->data-mean)*(element->data-mean);
		element=element->next;
	}
	standartdeviation=sqrt(Std/counter);
	arrey1[0]=max;
	arrey1[1]=min;
	arrey1[2]=mean;
	arrey1[3]=standartdeviation;
	return arrey1;
	
}
int* fill_array(){
	int *p,sayac=0,number,number1,i,control;
	p=(int*)malloc(2*sizeof(int));
	printf("if you break to enter the number ,please enter 0\n");
	while(number!=0){//enter the number until enter 0
		printf("Enter number for arrey\n");
		scanf("%d",&number);
		p[sayac]=number;
		sayac++;
		p=(int*)realloc(p,(sayac+2)*sizeof(int));
	}
	printf("Dynamic array:{");
	for(i=0;i<sayac-1;i++){
		printf("%d",p[i]);
		if(i==sayac-2){
			break;
		}
		else{
			printf(",");
		}
	}
	printf("}\n");
	return p;
}
node* fill_linkedlist(){
	int number,i;
	char ch;
	node *temp;
	node *element=(node*)malloc(sizeof(node));
	temp=element;
	int sayac=0;
	printf("if you break to enter the number ,please enter 0\n");
	while(number!=0){
		printf("Enter number for linked list: \n");
		scanf("%d",&number);
		element->data=number;
		element->next=(node*)malloc(sizeof(node));
		element=element->next;
		sayac++;
	}
	element->next=NULL;
	element=temp;
	
	printf("Linked List:{");
	for(i=0;i<sayac-1;i++){
		printf("%d",element->data);
		element=element->next;
		if(i==sayac-2){
			break;
		}
		else{
			printf(",");
		}
	}
	printf("}\n");
	element=temp;
	return element;
}
sayi* find_diff(int *arrey,node *element,int *counter){//we did *sayi for return structure
	int i=0,sayac=0,j;
	node *temp1;
	sayi *number=(sayi*)malloc(sizeof(sayi));//open place
	while(arrey[i]!=0){//reach the end of arrey
		sayac++;
		arrey=(int*)realloc(arrey,(sayac+2)*sizeof(int));
		i++;
	}
	j=0;
	i=0;
	sayac=0;
	while(arrey[i]!=0){
		if(element->data!=arrey[i]){//find the different number
			number[j].sayi1=element->data;//assign the value to the sayi structure
			number[j].sayi2=arrey[i];
			number=realloc(number,(sayac+2)*sizeof(sayi));//open place for number structure
			sayac++;
			j++;
		}
		i++;
		element=element->next;//reach the end of linked list
	}
	*counter=sayac;
	return number;
}
