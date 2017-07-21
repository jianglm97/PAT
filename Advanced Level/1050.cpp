/*1050. String Subtraction (20)

Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.

Input Specification:

Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 10^4.
It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:

For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/
#include <stdio.h>
#include <string.h>
int main()
{
  bool hashTable[200]={false};
  char str1[10010],str2[10010];
  gets(str1);
  gets(str2);
  int len1=strlen(str1);
  int len2=strlen(str2);
  for(int i=0;i<len2;i++) hashTable[str2[i]]=true;
  for(int i=0;i<len1;i++) if(hashTable[str1[i]]!=true) printf("%c",str1[i]);
  return 0;
}
