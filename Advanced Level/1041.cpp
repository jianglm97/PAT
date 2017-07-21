/*1041. Be Unique (20)

Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1, 10^4]. The first one who bets on a unique number wins.
For example, if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.

Input Specification:

Each input file contains one test case. Each case contains a line which begins with a positive integer N (<=10^5) and then followed by N bets. The numbers are separated by a space.

Output Specification:

For each test case, print the winning number in a line. If there is no winner, print "None" instead.

Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None
*/
#include <stdio.h>
int main()
{
  int N,hashTable[100010]={0},num[100010];
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d",&num[i]);
    hashTable[num[i]]++;
  }
  int j;
  for(j=0;j<N;j++) if(hashTable[num[j]]==1) break;
  if(j==N) printf("None");
  else printf("%d",num[j]);
  return 0;
}
