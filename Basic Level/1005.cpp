/*1005. ����(3n+1)���� (25)

������(Callatz)�����Ѿ���1001�и������������������Ŀ������΢��Щ���ӡ�

��������֤�����Ȳ����ʱ��Ϊ�˱����ظ����㣬���Լ�¼�µ��ƹ�����������ÿһ�����������n=3������֤��ʱ��������Ҫ����3��5��8��4��2��1�������Ƕ�n=5��8��4��2������֤��ʱ�򣬾Ϳ���ֱ���ж������Ȳ������α��������Ҫ�ظ����㣬
��Ϊ��4�����Ѿ�����֤3��ʱ���������ˣ����ǳ�5��8��4��2�Ǳ�3�����ǡ����������ǳ�һ�������е�ĳ����nΪ���ؼ����������n���ܱ������е��������������ǡ�

���ڸ���һϵ�д���֤�����֣�����ֻ��Ҫ��֤���еļ����ؼ������Ϳ��Բ������ظ���֤���µ����֡������������ҳ���Щ�ؼ����֣������Ӵ�С��˳��������ǡ�

�����ʽ��ÿ�������������1��������������1�и���һ��������K(<100)����2�и���K��������ͬ�Ĵ���֤��������n(1<n<=100)��ֵ�����ּ��ÿո������

�����ʽ��ÿ���������������ռһ�У����Ӵ�С��˳������ؼ����֡����ּ���1���ո��������һ�������һ�����ֺ�û�пո�

����������
6
3 5 6 7 8 11
���������
7 6
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
  bool hashTable[10000]={false};
  int K,a[110];
  scanf("%d",&K);
  for(int i=0;i<K;i++)
  {
    scanf("%d",&a[i]);
    int temp=a[i];
    while(temp!=1)
    {
      if(temp%2!=0) temp=3*temp+1;
      temp/=2;
      hashTable[temp]=true;
    }
  }
  sort(a,a+K);
  int j;
  for(j=K-1;j>=0;j--) if(hashTable[a[j]]==false)
  {
    printf("%d",a[j]);
    break;
  }
  for(j--;j>=0;j--) if(hashTable[a[j]]==false) printf(" %d",a[j]);
  return 0;
}