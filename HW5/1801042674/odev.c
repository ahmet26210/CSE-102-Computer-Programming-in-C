#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define only_title_one 1
#define only_title_zero 0
#define TRUE 1
#define FALSE 0
void append_file(char* file_path,char c);
void read_file(char *file_path);
void menu();
void read_magic_numbers(char buffer_magic[10],char buffer_news[500]);
double f_func(int x);
double g_func(double f(int x),int a);
void read_news(char buffer[500], char file_path[10], int is_Only_Title){//Reading news
	char ch;
	int i;
	FILE *fp;
	if((fp=fopen(file_path, "r"))==NULL)
	{
		printf("reading error!!\n");
		//exit(0); 	
	}
	if(is_Only_Title==only_title_one){//This read only title
		while(!feof(fp)){
			fscanf(fp,"%c",&ch);
			if(ch=='\n'){//for reading only title
				break;
			}
			buffer[i]=ch;
			i++;
			
		}
		buffer[i]='\0';//for char arrey
	}
	else if(is_Only_Title==only_title_zero){//This read the whole news
		while(!feof(fp)){
			fscanf(fp,"%c",&ch);
			if(ch=='\n'){
				 printf("\n");
			}
			else{
				buffer[i]=ch;
				i++;
			}
		}
		buffer[i]='\0';//for char arrey
	}
	
	fclose(fp);
			
}

void append_file(char* file_path,char c){//This write the news readed before
	FILE *fp;
	char ch;
	if((fp=fopen(file_path, "a+"))==NULL){//for reading and writing
		printf("error!!\n");
		//exit(1);
	}
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		if(ch!=c){//checks if there is same news in the file 
			fprintf(fp,"%c",c);
			fprintf(fp,"\n");
			break;	
		}
		
	}	
	fclose(fp);	
}

void read_file(char *file_path){//This write the readed news for b part
	FILE *fp;
	char ch;
	if((fp=fopen(file_path,"r"))==NULL)
	{
		printf("reading error!!\n");
		//exit(1);
	}	
	while(!feof(fp)){//checks readed news in the file if there is it writes
		fscanf(fp,"%c",&ch);
		if(ch!='\n'){
			printf("%c. news is readed",ch);
		}
		else{
			printf("\n");
		}
	}

}

