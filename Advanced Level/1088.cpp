/*1088. Rational Arithmetic (20)

For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int.
If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result".
Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.

Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
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
