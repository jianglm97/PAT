/*1082. Read Number in Chinese (25)

Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative.
For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".

Input Specification:

Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:

For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

Sample Input 1:
-123456789    -1,2345,6789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai
*/
#include <stdio.h>
#include <string.h>
char num[12][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[10][10]={"Shi","Bai","Qian","Wan","Yi"};
int main()
{
  char str[11];
  gets(str);
  int len=strlen(str);
  int left=0,right=len-1;
  if(str[0]=='-')
  {
    printf("Fu");
    left++;
  }
  while(left+4<=right) right-=4;
  while(left<len)
  {
    bool flag=false;    //累积的0
    bool isPrint=false;  //该节是否有输出
    while(left<=right)
    {
      if(left>0&&str[left]=='0') flag=true;
      else
      {
        if(flag==true)
        {
          printf(" ling");
          flag=false;
        }
        if(left>0) printf(" ");
        printf("%s",num[str[left]-'0']);
        isPrint=true;
        if(left!=right) printf(" %s",wei[right-left-1]);
      }
      left++;
    }
    if(isPrint==true&&right!=len-1) printf(" %s",wei[(len-1-right)/4+2]);
    right+=4;
  }
  return 0;
}
