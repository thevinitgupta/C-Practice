#include <stdio.h>

int main() 
{
int a,b;
float c;
char ch='Y';
printf("Enter the number of classes held: \n");
scanf("%d",&a);
printf("Enter the number of classes attended: \n");
scanf("%d",&b);
c=((b*100)/a);

printf("Does the student has any medical cause?\nPress Y for yes and N for no\n");
scanf("%s",&ch);
printf("The student attended %f percent of class\n",c);
if(c>75||ch=='Y')
{
printf("The student can sit in exam");
}
else
printf("The student cannot sit in exam");
  return 0;
}