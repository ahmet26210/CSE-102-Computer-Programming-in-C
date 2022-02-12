#include<stdio.h>
#include<math.h>
#include<stdlib.h>
char decrypt_numbers(int number);
void deep_decrypt_and_print(char* file_path);
void refresh_position(int *X, int *Y, double *D , double *R);
void decrypt_and_print(char* file_path);
void menu();
void track_machine();
void encrypt_messages(char* file_path);
int decrypt_chars(char messages);
int main(){
	int choice;
	while(1){
		menu();
		scanf("%d",&choice);
		if(choice==1){
		decrypt_and_print("encrypted_p1.img");
		}

		else if(choice==2){
		deep_decrypt_and_print("encrypted_p2.img");
		}
		else if(choice==3){
		track_machine();
		}
		else if(choice==4){
		encrypt_messages("decrypted_p4.img");
		}
		else if(choice==5){
			break;		
		}
		else{
			printf("Unsupported operation");
		}
	}
	return 0;
	
}
void menu(){
	printf("1-) Decrypt_and_print encrypted_p1.img\n");
	printf("2-) Decrypt_and_print encrypted_p2.img\n");
	printf("3-) Switch on the tracking machine\n");
	printf("4-) Encrypt the message\n");
	printf("5-) Switch off\n\n");
	printf("Please make your choice");


}
void decrypt_and_print(char* file_path){
	
	char y,number;
	int x,number1;	
	FILE *fp;
	fp=fopen(file_path,"r");
	while(!feof(fp)){
		fscanf(fp,"%c",&number);
		number1=number-'0';
		y=decrypt_numbers(number1);
		printf("%c",y);
		
	}	

	
	
}
char decrypt_numbers(int number){
	
	switch(number){
		case 0:
			return ' ';
			break;	
		case 1:
			
			return '-';
			break;
		case 2: 
			return '_';
			break;
		case 3:
			return '|';
			break;
		case 4: 
			return '/';
			break;
		case 5:
			return '\\';
			break;
		case 6:
			return 'O';
			break;
		
		default:
			return '\n';
			break;
		
	}

}

void deep_decrypt_and_print(char* file_path){
	char y,number,number2,number3,number4,number5,number6,number7,number8,number9,a,b,c;
	int x,number1,i,j,sum=0;	
	FILE *fp;
	fp=fopen(file_path,"r");
	fscanf(fp,"%c",&number);
	fscanf(fp,"%c",&number2);
	fscanf(fp,"%c",&number3);
	number7=number-'0';
	number8=number2-'0';
	number9=number3-'0';
	sum=number7+number8+number9;	
	number1=sum%7;	
	y=decrypt_numbers(number1);
	printf("%c",y);
	
	while(!feof(fp)){
		if(number3=='\n'){
			number3='0';
		}
		else if(number2=='\n'){
			number2='0';
		}
		else if(number=='\n'){
			number='0';
		}
		else{
			number=number2;
			number2=number3;
			fscanf(fp,"%c",&number3);
			number4=number-'0';
			number5=number2-'0';
			number6=number3-'0';
			sum=number4+number5+number6;	
			number1=sum%7;	
			y=decrypt_numbers(number1);
			printf("%c",y);
			
			
		}	
	}
}
void track_machine(){
	int a, b, Ya =1, Yb =1, Za =6, Zb =6;
	char choice;
	char Yc, Zc;
	double displacement=0.0,distance;
	distance=6.0*sqrt(2);
	while(1) {
	for(a=1; a<=11; a++) {
			for(b=1; b<=11; b++){
				if(a==Ya&&b==Yb){
					printf("E");
				}	
				else if(a==Za&&b==Zb){
					printf("O");
				}
				else{
					printf(".");
				}
				printf("\t");
			}
	printf("\n");	
	}
	printf("Enimies X position:%d ",Ya);
	printf("Y position:%d ",Yb);
	printf("Displacement:%lf ",displacement);
	printf("Distance the our camp:%lf ",distance);

	printf("Command waiting... ");
	scanf(" %c", &choice);

			 if(choice=='E' || choice=='e')
			{
				break;	
			}		
			else if(choice=='R' || choice=='r')
			{
				refresh_position(&Ya, &Yb, &distance, &displacement);
			if(Ya==6 && Yb==6)
						refresh_position(&Ya, &Yb, &distance, &displacement);
	
	
	}
	}	
	
}
void refresh_position(int *X, int *Y, double *D , double *R){
int displacement1,displacement2,distance1,distance2;
int Za =6, Zb =6;
int Ba,Bb;
Ba=*X;
Bb=*Y;
*X=rand()%12;
*Y=rand()%12;
if(Ba>Za){
		distance1=Ba-Za;
		distance2=Bb-Zb;
	}
	else{
		distance1=Za-Ba;
		distance2=Zb-Bb;
	}
			*D=sqrt(distance2*distance2+distance1*distance1);
	if(Ba>*X){
		displacement1=Ba-*X;
		displacement2=Bb-*Y;
	}
	else{
		displacement1=*X-Ba;
		displacement2=*Y-Bb;
	}	  *R=sqrt(displacement2*displacement2+displacement1*displacement1);

}

int decrypt_chars(char messages){
	
	switch(messages){
		case ' ':
			return 0;
			break;	
		case '-':
			
			return 1;
			break;
		case '_': 
			return 2;
			break;
		case '|':
			return 3;
			break;
		case '/': 
			return 4;
			break;
		case '\\':
			return 5;
			break;
		
		
	}

}


void encrypt_messages(char* file_path){
	int sum=0,number,number5=0,count=0;
	char char1,char2,char3,number4=0,number1;	
	FILE *fp;
	FILE *tp;
	if((fp=fopen(file_path, "r"))==NULL)
	{
		printf("reading error!!\n");
		//exit(1); 	
	}
		if((tp=fopen("encrypted_p4.img", "w"))==NULL)
	{
		printf("error!!\n");
		//exit(1);
	}
	
	fscanf(fp,"%c",&char1);
	fscanf(fp,"%c",&char2);
	while(!feof(fp)){
		fscanf(fp,"%c",&char3);
		if(char3!='\n'){
			sum=decrypt_chars(char1)+decrypt_chars(char2)+decrypt_chars(char3);
			number=sum%7;
			number1=number+'0';	
			printf("%c",number1);
			char1=char2;
			char2=char3;
		}
		else{
			char3=' ';
			sum=decrypt_chars(char1)+decrypt_chars(char2)+decrypt_chars(char3);
			number=sum%7;
			number1=number+'0';
			count++;	
			printf("%c",number1);
			if(count==5){
				printf("\n");
				printf("\n");
				printf("\n");

			}
			else{
				printf("\n");
				fscanf(fp,"%c",&char1);
				fscanf(fp,"%c",&char2);
			}
			
		}
		
	}	
	fclose(fp);
	fclose(tp);
}
