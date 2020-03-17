#include "cstdio"
#include "map"
#include "iostream"
using namespace std;
int main()
{
	map<int, int> map;
	int n, m;
	cin >> m >> n;
	for(int ii=0;ii<n;ii++)
		for (int jj = 0; jj < m; jj++)
		{
			int c;
			scanf("%d", &c);
			map[c]++;
		}
	int max = -1;
	int ans = 0;
	for (auto it : map)
	{
		if (it.second > max) { max = it.second; ans = it.first; }
	}
	cout << ans << endl;
	return 0;
}