#include<stdio.h>
int main(){
    int currency;
    float amount,converted;
    printf("Enter your amount;\n");
    scanf("%f",&amount);//Enter your money.
    printf("Please select your currency\n");
    printf("1. Türkish lira\n");
    printf("2. Euro\n");
    printf("3. Dollar\n");
    scanf("%d",&currency);//Which currency dou you want ? 
    switch(currency)
    {
    case 1:
         printf("You have %f Türkish liras\n",amount);
         printf("Choose which currency  you want to convert\n");
         scanf("%d",&currency);//This convert your money to another
	 	if(currency==2){
		   printf("You have %f Euros.\n",amount/6.69);// convert the money 

		}
		else if(currency==3){
		   printf("You have %f Dollar.\n",amount/6.14);	// convert the money
		}
		else{
		   printf("Please enter invalid currency\n");			
		}
	break; //end of case 1
    case 2:
         printf("You have %f Euros\n",amount);
         printf("Choose which currency  you want to convert\n");
         scanf("%d",&currency);
	 	if(currency==1){
		   printf("You have %f Türkish Liras.\n",amount*6.69);

		}
		else if(currency==3){
		   printf("You have %f Dollars.\n",amount*1.10);	
		}
		else{
		   printf("Please enter invalid currency 1 or 3\n");			
		}
	break;//end of case 2
	                                                                                                                                                                                                                                                                                                                                                                                          
         printf("You have %f Dollars\n",amount);
         printf("Choose which currency  you want to convert\n");
         scanf("%d",&currency);
	 	if(currency==1){
		   printf("You have %f Türkish Liras.\n",amount*6.14);
		}
		else if(currency==2){
		   printf("You have %f Euros.\n",amount/1.10);	
		}
		else{
		   printf("Please enter invalid currency 1 or 2\n");			
		}
 	   	break;// end of case 3
	default:
	printf("Your selection is invalid\n");
	break;
		}
return 0;
}
    
