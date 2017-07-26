/*1034. 有理数四则运算(20)

本题要求编写程序，计算2个有理数的和、差、积、商。

输入格式：

输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。

输出格式：

分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式“k a/b”，其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；若除法分母为0，则输出“Inf”。
题目保证正确的输出中没有超过整型范围的整数。

输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b)
{
  if(b==0) return a;
  else return gcd(b,a%b);
}
struct Fraction
{
  LL up,down;
}f1,f2,result;
Fraction reduction(Fraction result)
{
  if(result.down<0)
  {
    result.up=-result.up;
    result.down=-result.down;
  }
  if(result.up==0) result.down=1;
  else
  {
    LL d=gcd(abs(result.up),abs(result.down));
    result.up/=d;
    result.down/=d;
  }
  return result;
}
Fraction add(Fraction f1,Fraction f2)
{
  Fraction result;
  result.up=f1.up*f2.down+f2.up*f1.down;
  result.down=f1.down*f2.down;
  return reduction(result);
}
Fraction minu(Fraction f1,Fraction f2)
{
  Fraction result;
  result.up=f1.up*f2.down-f2.up*f1.down;
  result.down=f1.down*f2.down;
  return reduction(result);
}
Fraction multi(Fraction f1,Fraction f2)
{
  Fraction result;
  result.up=f1.up*f2.up;
  result.down=f1.down*f2.down;
  return reduction(result);
}
Fraction divide(Fraction f1,Fraction f2)
{
  Fraction result;
  result.up=f1.up*f2.down;
  result.down=f1.down*f2.up;
  return reduction(result);
}
void showResult(Fraction r)
{
  r=reduction(r);
  if(r.down==1)
  {
  if(r.up>=0) printf("%lld",r.up);
  else printf("(%lld)",r.up);
  }
  else if(abs(r.up)>r.down)
  {
    if(r.up/r.down>=0) printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
    else printf("(%lld %lld/%lld)",r.up/r.down,abs(r.up)%r.down,r.down);
  }
  else
  {
    if(r.up>=0) printf("%lld/%lld",r.up,r.down);
    else printf("(%lld/%lld)",r.up,r.down);
  }
}
int main()
{
  scanf("%lld/%lld %lld/%lld",&f1.up,&f1.down,&f2.up,&f2.down);
  result=add(f1,f2);
  showResult(f1);
  printf(" + ");
  showResult(f2);
  printf(" = ");
  showResult(result);
  printf("\n");
  result=minu(f1,f2);
  showResult(f1);
  printf(" - ");
  showResult(f2);
  printf(" = ");
  showResult(result);
  printf("\n");
  result=multi(f1,f2);
  showResult(f1);
  printf(" * ");
  showResult(f2);
  printf(" = ");
  showResult(result);
  printf("\n");
  result=divide(f1,f2);
  showResult(f1);
  printf(" / ");
  showResult(f2);
  printf(" = ");
  if(f2.up!=0) showResult(result);
  else printf("Inf");
  printf("\n");
  return 0;
}
