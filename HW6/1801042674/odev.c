#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define column 20
#define row 20
int find_words(char arrey[20][20],int row_user,int column_user,char word_user[20],int length_user);
int control_word(int k,int l,int word_size,int a,char arrey[20][20]);
int control_row_column(int word_size,int direction,int rows ,int colum);
void place_number(char word[10][20],char arrey[20][20],int a,int k,int l,int m,int word_size);
void print_number(char arrey[20][20],char word[10][20]);
char fill_arrey();
void change_word(char word_user[20],char word[10][20],int length);
int main(){
	char arrey1[100][100],ch,row_user;
	char word[10][20];
	char arrey[20][20];
	char word_user[15];
	int i=0,j=0,column_user,row_user1,p;
	int k,l,m,n,a,control,control1,rondom,control3;
	char temp;
	srand(time(NULL));//for rondom words or digits

	for(i=0;i<column;i++){//for controlling the empty column or row
		for(j=0;j<row;j++){
			arrey[i][j]='*';
		}
	}
	
	

	FILE *fp;
	fp=fopen("words.txt","r");//take the rondom words from words.txt
	for(i=0;i<96;i++){
		fgets(arrey1[i],20,fp);
	}
	for(i=0;i<10;i++){
		rondom=rand()%99;
		strcpy(word[i],arrey1[rondom]);
	}

	fclose(fp);
	
	j=0;
	i=0;
	m=0;
	while(i<10){
		k=rand()%19;//for random column
		l=rand()%19;//for rondom row
	
		a=rand()%8;//for rondom direction
		while(a==0){
			a=rand()%8;//for rondom direction 1-8
		}
		control=control_row_column(strlen(word[m])-2,a,k,l);//for controlling the empty row or column
		control1=control_word(k,l,strlen(word[m])-2,a,arrey);//for controlling the prevent the exceed the row or column
		if(control==1&&control1==1){ 
			place_number(word,arrey,a,k,l,m,strlen(word[m])-2);//for placing the number to the arrey
			i++;
			m++;
		}
	}
	i=0;
	j=0;
	for(i=0;i<column;i++){
		for(j=0;j<row;j++){//fill the arrey with rondom letters
			if(arrey[i][j]=='*'){
				temp=fill_arrey();
				arrey[i][j]=temp;
			}
		}
	}
	print_number(arrey,word);
	i=0;
	while(i<10){//for ten words
		printf("Please enter the coordinate and word!\n");
		printf("Please enter the column: \n");
		scanf(" %d",&column_user);
		printf("Enter the row: \n");
		scanf(" %c",&row_user);
		row_user-=17;
		row_user1=row_user-'0';//for converting the character to integer
		printf("please enter the word:");
		scanf("%s",word_user);
	if((word_user[0]=='e')&&(word_user[1]=='x')&&(word_user[2]=='i')&&(word_user[3]=='t')){
	exit(1);//for exit
}
		control3=find_words(arrey,row_user1,column_user,word_user,strlen(word_user));//for converting the letter to the uppercase letter
		if(control3==0){//for wrong words
			printf("Try again\n");
		}
		
		else if(control3==1){
			i++;
			change_word(word_user,word,strlen(word_user));//for converting the words to the uppercase word
			print_number(arrey,word);
		}
	}
}
int control_word(int k,int l,int word_size,int a,char arrey[20][20]){
	while(1){
		int direction,i;
		direction=a;
		if(direction==1){//kuzey
			for(i=0;i<word_size;i++){
				if(arrey[k][l]=='*'){
					k--;
				}			
				else{
					return 0;
				}	
			}
				return 1;
		}
		
		if(direction==2){//güney
			for(i=0;i<word_size;i++){
				if(arrey[k][l]=='*'){
					k++;
				}			
				else{
					return 0;
				}	
			}
				return 1;
		}

		if(direction==3){//sağa
			for(i=0;i<word_size;i++){
				if(arrey[k][l]=='*'){
					l++;
				}			
				else{
					return 0;
				}	
			}
				return 1;
		}

		if(direction==4){//sola
			for(i=0;i<word_size;i++){
				if(arrey[k][l]=='*'){
					l--;
				}			
				else{
					return 0;
				}	
			}
				return 1;
		}

		if(direction==5){//sağ üst
			for(i=0;i<word_size;i++){
				if(arrey[k][l]=='*'){
					k--;
					l++;
				}			
				else{
					return 0;
				}	
			}
				return 1;
		}

		if(direction==6){//sol alt
			for(i=0;i<word_size;i++){
				if(arrey[k][l]=='*'){
					k++;
					l--;			
				}			
				else{
					return 0;
				}	
			}
				return 1;
		}

		if(direction==7){//sol üst
			for(i=0;i<word_size;i++){
				if(arrey[k][l]=='*'){
					k--;
					l--;
				}			
				else{
					return 0;
				}	
			}
				return 1;
		}

		if(direction==8){//sağ alt
			for(i=0;i<word_size;i++){
				if(arrey[k][l]=='*'){
					k++;
					l++;
				}			
				else{
					return 0;
				}	
			}
				return 1;
		}

	}

}
int control_row_column(int word_size,int direction,int rows ,int colum){
	while(1){
		if(direction==1){//kuzey
			if(rows-word_size<=0){
				return 0;
			}
			else{
			      return 1;			
			}
		}
		
		if(direction==2){//güney
			if(rows+word_size>=row){
				return 0;
			}
			else{
			      return 1;			
			}
		}
	
		if(direction==3){//sağ
			if(colum+word_size>=column){
				return 0;
			}
			else{
			      return 1;			
			}
		}
	
		if(direction==4){//sola
			if(colum-word_size<=0){
				return 0;
			}
			
			else{
			      return 1;			
			}
		}
	
		if(direction==5){//sağ üst
			if(rows-word_size<=0){
				return 0;
			}
			else if(colum+word_size>=column){
				return 0;
			}
			
			else{
			      return 1;			
			}
		}
	
		if(direction==6){//sol alt
			if(rows+word_size>=row){
				return 0;
			}
			else if(colum-word_size<=0){
				return 0;
			}
			
			else{
			      return 1;			
			}
		}
	
		if(direction==7){//sol üst
			if(rows-word_size<=0){
				return 0;
			}
			else if(colum-word_size<=0){
				return 0;
			}
			
			else{
			      return 1;			
			}
		}
		
		if(direction==8){//sağ alt
			if(rows+word_size>=row){
				return 0;
			}
			else if(colum+word_size>=column){
				return 0;
			}
			
			else{
			      return 1;			
			}
		}
	}
}
void place_number(char word[10][20],char arrey[20][20],int a,int k,int l,int m,int word_size){
	int i,n=0;
	if(a==1){
		for(i=0;i<word_size;i++){//kuzey
			arrey[k][l]=word[m][n];
			k--;
			n++;
			
		}
	}
	else if(a==2){
		for(i=0;i<word_size;i++){//güney
			arrey[k][l]=word[m][n];
			k++;
			n++;
		}
	}


	else if(a==3){
		for(i=0;i<word_size;i++){//sağ
			arrey[k][l]=word[m][n];
			l++;
			n++;
		}
	}
	else if(a==4){
		for(i=0;i<word_size;i++){//sola
			arrey[k][l]=word[m][n];
			l--;
			n++;
		}
	}


	else if(a==5){
		for(i=0;i<word_size;i++){//sağ üst
			arrey[k][l]=word[m][n];
			k--;
			l++;
			n++;
		}
	}
	else if(a==6){
		for(i=0;i<word_size;i++){//sol alt
			arrey[k][l]=word[m][n];
			k++;
			l--;
			n++;
		}
	}


	else if(a==7){
		for(i=0;i<word_size;i++){//sol üst
			arrey[k][l]=word[m][n];
			k--;
			l--;
			n++;
		}
	}
	else if(a==8){
		for(i=0;i<word_size;i++){//sağ alt
			arrey[k][l]=word[m][n];
			k++;
			l++;
			n++;
		}
	}
}
int find_words(char arrey[20][20],int row_user,int column_user,char word_user[20],int length_user){
	int flag=0,i,j;
	int a=0,b;
	i=row_user;
	j=column_user;
	for(b=0;b<length_user;b++){//kuzey
		if(arrey[i][j]==word_user[a]){
			flag++;
		}
		a++;
		i--;
	}
	i=row_user;
	if(length_user==flag){
		for(b=0;b<length_user;b++){
			arrey[i][j]=arrey[i][j]-32;
			i--;
		}
		return 1;
	}
	
	flag=0;
	a=0;
	i=row_user;
	j=column_user;
	for(b=0;b<length_user;b++){//güney
		if(arrey[i][j]==word_user[a]){
			flag++;
		}
		a++;
		i++;
	}
	i=row_user;
	if(length_user==flag){
		for(b=0;b<length_user;b++){
			arrey[i][j]=arrey[i][j]-32;
			i++;
		}
		return 1;
	}

	flag=0;
	a=0;
	i=row_user;
	j=column_user;
	for(b=0;b<length_user;b++){//sağ
		if(arrey[i][j]==word_user[a]){
			flag++;
		}
		a++;
		j++;
	}
	j=column_user;
	if(length_user==flag){
		for(b=0;b<length_user;b++){
			arrey[i][j]=arrey[i][j]-32;
			j++;
		}
		return 1;
	}

	flag=0;
	a=0;
	i=row_user;
	j=column_user;
	for(b=0;b<length_user;b++){//sola
		if(arrey[i][j]==word_user[a]){
			flag++;
		}
		a++;
		j--;
	}
	j=column_user;
	if(length_user==flag){
		for(b=0;b<length_user;b++){
			arrey[i][j]=arrey[i][j]-32;
			j--;
		}
		return 1;
	}

	flag=0;
	a=0;
	i=row_user;
	j=column_user;
	for(b=0;b<length_user;b++){//sağ üst
		if(arrey[i][j]==word_user[a]){
			flag++;
		}
		a++;
		i--;
		j++;
	}
	i=row_user;
	j=column_user;
	if(length_user==flag){
		for(b=0;b<length_user;b++){
			arrey[i][j]=arrey[i][j]-32;
			i--;
			j++;
		}
		return 1;
	}

	flag=0;
	a=0;
	i=row_user;
	j=column_user;
	for(b=0;b<length_user;b++){//sol alt
		if(arrey[i][j]==word_user[a]){
			flag++;
		}
		a++;
		i++;
		j--;
	}
	i=row_user;
	j=column_user;
	if(length_user==flag){
		for(b=0;b<length_user;b++){
			arrey[i][j]=arrey[i][j]-32;
			i++;
			j--;
		}
		return 1;
	}

	flag=0;
	a=0;
	i=row_user;
	j=column_user;
	for(b=0;b<length_user;b++){//sol üst
		if(arrey[i][j]==word_user[a]){
			flag++;
		}
		a++;
		i--;
		j--;
	}
	i=row_user;
	j=column_user;
	if(length_user==flag){
		for(b=0;b<length_user;b++){
			arrey[i][j]=arrey[i][j]-32;
			i--;
			j--;
		}
		return 1;
	}

	flag=0;
	a=0;
	i=row_user;
	j=column_user;
	for(b=0;b<length_user;b++){//sağ alt
		if(arrey[i][j]==word_user[a]){
			flag++;
		}
		a++;
		i++;
		j++;
	}
	i=row_user;
	j=column_user;
	if(length_user==flag){
		for(b=0;b<length_user;b++){
			arrey[i][j]=arrey[i][j]-32;
			i++;
			j++;
		}
		return 1;
	}
	return 0;
}

