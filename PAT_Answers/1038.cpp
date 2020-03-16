#include "string"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
bool cmp(string s1, string s2)
{
	//sort by lexicographical order doesn't work here. 33<321,but 33321 > 32133. :-(
	//but we can throw the problem at cpp :-)
	auto p1 = s1;
	auto p2 = s2;
	return p1+p2 < p2+p1;
}
int main()
{
	int n;
	cin >> n;
	vector<string> v=vector<string>(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	string res;
	for (auto i : v) res.append(i);
	int i = 0; while (res[i] == '0') i++;
	res = res.substr(i);
	if (res.size() == 0) res = "0";
	cout << res << endl;
	return 0;
}