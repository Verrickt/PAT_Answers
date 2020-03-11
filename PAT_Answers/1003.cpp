#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 0xFFFFFFF;
int n, m, c1, c2;
int cost[504][504];
int people[504];

int est[504];
bool visited[504];

int roads[504];
int rescue[504];
int main()
{
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < 504; i++)
		fill(&cost[i][0], &cost[i][503], inf);
	for (int i = 0; i < n; i++) scanf("%d", &people[i]);
	for (int i = 0; i < m; i++)
	{
		int s, d, l;
		scanf("%d %d %d", &s, &d, &l);
		cost[s][d] = cost[d][s] = l;
	}
	//dijkstra here
	{
		fill(est, est + 504, inf);
		fill(visited, visited + 504, false);
		est[c1] = 0;
		roads[c1] = 1;
		rescue[c1] = people[c1];
		while (true)
		{
			int mmin = inf;
			int ind = -1;
			for (int i = 0; i < n; i++)
			{
				if (est[i] < mmin && !visited[i]) { mmin = est[i]; ind = i; }
			}
			if (ind == -1) break;
			visited[ind] = true;
			for (int j = 0; j < n; j++)
			{
				if (est[ind] + cost[ind][j] < est[j])
				{
					est[j] = est[ind] + cost[ind][j];
					roads[j] = roads[ind];
					//rescue[j]: the maximum number of rescue available from
					//c1 to j;
					rescue[j] = rescue[ind] + people[j];
				}
				else if (est[ind] + cost[ind][j] == est[j])
				{
					roads[j] += roads[ind];
					if (rescue[ind] + people[j] > rescue[j])
					{
						//more rescue
						rescue[j] = rescue[ind] + people[j];
					}
				}
			}
		}
	}

	printf("%d %d", roads[c2],rescue[c2]);
	return 0;
}