/*1022. D���Ƶ�A+B (20)

���������Ǹ�10��������A��B(<=2^30-1)�����A+B��D (1 < D <= 10)��������

�����ʽ��

������һ�������θ���3������A��B��D��

�����ʽ��

���A+B��D��������

����������
123 456 8
���������
1103
*/
#include <stdio.h>
int main()
{
  int A,B,D,a[50],num=0;
  scanf("%d%d%d",&A,&B,&D);
  long long ans=A+B;
  do
  {
    a[num++]=ans%D;
    ans/=D;
  }
  while(ans!=0);
  for(int i=num-1;i>=0;i--) printf("%d",a[i]);
  return 0;
}
