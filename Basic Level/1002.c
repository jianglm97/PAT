/*1002. д������� (20)

����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10^100��

�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�

����������
1234567890987654321123456789
���������
yi san wu
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int i,j=0,s=0;
  static char a[110];
  int b[5];
  gets(a);
  for(i=0;a[i]!='\0';i++) s+=a[i]-'0';
  do
  {
    b[j]=s%10;
    s/=10;
    j++;
  }
  while(s!=0);
  for(i=j-1;i>0;i--)
  {
     switch(b[i])
     {
       case 0: printf("ling "); break;
       case 1: printf("yi "); break;
       case 2: printf("er "); break;
       case 3: printf("san "); break;
       case 4: printf("si "); break;
       case 5: printf("wu "); break;
       case 6: printf("liu "); break;
       case 7: printf("qi "); break;
       case 8: printf("ba "); break;
       case 9: printf("jiu "); break;
     }
  }
  switch(b[0])
  {
    case 0: printf("ling"); break;
    case 1: printf("yi"); break;
    case 2: printf("er"); break;
    case 3: printf("san"); break;
    case 4: printf("si"); break;
    case 5: printf("wu"); break;
    case 6: printf("liu"); break;
    case 7: printf("qi"); break;
    case 8: printf("ba"); break;
    case 9: printf("jiu"); break;
     }
  return 0;
}
