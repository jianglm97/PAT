/*1040. �м���PAT��25��

�ַ���APPAPT�а������������ʡ�PAT�������е�һ��PAT�ǵ�2λ(P),��4λ(A),��6λ(T)���ڶ���PAT�ǵ�3λ(P),��4λ(A),��6λ(T)��

�ָ����ַ�������һ�������γɶ��ٸ�PAT��

�����ʽ��

����ֻ��һ�У�����һ���ַ��������Ȳ�����10^5��ֻ����P��A��T������ĸ��

�����ʽ��

��һ������������ַ����а������ٸ�PAT�����ڽ�����ܱȽϴ�ֻ�����1000000007ȡ�����Ľ����

����������
APPAPT
���������
2
*/
#include <cstdio>
#include <cstring>
int main()
{
  int leftNumP[100010],rightNumT=0,sum=0;
  char str[100010];
  gets(str);
  int len=strlen(str);
  if(str[0]=='P') leftNumP[0]=1;
  else leftNumP[0]=0;
  for(int i=1;i<len;i++)
  {
    if(str[i]=='P') leftNumP[i]=leftNumP[i-1]+1;
    else leftNumP[i]=leftNumP[i-1];
  }
  for(int i=len-1;i>=0;i--)
  {
    if(str[i]=='T') rightNumT++;
    if(str[i]=='A') sum=(sum+leftNumP[i]*rightNumT)%1000000007;
  }
  printf("%d",sum);
  return 0;
}
