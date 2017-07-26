/*1034. ��������������(20)

����Ҫ���д���򣬼���2���������ĺ͡�������̡�

�����ʽ��

������һ���а��ա�a1/b1 a2/b2���ĸ�ʽ��������������ʽ�������������з��Ӻͷ�ĸȫ�����ͷ�Χ�ڵ�����������ֻ���ܳ����ڷ���ǰ����ĸ��Ϊ0��

�����ʽ��

�ֱ���4���а��ա�������1 ����� ������2 = ������ĸ�ʽ˳�����2���������ĺ͡�������̡�ע�������ÿ�������������Ǹ��������������ʽ��k a/b��������k���������֣�a/b�����������֣���Ϊ��������������ţ���������ĸΪ0���������Inf����
��Ŀ��֤��ȷ�������û�г������ͷ�Χ��������

��������1��
2/3 -4/2
�������1��
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
��������2��
5/3 0/6
�������2��
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