void menu(){
	char command,command2,read_new[500],*file_path,*file_path1,buffer_magic[10],n;
	int news,number1=0,number2=0,number3=0,number4=0,command3,checking=TRUE;
	file_path="readed_news_id.txt";
	printf("********Daily Press********\n");
	printf("Today's news are listed for you :\n");
	printf("Title of 1.news: ");
	file_path1="news/1.txt";
	read_news(read_new,file_path1,only_title_one);
	puts(read_new);//read the news at the terminal
	printf("Title of 2.news: ");
	file_path1="news/2.txt";
	read_news(read_new,file_path1,only_title_one);
	puts(read_new);
	printf("Title of 3.news: ");
	file_path1="news/3.txt";
	read_news(read_new,file_path1,only_title_one);
	puts(read_new);
	printf("Title of 4.news: ");
	file_path1="news/4.txt";
	read_news(read_new,file_path1,only_title_one);
	puts(read_new);


	while(checking==TRUE){//checking continuing or exiting the program
		printf("\n\n");
		printf("What do you want to do?\n");
		printf("a.Read a new\n");
		printf("b.List the readed news\n");
		printf("c.Get decrypted information from the news\n");
		scanf(" %c",&command);
		if(command=='a'||command=='A'){
			printf("Which news do you want to read? :\n");		
			scanf(" %d",&news);
			switch(news){
				case 1:
					if(number1==0){
						file_path1="news/1.txt";
				read_news(read_new,file_path1,only_title_zero);//reading new
append_file(file_path,'1');//add the readed news to file
puts(read_new);
number1=1;//this check the news for reading once

				}
					else{	
						printf("this new is readed. Do you want ot read again? Yes(y)/No(n): \n");
						scanf(" %c",&command2);
						if(command2=='n'){
	checking=FALSE;//for exiting the program
}

				} 
				break;
				case 2:
					 if(number2==0){
						file_path1="news/2.txt";
				read_news(read_new,file_path1,only_title_zero);
append_file(file_path,'2');
puts(read_new);
number2=1;

					} 
					else{	
						printf("this new is readed. Do you want ot read again? Yes(y)/No(n): \n");
						scanf(" %c",&command2);
						if(command2=='n') checking=FALSE; 
	
				} 
				break;
				case 3:
			if(number3==0){
				file_path1="news/3.txt";
				read_news(read_new,file_path1,only_title_zero);
append_file(file_path,'3');
puts(read_new);
number3=1;

			} 
			else{	
				printf("this new is readed. Do you want ot read again? Yes(y)/No(n): \n");
				scanf(" %c",&command2);
				if(command2=='n') checking=FALSE;
					
			}  
			break;
				case 4:
			if(number4==0){
				file_path1="news/4.txt";
				read_news(read_new,file_path1,only_title_zero);
append_file(file_path,'4');
puts(read_new);
number4=1;

			}
			else{	
				printf("this new is readed. Do you want ot read again? Yes(y)/No(n): \n");
				scanf(" %c",&command2);
				if(command2=='n') checking=FALSE;
					
			}  
			break;
			default:
			 printf("There is no news number like this\n");
			break;
		}
			
		}
		else if(command=='b'){
			read_file(file_path);
			printf("Do you want to contiune? Yes(y)/No(n):\n");
			scanf(" %c",&command2);
			if(command2=='n'){
				break;
			}
		}

		else if(command=='c'){
			printf("which news would you like to decrypt? :");
			scanf(" %d",&command3);
			if(command3==1){
				file_path1="news/1.txt";
				read_news(read_new,file_path1,only_title_one);//for title
				puts(read_new);
				  	read_news(read_new,file_path1,only_title_zero);//for whole part of news
				puts(read_new);
				
	read_magic_numbers(file_path1,read_new);//for finding the magic numbers
				
				
			}
			else if(command3==2){
				file_path1="news/2.txt";
				read_news(read_new,file_path1,only_title_one);
				puts(read_new);
				read_news(read_new,file_path1,only_title_zero);
				puts(read_new);

					read_magic_numbers(file_path1,read_new);
				
				
			}
			else if(command3==3){
				file_path1="news/3.txt";
				read_news(read_new,file_path1,only_title_one);
				puts(read_new);
				read_news(read_new,file_path1,only_title_zero);
				puts(read_new);
				
				read_magic_numbers(file_path1,read_new);
				
				
			}
			else if(command3==4){
				file_path1="news/4.txt";
				read_news(read_new,file_path1,only_title_one);
				puts(read_new);;
				read_news(read_new,file_path1,only_title_zero);
				puts(read_new);
				
		read_magic_numbers(file_path1,read_new);
				
			}
			
		}
		
		else{
			printf("Wrong command\n");
		}
	}
}

void read_magic_numbers(char buffer_magic[10],char buffer_news[500]){
	int i=0,j=0,x=0;
	double sonuc1=0,sum=0,sonuc=0;
	char ch;
	FILE *fp;
	if((fp=fopen(buffer_magic,"r"))==NULL)
	{
		printf("reading error!!\n");
		//exit(0); 	
	}
	while(!feof(fp)){//read whole news
		fscanf(fp,"%c",&ch);
		if(ch=='\n'){
			 printf("\n");
		}
		else{
			buffer_news[i]=ch;
			i++;
		}
	}
	buffer_news[i]='\0';
	i=0;
	while(buffer_news[i]!='\0'){//for finding all number
		if(buffer_news[i]=='#'){//for finding magic numbers
			x=buffer_news[i+1]-'0';//find magic number at turn the integer
			sonuc=g_func(f_func,x);
			sum+=sonuc;
		}
		i++;
	}
	if(buffer_magic=="news/1.txt"){
		printf("the number of test performed= ");
		printf("%lf\n",sum);
	}
	else if(buffer_magic=="news/2.txt"){
		printf("number of sick people= ");
		printf("%lf\n",sum);
	}
	else if(buffer_magic=="news/3.txt"){
		printf("the number of deaths people= ");
		printf("%lf\n",sum);
	}
	else if(buffer_magic=="news/4.txt"){
		printf("expected number of sick people= ");	
		printf("%lf\n",sum);
	}
	
	fclose(fp);
	
}
double f_func(int x){
	double sonuc=0;
	sonuc=(x*x*x)-(x*x)+2;
	return sonuc;
}
double g_func(double f(int x),int a){
	double sonuc1=0;
	double sonuc2=0;
	sonuc2=f(a);
	sonuc1=sonuc2*sonuc2;//for finding a*a
	return sonuc1;
	
}

int main(){
	setlocale(LC_ALL,"Turkish");
	menu();
	return 0;
}
