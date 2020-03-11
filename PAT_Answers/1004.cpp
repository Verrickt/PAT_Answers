#include "cstdio"
#include "vector"
#include "queue"
using namespace std;
struct node
{
	vector<int> children;
	int level = 1;
};
int main()
{
	{
		node nodes[104];
		vector<int> v;
		int m, n;
		scanf("%d %d", &n, &m);
		if (n == 0)
		{
			return 0;
		}
		for (size_t i = 0; i < m; i++)
		{
			int id, k;
			scanf("%d %d", &id, &k);
			nodes[id].children.resize(k);
			for (int j = 0; j < k; j++)
			{
				scanf("%d", &nodes[id].children[j]);
			}
		}
		{
			int curLevel = 1;
			int curOrphan = 0;
			queue<node> q;
			q.push(nodes[1]);
			while (!q.empty())
			{
				auto cur = q.front();
				for (int i = 0; i < cur.children.size(); i++)
				{
					nodes[cur.children[i]].level = cur.level + 1;
					q.push(nodes[cur.children[i]]);
				}
				if (curLevel != cur.level)
				{
					curLevel = cur.level;
					v.push_back(curOrphan);
					curOrphan = 0;
				}
				if (cur.children.size() == 0) curOrphan += 1;
				q.pop();
			}
			v.push_back(curOrphan);
		}
		for (int i = 0; i < v.size(); i++)
		{
			printf("%d", v[i]);
			if (i + 1 != v.size()) printf(" ");
		}
		return 0;
	}
}