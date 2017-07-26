/*1013. ������ (20)

��Pi��ʾ��i�����������θ�����������M <= N <= 10^4�������PM��PN������������

�����ʽ��

������һ���и���M��N������Կո�ָ���

�����ʽ��

�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�

����������
5 27
���������
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
