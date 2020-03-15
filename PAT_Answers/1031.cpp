#include "string"
#include "vector"
#include "iostream"
using namespace std;
int main()
{
	string s;
	cin >> s;
	int n1=-1;
	for (int n2 = 3; n2 <= s.length(); n2++)
	{
		int nn1 = (s.length() + 2 - n2)/2;
		int nn3 = nn1;
		if (nn1 <= n2 && nn1 > n1) n1 = nn1;
	}
	int n3 = n1;
	int n2 = s.length() + 2 - n1 - n3;
	for (int i = 0; i < n1-1; i++)
	{
		printf("%c", s[i]);
		for(int i=0;i<n2-2;i++)
			printf(" ");
		printf("%c\n", s[s.length()-i-1]);
	}
	for (int i = 0; i < n2; i++)
	{
		printf("%c", s[i+n1-1]);
	}
	return 0;
}