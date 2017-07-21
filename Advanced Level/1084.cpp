/*1084. Broken Keyboard (20)

On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string.
Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI
*/
#include <stdio.h>
#include <string.h>
int main()
{
  int hashTable[200]={0};
  char str1[100],str2[100];
  gets(str1);
  for(int i=0;i<strlen(str1);i++) hashTable[str1[i]]++;
  gets(str2);
  for(int i=0;i<strlen(str2);i++) hashTable[str2[i]]--;
  for(int i=0;i<strlen(str1);i++)
  {
    if(hashTable[str1[i]]!=0)
    {
      if(str1[i]<='z'&&str1[i]>='a') printf("%c",str1[i]-32);
      else printf("%c",str1[i]);
      hashTable[str1[i]]=0;
      if(str1[i]<='z'&&str1[i]>='a') hashTable[str1[i]-32]=0;
      if(str1[i]<='Z'&&str1[i]>='A') hashTable[str1[i]+32]=0;
    }
  }
  return 0;
}
