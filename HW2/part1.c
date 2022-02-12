#include<stdio.h>
#include<math.h>
int draw_triangle(int side1, int side2 ,int side3);/*Checking if a triangle can be drawn or not */
void type_triangle(int side1,int side2,int side3);/*Determining the triangle type*/
int perimeter_triangle(int side1, int side2, int side3);/*Finding the perimeter of triangle*/
float area_triangle(int side1 ,int side2, int side3 ,float perimeter);/*Finding the area of triangle*/

int main(){
	int a,b,c,x;
	float z,y;
	printf("The length of first side:\n");
	scanf("%d",&a);//FİRST SİDE OF TRİANGLE 
	printf("The length of first side:\n");
	scanf("%d",&b);//SECOND SİDE OF TRİANGLE
	printf("The length of first side:\n"); 
	scanf("%d",&c);//THİRD SİDE OF TRİANGLE  
	x=draw_triangle(a,b,c);   
		if(x==1){
			 printf("The triangle can be drawn\n");
			 type_triangle(a,b,c);
			 y=perimeter_triangle(a,b,c);
			 z=area_triangle(a,b,c,y);
			 printf("The area is %f",z);
 
          		}   
		else if(x==0){
      			printf("The triangle can  not be drawn\n");
 
    			  }
    
return 0;
}

 int draw_triangle(int side1 ,int side2 ,int side3){
     if(side1+side2>side3 && side1-side2<side3){//Checking triangle can be drawn
         if(side2+side3>side1 && side2-side3<side1){
            if(side1+side3>side2 && side1-side3<side2){
                   return 1;//If triangle can be drawn return 1              
                           }                   
            else{
                 return 0;//If triangle can not be drawn return 0
                 }                   
                              }
         else{
              return 0 ;
              }                     
                   }
 
     else{
          return 0;
		}
          }
 void type_triangle(int side1,int side2,int side3){
      if(side1==side2 && side2==side3 && side1==side3){
      printf("this triangle is isosceles\n");                
      }
      else if(side1==side2 && side2!=side3 && side1!=side3){
      printf("this triangle is isosceles\n");                
      }
      else if(side1!=side2 && side2==side3 && side1!=side3){
      printf("this triangle is isosceles\n");                
      }
      else if(side1!=side2 && side2!=side3 && side1==side3){
      printf("this triangle is isosceles\n");                
      }
      else{
      printf("this triangle is scalene\n");
           }
      
      }   
     
     
     
 
int perimeter_triangle(int side1, int side2, int side3){
    int perimeter;
    perimeter=side1+side2+side3;//Fİnding the perimeter of triangle
    return perimeter;

    }
    
    
float area_triangle(int side1, int side2, int side3, float perimeter){
       float area,p;
       p=perimeter/2;//This part for finding the area of triangle
     area=sqrt(p*(p-side1)*(p-side2)*(p-side3));//Fİnding the area  
       return area;
       }
