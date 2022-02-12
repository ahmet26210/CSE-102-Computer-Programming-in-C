#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct {
	char *name;
	char citiesServed[3];
}Hospital;
int numPathsHome(int y,int x);
void assign_value();
void print_value();
int control(char _cities[6],char _locations[4][3]);
int canOfferCovidCoverage(char _cities[6],char _locations[4][3],int _numHospitals,Hospital results[4]);
void menu();

struct card{
	const char *face;
	const char *suit;
}temp[1],ydizi[52]={
			"Ace","Clubs","Deuce","Clubs","Three","Clubs","Four","Clubs","Five","Clubs","Six","Clubs","Seven","Clubs","Eight","Clubs","Nine","Clubs","Ten","Clubs","Jack","Clubs","Queen","Clubs","King","Clubs",
			"Ace","Spades","Deuce","Spades","Three","Spades","Four","Spades","Five","Spades","Six","Spades","Seven","Spades","Eight","Spades","Nine","Spades","Ten","Spades","Jack","Spades","Queen","Spades","King","Spades",
			"Ace","Hearts","Deuce","Hearts","Three","Hearts","Four","Hearts","Five","Hearts","Six","Hearts","Seven","Hearts","Eight","Hearts","Nine","Hearts","Ten","Hearts","Jack","Hearts","Queen","Hearts","King","Hearts",
			"Ace","Diamonds","Deuce","Diamonds","Three","Diamonds","Four","Diamonds","Five","Diamonds","Six","Diamonds","Seven","Diamonds","Eight","Diamonds","Nine","Diamonds","Ten","Diamonds","Jack","Diamonds","Queen","Diamonds","King","Diamonds"
			};

