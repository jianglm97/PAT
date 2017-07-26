/*1023. Have Fun with Numbers (20)

Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication.
Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/
#include <stdio.h>
#include <string.h>
struct bign
{
  int d[30];
  int len;
  bign()
  {
    memset(d,0,sizeof(d));
    len=0;
  }
};
bign change(char str[])
{
  bign a;
  a.len=strlen(str);
  for(int i=0;i<a.len;i++) a.d[i]=str[a.len-i-1]-'0';
  return a;
}
bool compare(bign a,bign b)
{
  if(a.len!=b.len) return false;
  int count[10]={0};
  for(int i=0;i<a.len;i++)
  {
    count[a.d[i]]++;
    count[b.d[i]]--;
  }
  for(int i=0;i<10;i++) if(count[i]!=0) return false;
  return true;
}
bign multi(bign a,int b)
{
  bign c;
  int carry=0;
  for(int i=0;i<a.len;i++)
  {
    int temp=a.d[i]*b+carry;
    c.d[c.len++]=temp%10;
    carry=temp/10;
  }
  while(carry!=0)
  {
    c.d[c.len++]=carry%10;
    carry/=10;
  }
  return c;
}
void print(bign a)
{
  for(int i=a.len-1;i>=0;i--) printf("%d",a.d[i]);
}
int main()
{
  char str[30];
  gets(str);
  bign a=change(str);
  bign b=multi(a,2);
  if(compare(a,b)==true) printf("Yes\n");
  else printf("No\n");
  print(b);
  return 0;
}
