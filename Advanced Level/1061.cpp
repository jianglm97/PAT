/*1061. Dating (20)

Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:

For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
Sample Output:
THU 14:04
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
  int i,j;
  char str[5][80],day[10][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
  for(i=0;i<4;i++) gets(str[i]);
  for(i=0;i<min(strlen(str[0]),strlen(str[1]));i++) if(str[0][i]==str[1][i]&&str[0][i]>='A'&&str[0][i]<='G') break;
  printf("%s ",day[str[0][i]-'A']);
  for(j=i+1;j<min(strlen(str[0]),strlen(str[1]));j++) if(str[0][j]==str[1][j]&&((str[0][j]>='A'&&str[0][j]<='N')||(str[0][j]>='0'&&str[0][j]<='9'))) break;
  printf("%02d:",str[0][j]<='9'?str[0][j]-'0':str[0][j]-'A'+10);
  for(i=0;i<min(strlen(str[2]),strlen(str[3]));i++) if(str[2][i]==str[3][i]&&((str[2][i]>='a'&&str[2][i]<='z')||(str[2][i]>='A'&&str[2][i]<='Z'))) break;
  printf("%02d",i);
  return 0;
}
