/*1059. Prime Factors (25)

Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *бн*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *бн*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/
#include <stdio.h>
const int maxn=100010;
int prime[maxn],pnum=0;
bool isPrime(int n)
{
  if(n<=1) return false;
  for(int i=2;i*i<=n;i++) if(n%i==0) return false;
  return true;
}
void Find_Prime()
{
  for(int i=1;i<maxn;i++) if(isPrime(i)==true) prime[pnum++]=i;
}
struct factor
{
  int x,cnt;
}fac[10];
int main()
{
  Find_Prime();
  int N,num=0;
  scanf("%d",&N);
  if(N==1)
  {
    printf("1=1");
    return 0;
  }
  printf("%d=",N);
  for(int i=0;i<pnum&&prime[i]*prime[i]<=N;i++)
  {
    if(N%prime[i]==0)
    {
      fac[num].x=prime[i];
      fac[num].cnt=0;
      while(N%prime[i]==0)
      {
        fac[num].cnt++;
        N/=prime[i];
      }
      num++;
    }
    if(N==1) break;
  }
  if(N!=1)
  {
    fac[num].x=N;
    fac[num++].cnt=1;
  }
  for(int i=0;i<num;i++)
  {
    if(i>0) printf("*");
    printf("%d",fac[i].x);
    if(fac[i].cnt>1) printf("^%d",fac[i].cnt);
  }
  return 0;
}
