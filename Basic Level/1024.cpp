/*1024. 科学计数法 (20)

科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

输出格式：

对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
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
