#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	char data;
	int freq;
	struct tree *left;
	struct tree *right;
}tree;
void huffmantree(tree **minheap,int sayac);
void findbinary(tree *minnode,int arr[],int top,char arrey[],int arrey1[],char arrey2[50][20]);
void printarr(int arr[],int top);
void rawfile(char *file_name,char *file_name1,char *file_name2,int arr[100],char arrey[100],int arrey1[100],char arrey2[50][20]);
int ischar(tree *minnode);
int main(){
	char ch;
	char *arrey;
	int *arrey1;
	int sayac=0;
	int control=1;
	int i=1,k,j;
	int sayac1=0;
	arrey1=(int*)malloc(2*sizeof(int));
	if(arrey1==NULL){
		printf("yer açılamadı");
	}
	arrey=(char*)malloc(2*sizeof(char));
	if(arrey==NULL){
		printf("yer açılamadı");
	}
	arrey1[0]=0;//for starting arrey[1]
	arrey[0]='x';
	FILE *fp;
	fp=fopen("reference.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		control=1;
		for(k=0;k<i;k++){//to increase the frequency of the letters readed from the file
			if(arrey[k]==ch){
				control=0;	
				arrey1[k]=arrey1[k]+1;//frequency				
				break;
			}
		}
		if(control==1){//if it has not been readed befero we insert char arrey readed new
			sayac++;
			arrey=(char*)realloc(arrey,(sayac+2)*sizeof(char));
			arrey1=(int*)realloc(arrey1,(sayac+2)*sizeof(int));
			arrey[i]=ch;
			arrey1[i]=1;//frequency
			i++;
		}		
	}
	fclose(fp);
	i=0;
	j=1;
	tree **array;//creat arrey for trees the reason why it is 2 dimensional is to add new node easily to minheap arrey
	array=(tree**)malloc(sayac*sizeof(tree*));
	while(i<=sayac){//create minheap arrey all tree nodes
		tree *newnode=(tree*)malloc(sizeof(tree));
		newnode->data=arrey[j];
		newnode->freq=arrey1[j];
		newnode->left=NULL;
		newnode->right=NULL;
		array[i]=newnode;
		i++;
		j++;
	}
	huffmantree(array,sayac);
	free(arrey);
	free(arrey1);
	return 0;
}
void huffmantree(tree **minheap,int sayac){
	int i=0,j=0;
	int sayac1=0;
	int top=0;
	char arrey2[50][20];
	int arr[100];
	int arrey1[100];
	char arrey[100];
	char *file_name="message.txt";
	char *file_name1="decoded.txt";
	char *file_name2="encoded.dat";
	int temp;
	int max;
	int min1,min2,min3,min4;
	char temp1;
	for(i=0;i<sayac;i++){//sorting from small frequency to large frequency
		for(j=i+1;j<sayac;j++){
			if(minheap[i]->freq>minheap[j]->freq){
				temp=minheap[i]->freq;
				temp1=minheap[i]->data;
				minheap[i]->freq=minheap[j]->freq;
				minheap[i]->data=minheap[j]->data;
				minheap[j]->freq=temp;
				minheap[j]->data=temp1;
			}
		}
	}
	i=0;
	min1=999;
	min2=999;
	min3=10;
	min4=10;
	max=minheap[i]->freq;
	for(j=0;j<sayac;j++){
		if(minheap[j]->freq>max){
			max=minheap[j]->freq;
		}
	}
	j=0;
	while(j<sayac-1){
		tree *nodez=(tree*)malloc(sizeof(tree));
		min1=999;
		min2=999;
		min3=999;
		min4=999;
		for(i=0;i<=sayac;i++){
			if(minheap[i]->freq<=min2 && minheap[i]->freq>0){
				if(min1>min2){//find two min frequency tree nodes
					min2=min2;
					min4=min4;
				}
				else{
					min2=min1;
					min4=min3;
				}
				min1=minheap[i]->freq;
				min3=i;
			}
			else if(minheap[i]->freq<min1 && minheap[i]->freq!=min1 && minheap[i]->freq>0)			{
				min1=minheap[i]->freq;
				min3=i;
			}
		}
		if(minheap[min3]->freq>=minheap[min4]->freq){//create a new tree node and insert two min frequency nodes to the left and right then insert the new tree node to the minheap arrey again
			nodez->right=minheap[min3];
			nodez->left=minheap[min4];
		}
		else{
			nodez->right=minheap[min4];
			nodez->left=minheap[min3];
		}
		nodez->freq=minheap[min4]->freq+minheap[min3]->freq;
		minheap[min3]=nodez;//insert new node to the minheap arrey
		minheap[min4]->freq=0;
		j++;
	}	 
	findbinary(minheap[sayac-1],arr,top,arrey,arrey1,arrey2);
	rawfile(file_name,file_name1,file_name2,arr,arrey,arrey1,arrey2);
}
void findbinary(tree *minnode,int arr[],int top,char arrey[],int arrey1[],char arrey2[50][20]){//when we reach all nodes in tree and go right we add 1 to arrey and go left add 0 to the arrey
	static int i=0;
	if(minnode->left){
		arr[top]=0;
		findbinary(minnode->left,arr,top+1,arrey,arrey1,arrey2);
	}
	if(minnode->right){
		arr[top]=1;
		findbinary(minnode->right,arr,top+1,arrey,arrey1,arrey2);
	}
	if(ischar(minnode)){
		arrey[i]=minnode->data;
		arrey1[i]=top;
		for(int k=0;k<top;k++){
			arrey2[i][k]=arr[k]+'\0';
		}
		i++;
	}
}
int ischar(tree *minnode){//controlling the reach char in arrey
	return  !(minnode->left) && !(minnode->right);	
}
void rawfile(char *file_name,char *file_name1,char *file_name2,int arr[100],char arrey[100],int arrey1[100],char arrey2[50][20]){
	int i=0,top=0,number4;
	char ch;
	char cha;
	char ch5,ch6;
	int size,size1;
	int k=0,t;
	char ch1=' ';
	char arrs[4];
	int arrey5[20],arrey6[20];
	int arrt[11];
	int number,number2;
	int number3=0;
	int f=0;
	FILE *message,*decoded,*encoded;
	message=fopen(file_name,"r");
	decoded=fopen(file_name1,"w");
	encoded=fopen(file_name2,"wb");
	while(!feof(message)){
		fscanf(message,"%c",&ch);
		for(i=0;i<100;i++){
			if(arrey[i]==ch){
				top=arrey1[i];
				arrey5[f]=top;
				number=i;
				arrey6[f]=i;
				f++;
				break;
			}
		}
		for(k=0;k<top;k++){//we write the encrypted char to the binary file
			number2=arrey2[i][k]-'\0';
			fwrite(&number2,sizeof(number2),1,encoded);	
		}
		number3+=top;	
	}
	fclose(message);
	fclose(encoded);
	t=0;
	f=0;
	encoded=fopen(file_name2,"rb");
	for(i=0;i<number3;i++){
		if(t==arrey5[f]){
			cha=arrey[arrey6[f]];
			fputc(cha,decoded);
			t=0;
			f++;
		}
		fread(arrs,sizeof(4),1,encoded);
		number4=arrs[0]-'\0';
		if(number4==0){
			arrt[t]=0;
		}
		else{
			arrt[t]=1;
		}
		t++;	
	}
	fclose(encoded);
	fclose(decoded);
	number=0;
	number2=0;
	//find the file size between encoded and decoded files
	encoded=fopen(file_name2,"rb");
	decoded=fopen(file_name1,"r");
	while(!feof(decoded)){
		fscanf(decoded,"%c",&ch5);
		number++;
	}
	while(!feof(encoded)){
		fread(arrs,sizeof(4),1,encoded);
		number2=number2+4;
	}
	number4=number2-number;
	printf("THE SİZE DİFFERENCE BETWEEN ENCODED AND DECODED FİLE :%d\n",number4);
	fclose(encoded);
	fclose(decoded);
}
