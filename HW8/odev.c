#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 8 
void generate_hofstadters_sequence(int *arr,int n);
int find_max(int arr[],int index,int max_value);
int sum_array(int arr[]);
char* remove_duplicates(char* str);
double std_array(int arr[],double *mean,int n,int index);
void menu();
void menu2();
int main(){
	int choice,choice1,n,index=0,max_value=0,sonuc=0,sonuc1=0,count=0;	
	int x=0,y=0,orientation=1;
	int arr[500]={0};
	char str[100];
	char a;
	double std;
	double mean;
	double sonuc2=0.0;
	printf("Welcome to Homework 8, Please choose one of the parts to continue\n");
	while(1){
		menu();
		scanf("%d",&choice);
		if(choice==1){
			menu2();
			printf("Please make your choice: ");
			scanf("%d",&choice1);
			if(choice1==1){
				printf("Please enter how many items you want to fill: ");
				scanf("%d",&n);
				generate_hofstadters_sequence(arr, n);
			}
			else if(choice1==2){
				sonuc=find_max(arr,index,max_value);
				printf("%d\n",sonuc);
			}
			else if(choice1==3){
				sonuc1=sum_array(arr);
				printf("%d\n",sonuc1);
			}
			else if(choice1==4){
				generate_hofstadters_sequence(arr, n);
				std=std_array(arr,&mean,n,index);
				printf("%lf\n",mean);
			}
			else if(choice1==5){
				exit(1);
			}
			else{
				printf("There is no option.Enter again\n");
			}
		}
		else if(choice==3){
			scanf("%c",&a);//for preventing the taking the \n by fgets 
			printf("please enter a string\n");
			fgets(str,100,stdin);
			remove_duplicates(str);
			printf("%s",str);
		}
		else if(choice==4){
			exit(1);//EXIT
		}	
		else{
			printf("There is no option.Enter again\n");
		}
	}
	return 0;
}
void menu(){
	printf("--------------------------------------------------\n");
	printf("1)EXECUTE PART 1\n");
	printf("1)EXECUTE PART 2\n");
	printf("3)EXECUTE PART 3\n");
	printf("4)EXIT\n");
	printf("---------------------------------------------------\n");
}
void menu2(){
	printf("---------------\n");
	printf("1)FILL ARREY\n");
	printf("2)FIND BIGGEST NUMBER\n");
	printf("3)CALCULATE SUM\n");
	printf("4)CALCULATE STANDART DEVIATION\n");
	printf("5)EXIT\n");
	printf("---------------\n");
}
void generate_hofstadters_sequence(int *arr,int n){
		if(n>1){
			generate_hofstadters_sequence(arr,n-1);//we decrease the n value for counter 
			arr[n]=arr[n-arr[n-1]]+arr[n-arr[n-2]];//formula
			
		}
		else {
			arr[0]=1;
			arr[1]=1;
			
		}
}
int find_max(int arr[],int index,int max_value){
	if(index>=500){
		return max_value;
	}

	if(arr[index]>max_value){
		max_value=arr[index];
	}	
	find_max(arr,index+1,max_value);//we increase the index for counter and reach the whole value of arrey
	
}
int sum_array(int arr[]){
	if(arr[1]!=0){
		arr[1]+1;//for counter
		arr[1]=arr[0]+arr[1];//we find the sum 
		sum_array(arr+1);//we increase the address of arrey for reach the whole arrey 
	}
	else{
		return  (arr[0]-arr[1]);//sum of the whole arrey
	}
}
double std_array(int arr[],double *mean,int n,int index){
	if(index==0){
		*mean=*mean+arr[index];
		return sqrt((std_array(&arr[0],mean,n,index+1)+pow(*mean-arr[index],2))/(n-1));	
	}
	else if(index<n){
		*mean=*mean+arr[index];
		
		return std_array(arr,mean,n,index+1)+pow(*mean-arr[index],2);
	}
	else{
		*mean=*mean/(n);
		
	}
}
char* remove_duplicates(char* str){
	if(str[0]=='\0'){//controll the end of word
		return str;
	}
	if(str[0]==str[1]){
		int i=0;
		while(str[i]!='\0'){
			str[i]=str[i+1];//in the repeated values we assign the right value to the left to prevent the repetition
			i++;
		}
		remove_duplicates(str+1);//we increase the address of str for reaching the different elements of arrey
	}
		remove_duplicates(str+1);

	return str;
}
