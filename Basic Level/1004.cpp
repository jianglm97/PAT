/*1004. �ɼ����� (20)

����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��ÿ�������������1��������������ʽΪ

  ��1�У�������n
  ��2�У���1��ѧ�������� ѧ�� �ɼ�
  ��3�У���2��ѧ�������� ѧ�� �ɼ�
  ... ... ...
  ��n+1�У���n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
�����ʽ����ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�

����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
Mike CS991301
Joe Math990112
*/
#include <stdio.h>
struct student
{
  char name[15],id[15];
  int score;
}student[1000];
int main()
{
  int n,max=-1,min=101,bmax,bmin;
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%s%s%d",student[i].name,student[i].id,&student[i].score);
  for(int i=0;i<n;i++)
  {
    if(student[i].score>max)
    {
      max=student[i].score;
      bmax=i;
    }
    if(student[i].score<min)
    {
      min=student[i].score;
      bmin=i;
    }
  }
  printf("%s %s\n",student[bmax].name,student[bmax].id);
  printf("%s %s",student[bmin].name,student[bmin].id);
  return 0;
}
