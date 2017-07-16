/*1031. Hello World for U (20)

Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:

h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters,
and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
(n1==n3;n1<=n2;n1 ALAP)
Input Specification:

Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

Output Specification:

For each test case, print the input string in the shape of U as specified in the description.

Sample Input:
helloworld!
Sample Output:
h   !
e   d
l   l
lowor
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int len;
  char c[100];
  gets(c);
  len=strlen(c);
  int row=(len+2)/3;
  for(int i=1;i<row;i++)
  {
    printf("%c",c[i-1]);
    for(int j=2;j<=len-2*row+1;j++) printf(" ");
    printf("%c\n",c[len-i]);
  }
  for(int j=1;j<=len-2*row+2;j++) printf("%c",c[row+j-2]);
  return 0;
}
