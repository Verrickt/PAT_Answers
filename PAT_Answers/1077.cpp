#include "string"
#include "iostream"
#include "vector"
using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);
	vector<string> s = vector <string>(n);
	vector<string> si = vector<string>(n);
	string ans;
	int min_len = 0x7FFFFFF;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s[i]);
		min_len = min_len < s[i].length() ? min_len : s[i].length();
		for (auto it = s[i].rbegin(); it != s[i].rend(); it++)
			si[i].push_back(*it);
	}
	int i = 0;
	while (i < min_len)
	{
		bool flag = true;
		for (int j = 1; j < n; j++)
			if (si[j][i] != si[0][i]) flag = false;
		if (flag) ans.insert(ans.begin(), si[0][i]);
		else break;
		i++;
	}
	if (ans.length() == 0) ans = "nai";
	cout << ans << endl;
	return 0;
}