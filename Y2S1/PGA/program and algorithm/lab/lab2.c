#include<stdio.h>

int main(){
   int windspeed;
   printf("enter the wind speed:");
   scanf("%d",&windspeed);
   if(windspeed<=62){
       printf("Tropical Depression\n");
   }else if(windspeed<=118){
       printf("Typhoon\n");
   }else if(windspeed<=156){
       printf("Strong Typhoon\n");
   }else if(windspeed<=192){
       printf("Very Strong Typhoon\n");
   }else{
       printf("Violent Typhoon\n");
   }
   return 0;
}