/*1048. ���ּ���(20)

����Ҫ��ʵ��һ�����ּ��ܷ��������ȹ̶�һ��������������A������һ������B������ÿ1λ������A�Ķ�Ӧλ���ϵ����ֽ����������㣺
������λ����Ӧλ��������Ӻ��13ȡ�ࡪ��������J����10��Q����11��K����12����ż��λ����B�����ּ�ȥA�����֣������Ϊ���������ټ�10���������λΪ��1λ��

�����ʽ��

������һ�������θ���A��B����Ϊ������100λ��������������Կո�ָ���

�����ʽ��

��һ����������ܺ�Ľ����

����������
1234567 368782971
���������
3695Q8118
*/
#include <stdio.h>
#include <string.h>
int main()
{
  char a[110],b[110],ans[110]={0},m[15]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
  int count=0,i,j;
  scanf("%s%s",a,b);
  int lena=strlen(a);
  int lenb=strlen(b);
  for(i=lena-1,j=lenb-1;i>=0&&j>=0;i--,j--)
  {
    if((count+1)%2==1)
    {
      int r=(b[j]-'0'+a[i]-'0')%13;
      ans[count++]=m[r];
    }
    else
    {
      int sub=b[j]-a[i];
      if(sub<0) sub+=10;
      ans[count++]=sub+'0';
    }
  }
  if(lena>lenb) for(i;i>=0;i--)
  {
    if((count+1)%2==1)
    {
      int r=(a[i]-'0')%13;
      ans[count++]=m[r];
    }
    else
    {
      if(a[i]=='0') ans[count++]='0';
      else ans[count++]='0'-a[i]+10+'0';   //CAUTION HERE
    }
  }
  if(lena<lenb) for(j;j>=0;j--) ans[count++]=b[j];
  int k;
  for(k=count-1;k>=0;k--) if(ans[k]!='0') break;
  if(k==-1) printf("0");
  for(k;k>=0;k--) printf("%c",ans[k]);
  return 0;
}

