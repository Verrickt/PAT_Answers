#include "string"
#include "iostream"
#include "cctype"
#include "cstdio"
using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);
	string a[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string b[13] = { "","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	for (int cnt = 0; cnt < n; cnt++)
	{
		string str;
		string ans;
		getline(cin, str);
		if (isdigit(str[0]))
		{
			auto i = stoi(str);
			if (i / 13 != 0) { ans = b[i / 13]; }
			if (ans.size() == 0) ans = a[i % 13];
			else ans += (i % 13 == 0 ? "" : " "+a[i % 13]);
		}
		else
		{
			auto s1 = str.size() > 4 ? str.substr(0, 3) : str;
			auto s2 = str.size() > 4 ? str.substr(4) : str;
			int i = 0, j = 0;
			for (i = 12; i >= 0; i--) if (b[i] == s1) break;
			for (j = 12; j >= 0; j--) if (a[j] == s2) break;
			i = i < 0 ? 0 : i; j = j < 0 ? 0 : j;
			ans = to_string((i * 13 + j));
		}
		cout << ans << endl;
	}
	return 0;
}