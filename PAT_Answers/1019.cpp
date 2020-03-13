#include "string"
#include "vector"
#include "iostream"
using namespace std;
int main()
{
	int n, b;
	cin >> n >> b;
	vector<int> v;
	int i = n;
	while (i != 0) { v.push_back(i % b); i /= b; }
	bool flag = true;
	for (int i = 0; i < v.size(); i++) flag = flag && (v[i] == v[v.size() - 1 - i]);
	cout << (flag ? "Yes" : "No") << endl;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i];
		if (i != 0) cout << " ";
	}
	return 0;
}