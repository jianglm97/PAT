/*1096. Consecutive Factors (20)

Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the three consecutive numbers.
Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

Input Specification:

Each input file contains one test case, which gives the integer N (1<N<2^31).

Output Specification:

For each test case, print in the first line the maximum number of consecutive factors.
Then in the second line, print the smallest sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:
630
Sample Output:
3
5*6*7
*/
#include <stdio.h>
typedef long long LL;
int main()
{
  LL N,start=0,len=0;
  scanf("%lld",&N);
  for(LL i=2;i*i<=N;i++)
  {
    LL temp=1,j=i;
    while(1)
    {
      temp*=j;
      if(N%temp!=0) break;
      if(j-i+1>len)
      {
        start=i;
        len=j-i+1;
      }
      j++;
    }
  }
  if(len==0) printf("1\n%lld",N);
  else
  {
    printf("%lld\n",len);
    for(LL i=0;i<len;i++)
    {
      printf("%lld",start+i);
      if(i<len-1) printf("*");
    }
  }
  return 0;
}
