#include <stdio.h>
#include <math.h>

double hypotenuse(double length1,double length2);


int main(){
    hypotenuse(3.0,4.0);
    hypotenuse(5.0,12.0);
    hypotenuse(8.0,15.0);
}

double hypotenuse(double length1,double length2){   
    printf("%lf/n",sqrt(length1*length1+length2*length2));
    return sqrt(length1*length1+length2*length2);
}