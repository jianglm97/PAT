/*1042. �ַ�ͳ��(20)

���д�����ҳ�һ�θ��������г�����Ƶ�����Ǹ�Ӣ����ĸ��

�����ʽ��

������һ���и���һ�����Ȳ�����1000���ַ������ַ�����ASCII���������ɼ��ַ����ո���ɣ����ٰ���1��Ӣ����ĸ���Իس��������س��������ڣ���

�����ʽ��

��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ�������в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��

����������
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
���������
e 7
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int hashTable[200]={0};
  char str[1010];
  gets(str);
  int len=strlen(str);
  for(int i=0;i<len;i++)
  {
    if(str[i]<='z'&&str[i]>='a') hashTable[str[i]]++;
    if(str[i]<='Z'&&str[i]>='A') hashTable[str[i]+32]++;
  }
  int max=0,idx;
  for(int i=0;i<190;i++) if(hashTable[i]>max)
  {
    max=hashTable[i];
    idx=i;
  }
  printf("%c %d",idx,max);
  return 0;
}
