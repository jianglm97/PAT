/*1003. ��Ҫͨ����(20)

������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
���������
YES
YES
YES
YES
NO
NO
NO
NO
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int n;
  char str[110];
  scanf("%d",&n);
  getchar();
  while(n--)
  {
    gets(str);
    int len=strlen(str);
    int pnum=0,ploc=-1,tnum=0,tloc=-1,other=0;
    for(int i=0;i<len;i++)
    {
      if(str[i]=='P')
      {
        pnum++;
        ploc=i;
      }
      else if(str[i]=='T')
      {
        tnum++;
        tloc=i;
      }
      else if(str[i]!='A') other++;
    }
    if(pnum!=1||tnum!=1||other!=0||tloc-ploc<=1)
    {
      printf("NO\n");
      continue;
    }
    int x=ploc,y=tloc-ploc-1,z=len-tloc-1;
    if(z-x*(y-1)==x) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
