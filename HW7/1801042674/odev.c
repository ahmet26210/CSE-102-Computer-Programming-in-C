#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void menu();
void list_genres(char genre[50][20]);
void list_platforms(char platforms[50][20]);
void list_name(float full[2000][7],char name[2000][100]);
void show_all(float full[2000][7],char name[2000][100],char genre[20][20],char platforms[20][20]);
void find_average(float full[2000][7]);
void find_popular(float full[2000][7],char name[2000][100]);
void genres_frequency(char genres[20][20],float full[2000][7]);
void platforms_frequency(char platforms[10][20],float full[2000][7]);
int main(){
	menu();
	return 0;
}
void menu(){
	int i,sayi=-1,flag=0,flag1=0,operation,j=0,k,l,m,length,sonuc,f=0,p=0;
	char char1[100],char2[100],char3[100],char4[100],char5[100],char6[100],char7[100],char8[100];
	char name[2000][100];
	char genre[20][20];
	char platforms[20][20];
	char arrey[2000][110];
	float full[2000][7];
	int a=0;
	FILE *fp;
	fp=fopen("Video_Games.txt","r");//read the file
	for(l=0;l<2000;l++){
		fgets(arrey[l],100,fp);//gets the information by line by
	}
	fclose(fp);
	
	for(l=0;l<2000;l++){//for deleting commas for sscanf 
		length=strlen(arrey[l]);
		for(m=0;m<length;m++){
			if(arrey[l][m]==','){
				arrey[l][m]=' ';
			}
		}
	}

	for(l=1;l<2000;l++){
		sscanf(arrey[l],"%s %s %s %s %s %s %s %s",char1,char2,char3,char4,char5,char6,char7,char8);//take the information by line by with sitring
		sscanf(char1,"%s",name[a]);//assign the name to the name arrey
		flag=0;//for controlling the values in the arrey
		for(i=0;i<12;i++){
			sonuc=strcmp(genre[i],char2);
			if(sonuc==0){//if these are the same it dont assign at arrey
				flag=2;
				sayi=i;
				break;
			}
			flag=1;//if these are not the same it assign the value to the genre arrey
		}
		if(flag==1){
			sscanf(char2,"%s",genre[f]);//assign the value to the arrey
			f++;//for arrey index
		}
		flag1=0;
		for(i=0;i<10;i++){
			sonuc=strcmp(platforms[i],char3);
			if(sonuc==0){
				flag1=2;
				sayi=i;
				break;
			}
			flag1=1;
		}
		if(flag1==1){
			sscanf(char3,"%s",platforms[p]);
			p++;
		}
		

		if(strcmp(genre[0],char2)==0){//if these are the same then this will assing the full arrey at genre partial
			full[a][1]=0.0;
		}
		else if(strcmp(genre[1],char2)==0){
			full[a][1]=1.0;
		}
		else if(strcmp(genre[2],char2)==0){
			full[a][1]=2.0;
		}
		else if(strcmp(genre[3],char2)==0){
			full[a][1]=3.0;
		}
		else if(strcmp(genre[4],char2)==0){
			full[a][1]=4.0;
		}
		else if(strcmp(genre[5],char2)==0){
			full[a][1]=5.0;
		}
		else if(strcmp(genre[6],char2)==0){
			full[a][1]=6.0;
		}
		else if(strcmp(genre[7],char2)==0){
			full[a][1]=7.0;
		}
		else if(strcmp(genre[8],char2)==0){
			full[a][1]=8.0;
		}
		else if(strcmp(genre[9],char2)==0){
			full[a][1]=9.0;
		}
		else if(strcmp(genre[10],char2)==0){
			full[a][1]=10.0;
		}
		else if(strcmp(genre[11],char2)==0){
			full[a][1]=11.0;
		}


		
		if(strcmp(platforms[0],char3)==0){//if these are the same then this will assing the full arrey at platform partial
			full[a][2]=0.0;
		}
		else if(strcmp(platforms[1],char3)==0){
			full[a][2]=1.0;
		}
		else if(strcmp(platforms[2],char3)==0){
			full[a][2]=2.0;
		}
		else if(strcmp(platforms[3],char3)==0){
			full[a][2]=3.0;
		}
		else if(strcmp(platforms[4],char3)==0){
			full[a][2]=4.0;
		}
		else if(strcmp(platforms[5],char3)==0){
			full[a][2]=5.0;
		}
		else if(strcmp(platforms[6],char3)==0){
			full[a][2]=6.0;
		}
		else if(strcmp(platforms[7],char3)==0){
			full[a][2]=7.0;
		}
		else if(strcmp(platforms[8],char3)==0){
			full[a][2]=8.0;
		}
		else if(strcmp(platforms[9],char3)==0){
			full[a][2]=9.0;
		}
		
		
		sscanf(char4,"%f",&full[a][3]);//assign the year value to the arrey
		sscanf(char5,"%f",&full[a][4]);//assign the na sales value to the arrey
		sscanf(char6,"%f",&full[a][5]);//assign the eu sales value to the arrey
		sscanf(char7,"%f",&full[a][6]);//assign the global sales value to the arrey
		sscanf(char8,"%f",&full[a][7]);//assign the user score value to the arrey
		a++;
	}
	
	while(1){
		printf(" 0:List of the Genres\n");
		printf(" 1:List of the Platforms\n");
		printf(" 2:List of the Games Through the Years\n");
		printf(" 3:All Informations of a Single Game\n");
		printf(" 4:Average of the User Scores\n");
		printf(" 5:Georographical Information of a Single Game\n");
		printf(" 6:Frequence of the Genres\n");
		printf(" 7:Frequence of the Platforms\n");
		printf(" 8:Exit\n");
		printf("\n");
		printf(" Please Select an Operations: ");
		scanf("%d",&operation);
		if(operation<0||operation>8){
			printf("TRY AGAIN\n");
			printf("\n");
		}
		else if(operation==0){
			list_genres(genre);
		}
		else if(operation==1){
			list_platforms(platforms);
		}
		else if(operation==2){
			list_name(full,name);			
		}
		else if(operation==3){
			show_all(full,name,genre,platforms);			
		}
		else if(operation==4){
			find_average(full);
		}
		else if(operation==5){
			find_popular(full,name);
		}
		else if(operation==6){
			genres_frequency(genre,full);
		}
		else if(operation==7){
			platforms_frequency(platforms,full);
		}
		else if(operation==8){
			exit(1);//exit
		}
	}

}

