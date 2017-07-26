/*1049. Counting Ones (30)

The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=2^30).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
*/
#include <stdio.h>
int main()
{
  int N,a=1,ans=0,left,now,right;
  scanf("%d",&N);
  while(N/a)
  {
    left=N/(a*10);
    now=N/a%10;
    right=N%a;
    if(now==0) ans+=left*a;
    else if(now==1) ans+=left*a+right+1;
    else ans+=(left+1)*a;
    a*=10;
  }
  printf("%d",ans);
  return 0;
}
