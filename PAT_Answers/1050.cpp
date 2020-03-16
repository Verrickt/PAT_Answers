#include "string"
#include "iostream"
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int i = 0, j = 0;
	bool m[404]{ false };
	for (auto c : s2) m[c] = true;
	string res;
	for (auto c : s1) if (!m[c]) res.push_back(c);
	cout << res << endl;
	return 0;
}