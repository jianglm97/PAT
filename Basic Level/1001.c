/*1001. �����˲�������(3n+1)���� (15)

������(Callatz)���룺

���κ�һ����Ȼ��n���������ż������ô��������һ�룻���������������ô��(3n+1)����һ�롣����һֱ��������ȥ�����һ����ĳһ���õ�n=1����������1950���������ѧ�Ҵ���Ϲ�����������룬
��˵��ʱҮ³��ѧʦ���붯Ա��ƴ����֤�����ò�ƺ�ɵ����������⣬����ֵ�ѧ��������ѧҵ��һ��ֻ֤(3n+1)������������˵����һ����ı�����������������ӻ�������ѧ���ѧ����еĽ�չ����

���ǽ������Ŀ����֤�������Ȳ��룬���ǶԸ�������һ������1000��������n���򵥵���һ�£���Ҫ���ٲ��������£����ܵõ�n=1��

�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ��

�����ʽ�������n���㵽1��Ҫ�Ĳ�����

����������
3
���������
5
*/
#include <stdio.h>
int main()
{
  int n,count=0;
  scanf("%d",&n);
  while(n!=1)
  {
    if(n%2!=0) n=3*n+1;
    n/=2;
    count++;
  }
  printf("%d",count);
  return 0;
}