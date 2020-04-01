#include "iostream"
#include "vector"
#include "cmath"
using namespace std;
struct node
{
	int level;
	vector<int> children;
	int index;
};
int n; double p, r;
vector<node> nodes;
vector<int> ans;
int max_level = -1;
void dfs(int source, int level)
{
	nodes[source].level = level;
	if (level > max_level) { max_level = level; ans.clear(); }
	if (level == max_level) ans.push_back(source);
	for (auto p : nodes[source].children)
		dfs(p, level + 1);
}
int main()
{
	cin >> n >> p >> r;
	nodes = vector<node>(n);
	int root = -1;
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		if (parent == -1) { root = i; continue; }
		nodes[parent].children.push_back(i);
	}
	dfs(root, 0);
	double max_price = p * pow((1 + r / 100), max_level);
	printf("%.2lf %d", max_price, ans.size());
	return 0;
}