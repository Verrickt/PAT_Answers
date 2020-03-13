#include "cstdio"
#include "vector"
#include "algorithm"
using namespace std;
int cmax, n, sp, m;
int road[504][504];
int bikes[504];
vector<int> pre[504];
bool visited[504];
int est[504];
const int inf = 0x7FFFFFF;

int take_out = inf;
int take_back = inf;

vector<int> temp;
vector<int> ans;
void dfs(int source)
{
	if (source == 0)
	{
		int w = 0, hq = 0;
		for (auto it = temp.rbegin(); it != temp.rend(); it++)
		{
			int diff = bikes[*it] - cmax / 2;
			// take additional bikes
			if (diff >= 0) w += diff;
			else if (abs(diff) < w)
			{
				//Good. Our bikes at hands could fill the gap
				w -= abs(diff);
			}
			else
			{
				//Bad. We need bikes from PMSC
				hq += (abs(diff) - w);
				w = 0;
			}
		}
		if (hq < take_out || w < take_back)
		{
			take_out = hq;
			take_back = w;
			ans = temp;
		}
		return;
	}
	temp.push_back(source);
	for (int i = 0; i < pre[source].size(); i++)
	{
		dfs(pre[source][i]);
	}
	temp.pop_back();
}

int main()
{

	scanf("%d %d %d %d", &cmax, &n, &sp, &m);
	for (int i = 0; i < 504; i++) fill(road[i], road[i] + 504, inf);
	for (int i = 1; i <= n; i++) scanf("%d", &bikes[i]);
	for (int i = 0; i < m; i++)
	{
		int c1, c2, w;
		scanf("%d %d %d", &c1, &c2, &w);
		road[c1][c2] = road[c2][c1] = w;
	}
	{
		//dijkstra
		est[0] = 0;
		fill(&est[1], &est[504], inf);
		fill(visited, visited + n, false);
		while (true)
		{
			int mmin = inf, mindex = -1;
			for (int i = 0; i <= n; i++)
			{
				if (est[i] < mmin && !visited[i]) { mmin = est[i]; mindex = i; }
			}
			if (mindex == -1) break;
			visited[mindex] = true;
			for (int j = 0; j <= n; j++)
			{
				if (road[mindex][j] != inf && !visited[j])
				{
					if (est[mindex] + road[mindex][j] < est[j])
					{
						pre[j].clear();
						pre[j].push_back(mindex);
						est[j] = est[mindex] + road[mindex][j];
					}
					else if (est[mindex] + road[mindex][j] == est[j])
					{
						pre[j].push_back(mindex);
					}
				}
			}
		}
	}
	{
		//dfs
		dfs(sp);
	}
	{
		ans.push_back(0);
		printf("%d ", take_out);
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			printf("%d", ans[i]);
			if (i != 0)
				printf("->");
		}
		printf(" %d", take_back);
	}
	return 0;
}