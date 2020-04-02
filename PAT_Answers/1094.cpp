#include "iostream"
#include "vector"
#include "map"
using namespace std;
int n, m;
struct node
{
	int level=0;
	vector<int> children;
};
vector<node> nodes;
map<int, int> ma;
void dfs(int id, int level)
{
	nodes[id].level = level;
	for (auto c : nodes[id].children)
		dfs(c, level + 1);
}
int main()
{
	cin >> n >> m;
	nodes = vector<node>(n+1);
	for (int i = 0; i < m; i++)
	{
		int id, num;
		cin >> id >> num;
		nodes[id].children.resize(num);
		for (int j = 0; j < num; j++) cin >> nodes[id].children[j];
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
		ma[nodes[i].level]++;
	int max_g = -1, max_p = -1;
	for (auto it = ma.begin(); it != ma.end(); it++)
		if (it->second > max_p) { max_p = it->second; max_g = it->first; }
	cout << max_p << " " << max_g << endl;
	return 0;
}