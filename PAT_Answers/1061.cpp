#include "cstdio"
#include "iostream"
#include "string"
#include "cctype"
using namespace std;
int main() 
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int d = -1, h = -1;
	string days[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	for (int i = 0; i < s2.length()&&i<s1.length(); i++)
	{
		if (s1[i] == s2[i])
		{
			if (d == -1 && s1[i]>='A'&&s1[i]<='G') 
			{ 
				d = s1[i] - 'A'; continue; 
			}
			if (d!=-1&&(isdigit(s1[i])|| s1[i] >= 'A' && s1[i] <= 'N'))
			{
				h = isdigit(s1[i]) ? s1[i] - '0' : s1[i] - 'A' + 10;
				break;
			}
		}
	}
	int m;
	for (int i = 0; i < s3.length() && i < s4.length(); i++)
	{
		if (s3[i] == s4[i]&&isalpha(s3[i])) { m = i; break; }
	}
	printf("%s %02d:%02d\n", days[d].c_str(), h, m);
	return 0;
}