#include "cstdio"
#include "vector"
#include "algorithm"
#include "set"
using namespace std;
int graph[10086][10086];
int n;
int max_depth = -1;
vector<int> roots;
set<int> ans = set<int>();
bool visited[10086];
void dfs(int source, int depth)
{
	visited[source] = true;
	if (depth > max_depth)
	{
		max_depth = depth;
		roots.clear();
	}
	if (depth == max_depth) roots.push_back(source);
	for (int i = 1; i <= n; i++)
		if (graph[source][i] == 1 && !visited[i])
			dfs(i, depth + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int j, k;
		scanf("%d %d", &j, &k);
		graph[j][k] = graph[k][j] = 1;
	}
	fill(visited, visited + 10086, false);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i]) { dfs(i, 0); cnt++; }
	}
	if (cnt != 1) { printf("Error: %d components\n", cnt); return 0; }
	for (auto i : roots) ans.insert(i);
	fill(visited, visited + 10086, false);
	dfs(roots[0], 0);
	for (auto i : roots) ans.insert(i);
	for (auto i : ans) printf("%d\n", i);
	return 0;
}