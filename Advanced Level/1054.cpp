/*1054. The Dominant Color (20)

Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color.
A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800x600), you are supposed to point out the strictly dominant color.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (<=800) and N (<=600) which are the resolutions of the image.
Then N lines follow, each contains M digital colors in the range [0, 2^24). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.

Output Specification:

For each test case, simply print the dominant color in a line.

Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24
*/
#include <stdio.h>
#include <map>
using namespace std;
map<int,int> count;
int main()
{
  int M,N;
  scanf("%d%d",&M,&N);
  for(int i=0;i<N;i++) for(int j=0;j<M;j++)
  {
    int temp;
    scanf("%d",&temp);
    if(count.find(temp)!=count.end()) count[temp]++;
    else count[temp]=1;
  }
  int max=0,index=0;
  for(map<int,int>::iterator it=count.begin();it!=count.end();it++) if(it->second>max)
  {
    max=it->second;
    index=it->first;
  }
  printf("%d\n",index);
  return 0;
}
