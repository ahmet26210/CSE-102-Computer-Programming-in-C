#include<stdio.h>
#include<math.h>
int find_digit(int number, int index); /*This find the digit of number wanted from user*/
int number_length(int number);/*This find the number length of the number */
int main(){
    int number,y,index,f,x;
    printf("Please enter a number (maximum 6 digits)\n");
    scanf("%d",&number);/* GETS NUMBER*/
    y=number_length(number);
    if(y>0 && y<7){/*Take only the from 1 to 6 length of number*/
        printf("Your number has %d digits\n\n",y);
        printf("When your number is written 100 times next to each other,which digit of this number would you like to see?\n\n");
        scanf("%d",&f);/*This part is related Which digit of number would you like to see */
        index=f%y;/*This part take mod of the entered digit and number length of number */
        x=find_digit(number,index);
        printf("%d.th digit of the big number sequence:%d",f,x);
                    
            }
    else{
    	printf("please enter maximum 6 digits");     
    }
    
    	return 0;
    
    }
    
    
int number_length(int number){
    if(number>0 && number<10){/*To find the number length of number*/
                return 1;
                }
    if(number>9 && number<100){
                return 2;
                }           
    if(number>99 && number<1000){
                return 3;
                }
    if(number>999 && number<10000){
                return 4;
                }
    if(number>9999 && number<100000){
                return 5;
                }
    if(number>99999 && number<1000000){
                return 6;
                }
    
    }
int find_digit(int number, int index){
    int a,d,f,c;
	if(number_length(number)==6){/*According to the number length*/
	    if(index==0){
		     d=number%10;/*To find the last number*/
		     return d;
             }
	    else if(index==1){
		     c=(int)pow(10 ,5);/*Reaching the number length*/
		     d=number/c;
		     return d;
             }
	    else if(index==2){
		     c=(int)pow(10 ,4);
		     d=(number/c)%10;
		     return d;
             }
	    else if(index==3){
		     c=(int)pow(10 ,3);
		     d=(number/c)%10;
		     return d;
             }
	    else if(index==4){
		     c=(int)pow(10 ,2);
		     d=(number/c)%10;
		     return d;
             }
	    else if(index==5){
		     c=(int)pow(10 ,1);
		     d=(number/c)%10;
		     return d;
             }
          }
	else if(number_length(number)==5){
	    if(index==0){
		     d=number%10;
		     return d;
             }
	    else if(index==1){
		     c=(int)pow(10 ,4);
		     d=number/c;
		     return d;
             }
	    else if(index==2){
		     c=(int)pow(10 ,3);
		     d=(number/c)%10;
		     return d;
             }
	    else if(index==3){
		     c=(int)pow(10 ,2);
		     d=(number/c)%10;
		     return d;
             }
	    else if(index==4){
		     c=(int)pow(10 ,1);
		     d=(number/c)%10;
		     return d;
             }
	    
           }
	else if(number_length(number)==4){
	    if(index==0){
		     d=number%10;
		     return d;
             }
	    else if(index==1){
		     c=(int)pow(10 ,3);
		     d=number/c;
		     return d;
             }
	    else if(index==2){
		     c=(int)pow(10 ,2);
		     d=(number/c)%10;
		     return d;
             }
	    else if(index==3){
		     c=(int)pow(10 ,1);
		     d=(number/c)%10;
		     return d;
             }
	    
           }
	else if(number_length(number)==3){
	    if(index==0){
		     d=number%10;
		     return d;
             }
	    else if(index==1){
		     c=(int)pow(10 ,2);
		     d=number/c;
		     return d;
             }
	    else if(index==2){
		     c=(int)pow(10 ,1);
		     d=(number/c)%10;
		     return d;
             }
	    
          }
	else if(number_length(number)==2){
	    if(index==0){
		     d=number%10;
		     return d;
             }
	    else if(index==1){
		     c=(int)pow(10 ,1);
		     d=number/c;
		     return d;
             }
	    
         }
	else if(number_length(number)==1){
	    if(index==0){
		     d=number%10;
		     return d;
             }
	    
	    
          }
    }
