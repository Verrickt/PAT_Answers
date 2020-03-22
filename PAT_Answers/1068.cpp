#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;
vector<int> v;
vector<int> ans;
vector<int> temp;
int n, m;
int k = 0;
bool dfs(int index, int val)
{
	if (index >= n) return false;
	temp.push_back(v[index]);
	val -= v[index];
	if (val > 0)
		for (int i = 1; index + i <= k; i++)
		{
			if (dfs(index + i, val)) return true;
		}
	else if (val == 0)
	{
		ans = temp;
		return true;
	}
	temp.pop_back();
	return false;
}
int main()
{
	bool res = false;
	cin >> n >> m;
	v.resize(n);
	int sum = 0;
	for (int i = 0; i < n; i++) { cin >> v[i]; sum += v[i]; }
	if (sum >= m)
	{
		sort(v.begin(), v.end());
		k = n;
		for (int i = 0; i < n; i++)
			if (v[i] > m)
			{
				k = i;
				break;
			}
		for (int i = 0; i < k; i++) if (dfs(i, m)) break;
	}
	if (ans.size() == 0) cout << "No Solution" << endl;
	else
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i];
			if (i + 1 != ans.size()) cout << " ";
		}
	return 0;
}