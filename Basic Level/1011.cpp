/*1011. A+B��C (15)

��������[-2^31, 2^31]�ڵ�3������A��B��C�����ж�A+B�Ƿ����C��

�����ʽ��

�����1�и���������T(<=10)���ǲ��������ĸ�����������T�����������ÿ��ռһ�У�˳�����A��B��C���������Կո�ָ���

�����ʽ��

��ÿ�������������һ���������Case #X: true�����A+B>C�����������Case #X: false��������X�ǲ��������ı�ţ���1��ʼ����

����������
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
���������
Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/
#include <stdio.h>
int main()
{
   int T,i=1;
   long long A,B,C;
   scanf("%d",&T);
   while(T--)
   {
     scanf("%lld%lld%lld",&A,&B,&C);
     if(A+B>C) printf("Case #%d: true\n",i++);
     else printf("Case #%d: false\n",i++);
   }
   return 0;
}
