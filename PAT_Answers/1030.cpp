#include "cstdio"
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int dist[504][504];
int cost[504][504];
int est[504];
bool visited[504];
int pre[504];
int curCost[504];
const int inf = 0x7FFFFFF;
int n, m, s, d;
void print(int i) 
{
	if (i != s)
	{
		print(pre[i]);
		printf("%d ",i);
	}
	else printf("%d ",i);
}
int main()
{
	cin >> n >> m >> s >> d;
	for (int i = 0; i < n; i++)
	{
		fill(dist[i], dist[i] + 504, inf);
		fill(cost[i], cost[i] + 504, inf);
	}
	for (int i = 0; i < m; i++)
	{
		int	c1, c2, dis, cos;
		cin >> c1 >> c2 >> dis >> cos;
		dist[c1][c2] = dist[c2][c1] = dis;
		cost[c1][c2] = cost[c2][c1] = cos;
	}
	{
		//dijkstra
		fill(est, est + n, inf);
		curCost[s] = 0;
		est[s] = 0;
		while (true)
		{
			int mmin = inf;
			int mindex = -1;
			for (int i = 0; i < n; i++)
			{
				if (est[i] < mmin && !visited[i])
				{
					mmin = est[i];
					mindex = i;
				}
			}
			if (mindex == -1) break;
			visited[mindex] = true;
			for (int i = 0; i < n; i++)
			{
				if (est[mindex] + dist[mindex][i] < est[i])
				{
					est[i] =est[mindex] + dist[mindex][i];
					curCost[i] = curCost[mindex] + cost[mindex][i];
					pre[i] = mindex;
				}
				else if (est[mindex] + dist[mindex][i] == est[i])
				{
					if (curCost[mindex] + cost[mindex][i] < curCost[i])
					{
						curCost[i] = curCost[mindex] + cost[mindex][i];
						pre[i] = mindex;
					}
				}
			}
		}
	}
	print(d);
	printf("%d %d",est[d],curCost[d]);
	return 0;
}