/*1022. D进制的A+B (20)

输入两个非负10进制整数A和B(<=2^30-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：

输入在一行中依次给出3个整数A、B和D。

输出格式：

输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
1103
*/
#include <stdio.h>
int main()
{
  int A,B,D,a[50],num=0;
  scanf("%d%d%d",&A,&B,&D);
  long long ans=A+B;
  do
  {
    a[num++]=ans%D;
    ans/=D;
  }
  while(ans!=0);
  for(int i=num-1;i>=0;i--) printf("%d",a[i]);
  return 0;
}