int main()
{
	Hospital results[4];
	menu();
	return 0;
}
void menu(){
	int choose,sonuc=0,street,avenue,sonuc1;
	int _numHospitals;
	Hospital results[4];
	char _locations[4][3];
	char _cities[6]={'A','B','C','D','E','F'};
	while(1){
		printf("1.EXECUTE PART 1\n");
		printf("2.EXECUTE PART 2\n");
		printf("3.EXECUTE PART 3\n");
		printf("4.EXIT\n");
		printf("Please choose one of them\n");
		scanf("%d",&choose);
		if(choose==1){
			printf("please enter street: ");
			scanf("%d",&street);//y ekseni
			printf("please enter avenue: ");
			scanf("%d",&avenue);//x ekseni
			sonuc+=numPathsHome(street,avenue);
			printf("Number of Optimal paths to take back home: %d\n\n",sonuc);
		} 
		else if(choose==2){
			printf("Enter the maximum number of hospitals that can be constructed: ");
			scanf("%d",&_numHospitals);
			sonuc1=canOfferCovidCoverage(_cities,_locations,_numHospitals,results);
			if(sonuc1==0){
				printf("No some cities are not covered.\n");
			}
			else if(sonuc1==1){
				printf("Yes,can offer health care to all!\n");
				printf("Hospital-1\n");
				printf("Hospital locations:%c%c%c \n",results[1].citiesServed[1],results[1].citiesServed[2],results[1].citiesServed[3]);
				printf("Hospital-2\n");
				printf("Hospital locations:%c%c%c \n",results[2].citiesServed[1],results[2].citiesServed[2],results[2].citiesServed[3]);
				printf("Hospital-3\n");
				printf("Hospital locations:%c%c%c \n",results[3].citiesServed[1],results[3].citiesServed[2],results[3].citiesServed[3]);
			}
			else if(sonuc1==2){
				printf("Yes,can offer health care to all!\n");
				printf("Hospital-1\n");
				printf("Hospital locations:%c%c%c \n",results[1].citiesServed[1],results[1].citiesServed[2],results[1].citiesServed[3]);
				printf("Hospital-2\n");
				printf("Hospital locations:%c%c%c \n",results[2].citiesServed[1],results[2].citiesServed[2],results[2].citiesServed[3]);
				printf("Hospital-3\n");
				printf("Hospital locations:%c%c%c \n",results[3].citiesServed[1],results[3].citiesServed[2],results[3].citiesServed[3]);
				printf("Hospital-4\n");
				printf("Hospital locations:%c%c \n",results[4].citiesServed[1],results[4].citiesServed[2]);
			}
			else if(sonuc1==-1){
				printf("wrong number enter again\n");
			}
		}
		else if(choose==3){
			assign_value();
			print_value();
		}
		else if(choose==4){
			exit(1);
		}
		else{
			printf("There is no option,enter again");
		}
	}
}
int numPathsHome(int y,int x){
	if(x==1 && y==1){
		return 1;

	}
	else if(x==1){// if we reach the end of x axis
		numPathsHome(y-1,x);
	}
	else if(y==1){
		numPathsHome(y,x-1);//if we reach the end of y axis
	}
	else if(x!=1 && y!=1){
		return numPathsHome(y,x-1)+numPathsHome(y-1,x);//This tries all the posibilities 
	}
}
void print_value(){
	int i=0;
	for(i;i<52;i++){
		printf("%-5s of %-5s\n",ydizi[i].face,ydizi[i].suit);
	}
	printf("\n\n");
}
void assign_value(){//this shuffle  all card
	int rondom1,rondom2,i;
	srand(time(NULL));
	for(i=0;i<104;i++){
		rondom1=rand()%52;
		rondom2=rand()%52;
		temp[1]=ydizi[rondom1];
		ydizi[rondom1]=ydizi[rondom2];
		ydizi[rondom2]=temp[1];
	}	
}
int canOfferCovidCoverage(char _cities[6],char _locations[4][3],int _numHospitals,Hospital results[4]){
	
	if(_numHospitals==1){
		_locations[1][1]=_cities[0];
		_locations[1][2]=_cities[1];
		_locations[1][3]=_cities[2];
		results[1].citiesServed[1]=_cities[0];
		results[1].citiesServed[2]=_cities[1];
		results[1].citiesServed[3]=_cities[2];
		if(control(_cities,_locations)==1){
			return 1;
		}
		else if(control(_cities,_locations)==2){
			return 2;
		}
		else{
			return 0;
		}
	}
	else if(_numHospitals==2){
		_locations[2][1]=_cities[0];
		_locations[2][2]=_cities[2];
		_locations[2][3]=_cities[3];
		results[2].citiesServed[1]=_cities[0];
		results[2].citiesServed[2]=_cities[2];
		results[2].citiesServed[3]=_cities[3];
		canOfferCovidCoverage(_cities,_locations,_numHospitals-1,results);
	}
	else if(_numHospitals==3){
		_locations[3][1]=_cities[2];
		_locations[3][2]=_cities[4];
		_locations[3][3]=_cities[5];
		results[3].citiesServed[1]=_cities[2];
		results[3].citiesServed[2]=_cities[4];
		results[3].citiesServed[3]=_cities[5];
		canOfferCovidCoverage(_cities,_locations,_numHospitals-1,results);
	}
	else if(_numHospitals==4){
		_locations[4][1]=_cities[1];
		_locations[4][2]=_cities[5];
		results[4].citiesServed[1]=_cities[1];
		results[4].citiesServed[2]=_cities[5];
		canOfferCovidCoverage(_cities,_locations,_numHospitals-1,results);
	}
	else {
		return -1;
	}
}

int control(char _cities[6],char _locations[4][3]){//checks if it covers all the hospitals
	int flag=-1,i,j,k=0,m;
	for(m=0;m<6;m++){
		for(i=1;i<=4;i++){
			for(j=1;j<=3;j++){
				if(_cities[m]==_locations[i][j]){
					flag++;
				}
			}
		}
	}
	if(flag==8){
		return 1;
	}
	else if(flag==10){
		return 2; 
	}
	else{
		return 0;
	}
}