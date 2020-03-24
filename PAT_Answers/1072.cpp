#include "iostream"
#include "vector"
#include "cstdio"
#include "map"
#include "cctype"
#include "string"
#include "algorithm"
using namespace std;

int index = 0;
map<string, int> ma;
map<int, string> mi;
int s_to_i(string str)
{
	if (ma.find(str) == ma.end())
	{
		ma[str] = index;
		mi[index] = str;
		index++;
	}
	return ma[str];
}
string i_to_s(int i) { return mi[i]; }
int graph[1024][1024];
int n, m, k, ds;
const int inf = 0x7FFFFFF;

int main()
{
	cin >> n >> m >> k >> ds;

	for (int i = 0; i < k; i++)
	{
		string src, des; int len;
		cin >> src >> des >> len;
		int i1 = s_to_i(src), i2 = s_to_i(des);
		graph[i1][i2] = graph[i2][i1] = len;
	}
	double min_avg = inf;
	double min_max = -1;
	int ans = -1;
	int est[1024];
	bool visited[1024];
	for (int ii = 1; ii <= m; ii++)
	{
		fill(visited, visited + 1024, false);
		fill(est, est + 1024, inf);
		int src_index = s_to_i("G" + to_string(ii));
		est[src_index] = 0;
		while (true)
		{
			int src = -1, est_src = inf;
			for (int i = 0; i < m + n; i++)
			{
				if (est[i] < est_src && !visited[i]) { src = i; est_src = est[i]; }
			}
			if (src == -1) break;
			visited[src] = true;
			for (int i = 0; i < m + n; i++)
			{
				if (est[src] + graph[src][i] < est[i] && graph[src][i] != 0)
				{
					est[i] = est[src] + graph[src][i];
				}
			}
		}
		int sum = 0, max = -1, min = inf;
		for (int i = 1; i <= n; i++)
		{
			int node_index = s_to_i(to_string(i));
			if (est[node_index] != inf)
			{
				sum += est[node_index];
				if (max < est[node_index]) max = est[node_index];
				if (min > est[node_index]) min = est[node_index];
			}
		}
		if (max <= ds)
		{
			double d_avg = (double)sum / n;
			if (min > min_max)
			{
				min_avg = d_avg;
				min_max = min;
				ans = src_index;
			}
			else if (min == min_max)
				if (d_avg < min_avg)
				{
					min_avg = d_avg;
					ans = src_index;
				}
		}
	}
	if (ans == -1)
	{
		printf("No Solution\n");
		return 0;
	}
	else
	{
		cout << i_to_s(ans) << endl;
		printf("%.1lf %.1lf\n",min_max, min_avg);
		return 0;
	}
}