/*1093. Count PAT's (25)

The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:

Each input file contains one test case. For each case, there is only one line giving a string of no more than 105 characters containing only P, A, or T.

Output Specification:

For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

Sample Input:
APPAPT
Sample Output:
2
*/
#include <cstdio>
#include <cstring>
int main()
{
  int leftNumP[100010],rightNumT=0,sum=0;
  char str[100010];
  gets(str);
  int len=strlen(str);
  if(str[0]=='P') leftNumP[0]=1;
  else leftNumP[0]=0;
  for(int i=1;i<len;i++)
  {
    if(str[i]=='P') leftNumP[i]=leftNumP[i-1]+1;
    else leftNumP[i]=leftNumP[i-1];
  }
  for(int i=len-1;i>=0;i--)
  {
    if(str[i]=='T') rightNumT++;
    if(str[i]=='A') sum=(sum+leftNumP[i]*rightNumT)%1000000007;
  }
  printf("%d",sum);
  return 0;
}
