/*1029. �ɼ���(20)

�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ�ʵ�ʱ���������֣������г��϶���������Щ����

�����ʽ��

������2���зֱ����Ӧ����������֡��Լ�ʵ�ʱ���������֡�ÿ�������ǲ�����80���ַ��Ĵ�������ĸA-Z��������Сд��������0-9���Լ��»��ߡ�_��������ո���ɡ���Ŀ��֤2���ַ������ǿա�

�����ʽ��

���շ���˳����һ������������ļ�������Ӣ����ĸֻ�����д��ÿ������ֻ���һ�Ρ���Ŀ��֤������1��������

����������
7_This_is_a_test
_hs_s_a_es
���������
7TI
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int hashTable[200]={0};
  char str1[100],str2[100];
  gets(str1);
  for(int i=0;i<strlen(str1);i++) hashTable[str1[i]]++;
  gets(str2);
  for(int i=0;i<strlen(str2);i++) hashTable[str2[i]]--;
  for(int i=0;i<strlen(str1);i++)
  {
    if(hashTable[str1[i]]!=0)
    {
      if(str1[i]<='z'&&str1[i]>='a') printf("%c",str1[i]-32);
      else printf("%c",str1[i]);
      hashTable[str1[i]]=0;
      if(str1[i]<='z'&&str1[i]>='a') hashTable[str1[i]-32]=0;
      if(str1[i]<='Z'&&str1[i]>='A') hashTable[str1[i]+32]=0;
    }
  }
  return 0;
}