void list_genres(char genre[20][20]){//list the genre values
	for(int i=0;i<12;i++){
		printf("%s\n",genre[i]);		
	}

}
void list_platforms(char platforms[20][20]){//list the platform values
	int i=0;
	for(i;i<10;i++){
		printf("%s\n",platforms[i]);
	}
}
void list_name(float full[2000][7],char name[2000][100]){//list the name according to the year
	int y,year,choice,i,oldest=0,youngest=2100,flag=0;
	for(y=0;y<2000;y++){
		if(full[y][3]>oldest){//this find the max year
			oldest=full[y][3];
		}
		if(full[y][3]<youngest){//this find the min year
			youngest=full[y][3];
		}	
	}
	while(1){
		printf("Enter a year: \n");
		scanf("%d",&year);
		printf("Until (0) or Since (1) %d: ",year);
		scanf("%d",&choice);
		if(year==oldest&&choice==1||year==youngest&&choice==0){
			printf("Try Again\n");
		}
		else{
			flag++;
			for(i=0;i<2000;i++){
				if(choice==0){
					if(full[i][3]<year){
						printf("%s\n",name[i]);
					}
				}
				else if(choice==1){
					if(full[i][3]>year){
						printf("%s\n",name[i]);
					}
				}
			}
		}
		if(flag==1) break;//for exit the while 
	}
}
void show_all(float full[2000][7],char name[2000][100],char genre[20][20],char platforms[20][20]){//show all value according to the name
	int i=0,j=1,sayi=-1,flag=0,gen,plat,year;
	char value[15];
	while(1){
		printf("Please enter a name of the game :");
		scanf("%s",value);
		for(i;i<2000;i++){
			if(strcmp(name[i],value)==0){// it finds the name
				sayi=i;
				flag++;
				break;
			}		
		}
		if(sayi==-1)printf("Wrong name Enter again\n");
		else{
			gen=(int)full[i][1];//convert the float to the int for genre
			plat=(int)full[i][2];//for platform
			year=(int)full[i][3];//for year
			printf("%d\n",i);
			printf("Name: %s\n",name[i]);
			printf("Genre: %s\n",genre[gen]);
			printf("Platform: %s\n",platforms[plat]);
			printf("Year: %d\n",year);
			printf("Sales In Na: %f\n",full[i][4]);
			printf("Sales In Eu: %f\n",full[i][5]);
			if(full[i][6]==0){//for 0 value of the total sales
				printf("Total Sales: Not Avaible\n");
			}
			else{
				printf("Total Sales: %f\n",full[i][6]);
			}
			printf("User Score: %f\n",full[i][7]);
			printf("\n");
			
		}
		if(flag==1)break;//for exit the while
	}
}
void find_average(float full[2000][7]){//find the average of the user score
	int i;
	float sonuc,sum=0.0;

	for(i=0;i<1999;i++){
		sum+=full[i][7];
	}
	sonuc=sum/2000;
	printf("%4.6lf\n",sonuc);
}
void find_popular(float full[2000][7],char name[2000][100]){
	char value[15];
	int i,flag=0;
	int sayi=-1;
	while(1){
		printf("Please enter the name of the game: ");
		scanf("%s",value);
		for(i=0;i<2000;i++){
			if(strcmp(name[i],value)==0){//find the name 	
				sayi=i;
				flag++;
				break;
			}	
		}
		if(sayi==-1){
			printf("Wrong name Enter again\n");
		}
		else{
			if(full[i][4]>full[i][5]){
				printf("This game was more popular in North America\n");

			}
			else if(full[i][4]<full[i][5]){
				printf("This game was more popular in Europe\n");
			}
			else{
				printf("This game was equal popular in Europe and North America\n");
			}
			printf("\n\n");
		}
		if(flag==1)break;//for exit the while
	}
}
void genres_frequency(char genres[12][20],float full[2000][7]){
	int i,j,a1=0,a2=0,a3=0,a4=-1,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0,a11=0,a12=1;
	int sayi;
	for(i=0;i<2000;i++){
		sayi=(int)full[i][1];//convert the float to the integer for finding the genre index
		if(sayi==0){
			a1++;
		}
		else if(sayi==1){
			a2++;
		}
		else if(sayi==2){
			a3++;
		}
		else if(sayi==3){
			a4++;
		}
		else if(sayi==4){
			a5++;
		}
		else if(sayi==5){
			a6++;
		}
		else if(sayi==6){
			a7++;
		}
		else if(sayi==7){
			a8++;
		}
		else if(sayi==8){
			a9++;
		}
		else if(sayi==9){
			a10++;
		}
		else if(sayi==10){
			a11++;
		}
		else if(sayi==11){
			a12++;
		}
		
	}
	printf("%s %-10d\n",genres[0],a1);
	printf("%s %-10d\n",genres[1],a2);
	printf("%s %-10d\n",genres[2],a3);
	printf("%s %-10d\n",genres[3],a4);
	printf("%s %-10d\n",genres[4],a5);
	printf("%s %-10d\n",genres[5],a6);
	printf("%s %-10d\n",genres[6],a7);
	printf("%s %-10d\n",genres[7],a8);
	printf("%s %-10d\n",genres[8],a9);
	printf("%s %-10d\n",genres[9],a10);
	printf("%s %-10d\n",genres[10],a11);
	printf("%s %-10d\n",genres[11],a12);
	
}
void platforms_frequency(char platforms[10][20],float full[2000][7]){
	int i,j,a1=0,a2=0,a3=0,a4=-1,a5=0,a6=0,a7=1,a8=0,a9=0,a10=0;
	int sayi;
	for(i=0;i<2000;i++){
		sayi=(int)full[i][2];//convert the float to the integer for finding the genre index
		if(sayi==0){
			a1++;
		}
		else if(sayi==1){
			a2++;
		}
		else if(sayi==2){
			a3++;
		}
		else if(sayi==3){
			a4++;
		}
		else if(sayi==4){
			a5++;
		}
		else if(sayi==5){
			a6++;
		}
		else if(sayi==6){
			a7++;
		}
		else if(sayi==7){
			a8++;
		}
		else if(sayi==8){
			a9++;
		}
		else if(sayi==9){
			a10++;
		}
		
	}
	printf("%s %d\n",platforms[0],a1);
	printf("%s %d\n",platforms[1],a2);
	printf("%s %d\n",platforms[2],a3);
	printf("%s %d\n",platforms[3],a4);
	printf("%s %d\n",platforms[4],a5);
	printf("%s %d\n",platforms[5],a6);
	printf("%s %d\n",platforms[6],a7);
	printf("%s %d\n",platforms[7],a8);
	printf("%s %d\n",platforms[8],a9);
	printf("%s %d\n",platforms[9],a10);
}