char fill_arrey(){//fill arrey with rondom letter
	int a=rand()%123;
	while(a<97||a>122)
	a=rand()%123;
	return a;

}
void change_word(char word_user[20],char word[10][20],int length){//convert the words to the uppercase words
	int a,j;
	int flag=1;
	for(int i=0;i<10;i++){
		a=0;
		flag=0;
		for(j=0;j<length;j++){
			if(word[i][j]==word_user[a]){
				flag++;
			}
			a++;
		}

		if(length==flag){
			j=0;
			for(int b=0;b<length;b++){
				word[i][j]=word[i][j]-32;
				j++;
			}
			break;
		}
	}
}
void print_number(char arrey[20][20],char word[10][20]){
	int a;
	int k=0;
	char l='A';
	printf("\t");
	printf("PLEASE WRİTE 'exit' İNSTEAD OF SCANF WORD,SO YOU CAN EXİT EASİLY.\n");
	printf("\t");		printf("=================================================================\n");
	printf("\t");
	for(int z=0;z<4;z++){
		printf(" ");
	}
	
	while(k<10){
		printf("%d",k);
		k++;	
		printf(" ");
		printf(" ");
	}
	while(k<20){
		printf("%d",k);
		k++;	
		printf(" ");
		
	}
	printf("\n");
	for(int i=0;i<20;i++){
		printf("\t");
		printf("%c",l);
		printf(" ");
		l++;
		for(int j=0;j<20;j++){
			printf(" ");
			printf(" ");
			if(arrey[i][j]!='*'){
				printf("%c",arrey[i][j]);
				
			}
			else{
				printf(".");
			}
		}
		printf("\n");
	}
	for(int j=0;j<10;j++){
		printf("%s",word[j]);
	}
}

			if(arrey[k][m]==','&&sayi==0){
				for(temp;0<m-temp;temp++){
					name[k]=arrey[k][temp];
				}
				temp=m;
			}
			else if(arrey[k][m]==','&&sayi==1){
				for(temp;0<m-temp;temp++){
					name[k]=arrey[k][temp];
				}
				temp=m;

			}
