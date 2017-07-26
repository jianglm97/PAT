/*1007. 素数对猜想 (20)

让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/
#include <stdio.h>
bool isPrime(int n)
{
  if(n<=1) return false;
  for(int i=2;i*i<=n;i++) if(n%i==0) return false;
  return true;
}
int main()
{
  int N,count=0;
  scanf("%d",&N);
  for(int i=3;i+2<=N;i+=2) if(isPrime(i)==true&&isPrime(i+2)==true) count++;
  printf("%d",count);
  return 0;
}
