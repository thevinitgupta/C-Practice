#include <stdio.h>
#include<math.h>

int fact(int y)
{
int fact=1,j;
for(j=y;j>=1;j--)
{
fact=fact*j;
}
return fact;
}

int main() 
{
int i,x,range;
float sum=0;
printf("Enter the number of terms of the series: ");
scanf("%d",&range);
printf("\nEnter the value of x: ");
scanf("%d",&x);
for(i=2;i<=range;i=i+4)
{
sum=sum-(pow(x,i)/fact(i));
sum=sum+(pow(x,i+2)/fact(i+2));
}
sum=sum+1;
printf("\nValue of the series is %f",sum);
return 0;
}
 