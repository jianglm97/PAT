/*1001. A+B Format (20)

Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
*/
#include <stdio.h>
int main()
{
  int a,b;
  char num[20];
  scanf("%d%d",&a,&b);
  int ans=a+b;
  if(ans<0)
  {
    printf("-");
    ans*=-1;
  }
  int i=0,j=0;
  do
  {
    num[i++]=ans%10+'0';
    j++;
    ans/=10;
    if(j%3==0) num[i++]=',';
  }
  while(ans!=0);
  if(i==8||i==4) for(i=i-2;i>=0;i--)  printf("%c",num[i]);
  for(i--;i>=0;i--) printf("%c",num[i]);
  return 0;
}
