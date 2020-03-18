#include "cstdio"
#include "set"
#include "vector"
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<set<int>> v;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int k, temp;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) 
		{
			scanf("%d", &temp);
			v[i].insert(temp);
		}
	}
	int k; scanf("%d", &k);
	for (int ii = 0; ii < k; ii++)
	{
		int i1, i2; 
		scanf("%d %d", &i1, &i2);
		auto s1 = v[i1], s2 = v[i2];
		int nc = 0;
		for (auto it : s1)
		{
			if (s2.find(it) != s2.end()) nc++;
		}
		int nt = s1.size() + s2.size() - nc;
		double f = ((double)nc / nt)*100;
		printf("%.1lf%%\n",f);
	}
	return 0;
}