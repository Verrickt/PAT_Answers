#include "string"
#include "vector"
#include "iostream"
using namespace std;
bool dp[1005][1005];
int main()
{
	string str;
	getline(cin, str);
	int n = str.length();
	int len = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = true;
		if (i < n - 1 && str[i] == str[i + 1])
		{
			dp[i][i + 1] = true;
			len = 2;
		}
	}
	for (int l = 3; l <= n; l++)
	{
		for (int i = 0; i + l - 1 < n; i++)
		{
			int j = i + l - 1;
			if (str[i] == str[j] && dp[i + 1][j - 1])
			{
				dp[i][j] = true;
				len = l;
			}
		}
	}
	printf("%d", len);
	return 0;
}