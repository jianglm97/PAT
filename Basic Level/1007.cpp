/*1007. �����Բ��� (20)

�����Ƕ��� dn Ϊ��dn = pn+1 - pn������ pi �ǵ�i����������Ȼ�� d1=1 �Ҷ���n>1�� dn ��ż�����������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������

�ָ�������������N (< 10^5)������㲻����N���������������Եĸ�����

�����ʽ��ÿ�������������1����������������������N��

�����ʽ��ÿ���������������ռһ�У�������N���������������Եĸ�����

����������
20
���������
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
