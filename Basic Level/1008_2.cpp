/*1008. ����Ԫ��ѭ���������� (20)

һ������A�д���N��N>0�����������ڲ�����ʹ�����������ǰ���£���ÿ������ѭ��������M��M>=0����λ�ã�����A�е������ɣ�A0 A1����AN-1���任Ϊ��AN-M ���� AN-1 A0 A1����AN-M-1�������M����ѭ��������ǰ���M��λ�ã���
�����Ҫ���ǳ����ƶ����ݵĴ��������٣�Ҫ�������ƶ��ķ�����

�����ʽ��ÿ���������һ��������������1������N ( 1<=N<=100)��M��M>=0������2������N��������֮���ÿո�ָ���

�����ʽ����һ�������ѭ������Mλ�Ժ���������У�֮���ÿո�ָ������н�β�����ж���ո�

����������
6 2
1 2 3 4 5 6
���������
5 6 1 2 3 4
*/
#include <stdio.h>
int gcd(int a,int b)
{
  if(b==0) return a;
  else return gcd(b,a%b);
}
int main()
{
  int a[110];
  int n,m,temp,pos,next;
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  m=m%n;
  if(m)
  {
    int d=gcd(m,n);
    for(int i=n-m;i<n-m+d;i++)
    {
      temp=a[i];
      pos=i;
      do
      {
        next=(pos-m+n)%n;
        if(next!=i) a[pos]=a[next];
        else a[pos]=temp;
        pos=next;
      }
      while(pos!=i);
    }
  }
  for(int i=0;i<n;i++)
  {
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  return 0;
}
