/*1035. ������鲢(25)

����ά���ٿƵĶ��壺

���������ǵ����㷨����һ����������ݣ��𲽲��������������С�ÿ�������У��㷨������������ȡ��һԪ�أ���֮����������������ȷ��λ�á���˵���ֱ��ȫ��Ԫ������

�鲢����������µ������������Ƚ�ԭʼ���п���N��ֻ����1��Ԫ�ص����������У�Ȼ��ÿ�ε����鲢�������ڵ����������У�ֱ�����ֻʣ��1����������С�

�ָ���ԭʼ���к���ĳ�����㷨�������м����У������жϸ��㷨���������������㷨��

�����ʽ��

�����ڵ�һ�и���������N (<=100)�����һ�и���ԭʼ���е�N�����������һ�и�����ĳ�����㷨�������м����С�������������Ŀ���������������ּ��Կո�ָ���

�����ʽ��

�����ڵ�1���������Insertion Sort����ʾ�������򡢻�Merge Sort����ʾ�鲢����Ȼ���ڵ�2��������ø������㷨�ٵ���һ�ֵĽ�����С���Ŀ��֤ÿ����ԵĽ����Ψһ�ġ����ּ��Կո�ָ�������ĩ�����ж���ո�
��������1��
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
�������1��
Insertion Sort
1 2 3 5 7 8 9 4 6 0
��������2��
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
�������2��
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=111;
int origin[N],tempOri[N],changed[N];
int n;
bool isSame(int A[],int B[])
{
  for(int i=0;i<n;i++) if(A[i]!=B[i]) return false;
  return true;
}
void showArray(int A[])
{
  for(int i=0;i<n;i++)
  {
    printf("%d",A[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");
}
bool insertSort()
{
  bool flag=false;
  for(int i=1;i<n;i++)
  {
    if(i!=1&&isSame(tempOri,changed)) flag=true;
    int temp=tempOri[i],j=i;
    while(j>0&&tempOri[j-1]>temp)
    {
      tempOri[j]=tempOri[j-1];
      j--;
    }
    tempOri[j]=temp;
    if(flag==true) return true;
  }
  return false;
}
void mergeSort()
{
  bool flag=false;
  for(int step=2;step/2<=n;step*=2)
  {
    if(step!=2&&isSame(tempOri,changed)) flag=true;
    for(int i=0;i<n;i+=step) sort(tempOri+i,tempOri+min(i+step,n));
    if(flag==true)
    {
      showArray(tempOri);
      return;
    }
  }
}
int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&origin[i]);
    tempOri[i]=origin[i];
  }
  for(int i=0;i<n;i++) scanf("%d",&changed[i]);
  if(insertSort())
  {
    printf("Insertion Sort\n");
    showArray(tempOri);
  }
  else
  {
    printf("Merge Sort\n");
    for(int i=0;i<n;i++) tempOri[i]=origin[i];
    mergeSort();
  }
  return 0;
}
