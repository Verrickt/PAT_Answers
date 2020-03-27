#include "iostream"
#include "vector"
#include "cmath"
using namespace std;
struct node
{
	vector<int> children;
	int volume;
	int level;
};
vector<node> nodes;
bool visited[100086];
int n; double p, r;
void dfs(int index, int level)
{
	if (!visited[index])
	{
		visited[index] = true;
		nodes[index].level = level;
		for (auto p : nodes[index].children)
			dfs(p, level + 1);
	}
}
int main()
{
	cin >> n >> p >> r;
	fill(visited, visited + n, false);
	nodes.resize(n);
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		if (c > 0)
		{
			nodes[i].children.resize(c);
			for (int j = 0; j < c; j++)
				cin >> nodes[i].children[j];
		}
		else
			cin >> nodes[i].volume;
	}
	dfs(0, 0);
	double sale = 0;
	for (auto node : nodes)
		if (node.children.size() == 0)
			sale += pow(1 + r / 100, node.level) * node.volume * p;
	printf("%.1lf", sale);
	return 0;
}