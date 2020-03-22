#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
#include "cctype"
using namespace std;
int main()
{
	string s;
	unordered_map<string, int> m;
	getline(cin, s);
	vector<char> v;
	for (auto p : s)
	{
		if (isalpha(p)) v.push_back(tolower(p));
		else if (isdigit(p)) v.push_back(p);
		else
		{
			if (v.size() != 0)
			{
				string str = string(v.begin(), v.end());
				m[str]++;
			}
			v.clear();
		}
	}
	if (v.size() != 0) { string str = string(v.begin(), v.end()); m[str]++; }

	string max; int cnt = -1;
	for (auto p : m)
	{
		if (p.second > cnt) { cnt = p.second; max = p.first; }
	}
	cout << max << " " << cnt << endl;
	return 0;
}
