/*1014. ����Ħ˹��Լ�� (20)

����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm����
����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ�
��2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ�����������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ�
�ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��

������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����

�����ʽ��

��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣

����������
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
���������
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
