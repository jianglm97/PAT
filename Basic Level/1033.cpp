/*1033. �ɼ��̴���(20)

�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ���������Щ��������Ľ�����ֻ���������

�����ʽ��

������2���зֱ������������Щ�����Լ�Ӧ����������֡����ж�ӦӢ����ĸ�Ļ����Դ�д������ÿ�������ǲ�����10^5���ַ��Ĵ���
���õ��ַ�������ĸ[a-z, A-Z]������0-9���Լ��»��ߡ�_��������ո񣩡���,������.������-������+���������ϵ���������Ŀ��֤��2����������ִ��ǿա�

ע�⣺����ϵ��������ˣ���ô��д��Ӣ����ĸ�޷��������

�����ʽ��

��һ��������ܹ�������Ľ�����֡����û��һ���ַ��ܱ��������������С�

����������
7+IE.
7_This_is_a_test.
���������
_hs_s_a_tst
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
  bool hashTable[100010]={0},flag=0;
  char broken[100],str[100010];
  gets(broken);
  for(int i=0;i<strlen(broken);i++) if(broken[i]>='A'&&broken[i]<='Z') broken[i]+=32;
  gets(str);
  int len=strlen(str);
  fill(hashTable,hashTable+len,1);
  for(int i=0;i<strlen(broken);i++)
  {
    if(broken[i]=='+') for(int j=0;j<len;j++) if(str[j]>='A'&&str[j]<='Z') hashTable[j]=0;
    for(int j=0;j<len;j++) if(str[j]==broken[i]||str[j]+32==broken[i]) hashTable[j]=0;
  }
  for(int i=0;i<len;i++) if(hashTable[i]==1) printf("%c",str[i]);
  return 0;
}
