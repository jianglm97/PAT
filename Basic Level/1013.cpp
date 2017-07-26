/*1013. 数素数 (20)

令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include <stdio.h>
const int maxn=100000000;
int prime[maxn],num=0;
bool p[maxn]={false};
bool isPrime(int n)
{
  if(n<=1) return false;
  for(int i=2;i*i<=n;i++) if(n%i==0) return false;
  return true;
}
void Find_Prime(int n)
{
  for(int i=1;i<maxn;i++) if(isPrime(i)==true)
  {
    prime[num++]=i;
    p[i]=true;
    if(num>=n) break;
  }
}
int main()
{
  int M,N,count=0;
  scanf("%d%d",&M,&N);
  Find_Prime(N);
  for(int i=M;i<=N;i++)
  {
    printf("%d",prime[i-1]);
    count++;
    if(count%10!=0&&i<N) printf(" ");
    else printf("\n");
  }
  return 0;
}
