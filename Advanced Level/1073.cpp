/*1073. Scientific Notation (20)

Scientific notation is the way that scientists easily handle very large numbers or very small numbers.
The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit,
there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int exp=0;
  bool flag=0;
  char str[10010];
  gets(str);
  if(str[0]=='-') printf("-");
  int i=0;
  do
  {
    i++;
  }
  while(str[i]!='+'&&str[i]!='-');
  if(str[i]=='+') flag=1;
  int len=i-4;  //小数点后到E前的数字长度
  for(i++;str[i]!='\0';i++) exp=exp*10+str[i]-'0';
  if(flag==0)
  {
    printf("0.");
    for(int i=0;i<exp-1;i++) printf("0");
    for(int i=1;str[i]!='E';i++)
    {
      if(str[i]=='.') continue;
      printf("%c",str[i]);
    }
  }
  else
  {
    if(exp<=len)
    {
      int j;
      for(j=1;j<=exp+2;j++)
      {
        if(str[j]=='.') continue;
        printf("%c",str[j]);
      }
      if(exp!=len)
      {
        printf(".");
        for(j;str[j]!='E';j++) printf("%c",str[j]);
      }
    }
    else
    {
      for(int j=1;str[j]!='E';j++)
      {
        if(str[j]=='.') continue;
        printf("%c",str[j]);
      }
      for(int j=1;j<=exp-len;j++) printf("0");
    }
  }
  return 0;
}
