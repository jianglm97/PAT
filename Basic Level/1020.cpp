/*1020. �±� (25)

�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±����ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�

ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ�����������3���±����������ֱ�Ϊ18��15��10��֣����ۼ۷ֱ�Ϊ75��72��45��Ԫ��
����г������������ֻ��20��֣���ô��������������Ӧ��������ȫ��15��ֵ�2���±����Լ�5��ֵ�3���±������ 72 + 45/2 = 94.5����Ԫ����

�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��ʾ�±������������Լ�������500�������Ϊ��λ����������D��ʾ�г������������
���һ�и���N��������ʾÿ���±��Ŀ�����������Ϊ��λ�������һ�и���N��������ʾÿ���±������ۼۣ�����ԪΪ��λ�������ּ��Կո�ָ���

�����ʽ��

��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С�����2λ��

����������
3 20
18 15 10
75 72 45
���������
94.50
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct mooncake
{
  double amount,total,price;
}cake[1010];
bool cmp(mooncake a,mooncake b)
{
  return a.price>b.price;
}
int main()
{
  int N,D,count=0;
  double sum=0;
  scanf("%d%d",&N,&D);
  for(int i=0;i<N;i++) scanf("%lf",&cake[i].amount);
  for(int i=0;i<N;i++)
  {
    scanf("%lf",&cake[i].total);
    cake[i].price=1.0*cake[i].total/cake[i].amount;
  }
  sort(cake,cake+N,cmp);
  int j=0;
  while(count<D&&j<N)
  {
    if(count+cake[j].amount<D)
    {
      sum+=cake[j].total;
      count+=cake[j].amount;
    }
    else
    {
      sum+=cake[j].price*(D-count);
      break;
    }
    j++;
  }
  printf("%.2f",sum);
  return 0;
}
