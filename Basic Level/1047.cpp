/*1047. ���������(20)

����������Ĺ���Ϊ��ÿ�������������ɶ�Ա��ɣ����ж�Ա���������������ӵĳɼ�Ϊ���ж�Ա�ĳɼ��ͣ��ɼ���ߵĶӻ�ʤ��

�ָ������ж�Ա�ı����ɼ��������д�����ҳ��ھ��ӡ�

�����ʽ��

�����һ�и���һ��������N��<=10000���������в�����Ա���������N�У�ÿ�и���һλ��Ա�ĳɼ�����ʽΪ����������-��Ա��� �ɼ��������С������š�Ϊ1��1000��������������Ա��š�Ϊ1��10�������������ɼ���Ϊ0��100��������

�����ʽ��

��һ��������ھ��ӵı�ź��ܳɼ��������һ���ո�ָ���ע�⣺��Ŀ��֤�ھ�����Ψһ�ġ�

����������
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
���������
11 176
*/
#include <stdio.h>
int main()
{
  int N,team,mate,score,hashTable[1010]={0};
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d-%d %d",&team,&mate,&score);
    hashTable[team]+=score;
  }
  int max=-1,idx;
  for(int i=0;i<1000;i++) if(hashTable[i]>max)
  {
    max=hashTable[i];
    idx=i;
  }
  printf("%d %d",idx,max);
  return 0;
}