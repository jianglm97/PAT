/*1005. Spell It Right (20)

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int sum=0,S[10];
  char N[110],change[15][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
  gets(N);
  int len=strlen(N);
  for(int i=len-1;i>=0;i--) sum+=N[i]-'0';
  int j=0;
  do
  {
    S[j++]=sum%10;
    sum/=10;
  }
  while(sum!=0);
  for(j--;j>=0;j--)
  {
    printf("%s",change[S[j]]);
    if(j!=0) printf(" ");
  }
  return 0;
}
