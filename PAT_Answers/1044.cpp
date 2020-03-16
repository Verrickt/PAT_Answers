#include "vector"
#include "cstdio"
using namespace std;
vector<int> ans;
int mmin = 0xFFFFFFF;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> v = vector<int>(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int val;
		scanf("%d", &val);
		v[i] = v[i - 1] + val;
	}
	mmin = v[n];
	for (int i = 1; i <= n; i++)
	{
		int left = i;
		int right = n;
		int sum = 0;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (v[mid] - v[i-1] >= m) { right = mid; }
			else  { left = mid + 1; }
		}
		sum = v[right] - v[i-1];
		if (sum >= m)
		{
			if (sum < mmin)
			{
				mmin = sum;
				ans.clear();
			}
			if (sum == mmin)
			{
				ans.push_back(i);
				ans.push_back(right);
			}
		}
	}
	for (int i = 0; i < ans.size(); i += 2)
		printf("%d-%d\n", ans[i], ans[i + 1]);
	return 0;
}