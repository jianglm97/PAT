/*1043. ���PATest(20)

����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰���PATestPATest....��������˳������������������ַ�����Ȼ�������ַ��ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�PATest��˳���ӡ��ֱ�������ַ����������

�����ʽ��

������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����

�����ʽ��

��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�

����������
redlesPayBestPATTopTeePHPereatitAPPT
���������
PATestPATestPTetPTePePee
*/
#include <stdio.h>
#include <string.h>
int main()
{
  char str[10010];
  int hashTable[200]={0};
  gets(str);
  int len=strlen(str);
  for(int i=0;i<len;i++) if(str[i]=='P'||str[i]=='A'||str[i]=='T'||str[i]=='e'||str[i]=='s'||str[i]=='t') hashTable[str[i]]++;
  while(hashTable['P']||hashTable['A']||hashTable['T']||hashTable['e']||hashTable['s']||hashTable['t'])
  {
    if(hashTable['P'])
    {
      printf("P");
      hashTable['P']--;
    }
    if(hashTable['A'])
    {
      printf("A");
      hashTable['A']--;
    }
    if(hashTable['T'])
    {
      printf("T");
      hashTable['T']--;
    }
    if(hashTable['e'])
    {
      printf("e");
      hashTable['e']--;
    }
    if(hashTable['s'])
    {
      printf("s");
      hashTable['s']--;
    }
    if(hashTable['t'])
    {
      printf("t");
      hashTable['t']--;
    }
  }
  return 0;
}
