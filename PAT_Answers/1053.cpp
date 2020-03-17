#include "iostream"
#include "vector"
#include "cstdio"
#include "algorithm"
using namespace std;
struct node
{
	int id;
	int weight;
	vector<int> child;
};
int n, m, s;
vector<node> nodes;
vector<int> path;
bool cmp(int n1, int n2) { return nodes[n1].weight > nodes[n2].weight; }
void print()
{
	for (int i = 0; i < path.size(); i++)
	{
		printf("%d", nodes[path[i]].weight);
		if (i + 1 != path.size()) printf(" ");
	}
	cout << endl;
}
void dfs(int root, int weight)
{
	path.push_back(root);
	weight += nodes[root].weight;
	if (weight == s && nodes[root].child.size() == 0) print();
	else if (weight < s) for (auto c : nodes[root].child) dfs(c, weight);
	path.pop_back();
}

int main()
{
	cin >> n >> m >> s;
	nodes.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &nodes[i].weight);
	for (int i = 0; i < m; i++)
	{
		int id, k;
		cin >> id >> k;
		nodes[id].child.resize(k);
		for (int j = 0; j < k; j++) scanf("%d", &nodes[id].child[j]);
		sort(nodes[id].child.begin(), nodes[id].child.end(), cmp);
	}
	dfs(0, 0);
	return 0;
}