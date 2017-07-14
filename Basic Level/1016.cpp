/*1016. 部分A+B (15)

正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 10^10。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0
*/
#include <stdio.h>
int main()
{
  long long A,B,PA=0,PB=0;
  int DA,DB;
  scanf("%lld%d%lld%d",&A,&DA,&B,&DB);
  while(A)
  {
    if(A%10==DA) PA=PA*10+DA;
    A/=10;
  }
  while(B)
  {
    if(B%10==DB) PB=PB*10+DB;
    B/=10;
  }
  printf("%lld",PA+PB);
  return 0;
}
