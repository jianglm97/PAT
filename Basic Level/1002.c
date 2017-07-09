/*1002. 写出这个数 (20)

读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int i,j=0,s=0;
  static char a[110];
  int b[5];
  gets(a);
  for(i=0;a[i]!='\0';i++) s+=a[i]-'0';
  do
  {
    b[j]=s%10;
    s/=10;
    j++;
  }
  while(s!=0);
  for(i=j-1;i>0;i--)
  {
     switch(b[i])
     {
       case 0: printf("ling "); break;
       case 1: printf("yi "); break;
       case 2: printf("er "); break;
       case 3: printf("san "); break;
       case 4: printf("si "); break;
       case 5: printf("wu "); break;
       case 6: printf("liu "); break;
       case 7: printf("qi "); break;
       case 8: printf("ba "); break;
       case 9: printf("jiu "); break;
     }
  }
  switch(b[0])
  {
    case 0: printf("ling"); break;
    case 1: printf("yi"); break;
    case 2: printf("er"); break;
    case 3: printf("san"); break;
    case 4: printf("si"); break;
    case 5: printf("wu"); break;
    case 6: printf("liu"); break;
    case 7: printf("qi"); break;
    case 8: printf("ba"); break;
    case 9: printf("jiu"); break;
     }
  return 0;
}
