#include "cstdio"
#include "algorithm"
#include "queue"
using namespace std;
int poi;
bool road[1004][1004];
bool visited[1004];
int n, m, k;
void bfs(int i)
{
	queue<int> q;
	if (visited[i]||i==poi) return;
	q.push(i);
	visited[i] = true;
	while (!q.empty())
	{
		int t = q.front();
		for (int cur = 0; cur < 1004; cur++)
		{
			if (road[t][cur]&&!visited[cur]&&cur!=poi)
			{
				q.push(cur);
				visited[cur] = true;
			}
		}
		q.pop();
	}
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int d1, d2;
		scanf("%d %d", &d1, &d2);
		road[d1][d2] = road[d2][d1] = true;
	}
	for (int qq = 0; qq < k; qq++)
	{
		fill(&visited[0], &visited[1004], false);
		scanf("%d", &poi);
		visited[poi] = true;
		int k = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				bfs(i);
				k++;
			}
		}
		printf("%d\n", k-1);
	}
	return 0;
}