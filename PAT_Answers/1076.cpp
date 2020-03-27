#include "iostream"
#include "algorithm"
#include "cstdio"
#include "queue"
using namespace std;
struct node
{
	int index;
	int level;
};
int n, l;
int graph[1024][1024];
bool visited[1024];
int bfs(int src)
{
	queue<node> q;
	q.push(node{ src,0 });
	visited[src] = true;
	int cnt = 0;
	while (!q.empty())
	{
		auto f = q.front();
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i] && graph[f.index][i] != 0)
			{
				node n = node{ i,f.level + 1 };
				if (n.level <= l)
				{
					q.push(n);
					visited[n.index] = true;
					cnt++;
				}
			}
		}
		q.pop();
	}
	return cnt;
}

int main()
{
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		int mi, ui;
		scanf("%d", &mi);
		for (int j = 0; j < mi; j++)
		{
			scanf("%d", &ui);
			graph[ui][i] = 1;
		}
	}
	int k;
	cin >> k;
	for (int iii = 0; iii < k; iii++)
	{
		fill(visited, visited + 1024, false);
		int j;
		scanf("%d", &j);
		auto cnt = bfs(j);
		printf("%d\n", cnt);
	}
	return 0;
}