#include <stdio.h>

int main() {
int ASCII;
char ch;
printf("Enter a character: \n");
scanf("%c",&ch);

//converting ch to its ascii value using type conversion
ASCII = (int) ch;
printf("The ASCII value is:%d\n",ch);
if(ASCII>=65&&ASCII<=90)
{
  printf("uppercase");
}
else if(ASCII>=97&&ASCII<=122)
{
  printf("lowercase");
}
else{
  printf("a digit or a symbol");
}
  return 0;
}