/*1071. Speech Patterns (25)

People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops".
Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

Input Specification:

Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return '\n'.
The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].

Output Specification:

For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input.
If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case.
Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.

Note that words are case insensitive.

Sample Input:
Can1: "Can a can can a can?  It can!"
Sample Output:
can 5
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> count;
bool check(char c)
{
  if(c>='0'&&c<='9') return true;
  if(c>='a'&&c<='z') return true;
  if(c>='A'&&c<='Z') return true;
  return false;
}
int main()
{
  string str;
  int i=0;
  getline(cin,str);
  while(i<str.length())
  {
    string word;
    while(i<str.length()&&check(str[i])==true)
    {
      if(str[i]>='A'&&str[i]<='Z') str[i]+=32;
      word+=str[i];
      i++;
    }
    if(word!="")
    {
      if(count.find(word)==count.end()) count[word]=1;
      else count[word]++;
    }
    while(i<str.length()&&check(str[i])==false) i++;
  }
  string ans;
  int max=0;
  for(map<string,int>::iterator it=count.begin();it!=count.end();it++) if(it->second>max)
  {
    max=it->second;
    ans=it->first;
  }
  cout<<ans<<" "<<max<<endl;
  return 0;
}
