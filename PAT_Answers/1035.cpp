#include "iostream"
#include "cstdio"
#include "cstring"
#include "vector"
#include "map"
using namespace std;
struct node
{
	char name[20];
	char pass[20];
};
struct replace { char c; bool r; };
int cnt;
vector<node> v;
map<char, replace> m;
bool p(node& n)
{
	bool flg = false;
	for (int i = 0; i < strlen(n.pass); i++)
	{
		if (m[n.pass[i]].r == true)
		{
			n.pass[i] = m[n.pass[i]].c;
			flg = true;
		}
	}
	return flg;
}
int main()
{
	for (int i = 0; i < 400; i++) m[i] = replace({ (char)i, false });
	m['1'] = replace({ '@',true });
	m['0'] = replace({ '%',true });
	m['l'] = replace({ 'L',true });
	m['O'] = replace({ 'o',true });
	int n;
	cin >> n;
	v.resize(n);
	vector<node> r;
	for (int i = 0; i < n; i++) scanf("%s %s", &v[i].name, &v[i].pass);
	for (auto i : v) if (p(i)) r.push_back(i);
	if (r.size() == 0)
	{
		if (n > 1) cout << "There are "<<n<<" accounts and no account is modified" << endl;
		else cout << "There is 1 account and no account is modified" << endl;
	}
	else
	{
		cout << r.size() << endl;
		for (auto i : r) printf("%s %s\n", i.name, i.pass);
	}
	return 0;
}