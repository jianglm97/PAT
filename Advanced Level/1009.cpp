/*1009. Product of Polynomials (25)

This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK,
where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/
#include <stdio.h>
int main()
{
  double a[1020]={0},b[1020]={0},ans[2020]={0},coe;
  int K1,K2,exp,count=0;
  scanf("%d",&K1);
  for(int i=0;i<K1;i++)
  {
    scanf("%d %lf",&exp,&coe);
    a[exp]=coe;
  }
  scanf("%d",&K2);
  for(int i=0;i<K2;i++)
  {
    scanf("%d %lf",&exp,&coe);
    b[exp]=coe;
  }
  for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) ans[i+j]+=a[i]*b[j];
  for(int i=0;i<=2000;i++) if(ans[i]!=0) count++;
  printf("%d",count);
  for(int i=2000;i>=0;i--) if(ans[i]!=0) printf(" %d %.1lf",i,ans[i]);
  return 0;
}
