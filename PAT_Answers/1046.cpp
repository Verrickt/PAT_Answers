#include "iostream"
#include "vector"
using namespace std;
int main()
{
	int n;
	cin >> n;
	auto v = vector<int>(n + 2);
	for (int i = 2; i <= n+1; i++)
	{
		cin >> v[i];
		v[i] += v[i - 1];
	}
	int k;
	cin >> k;
	while (k > 0)
	{
		int c1, c2;
		cin >> c1 >> c2;
		if (c1>c2) swap(c1, c2);
		int t1 = v[c2] - v[c1];
		int t2 = v[n+1] - t1;
		cout << (t1 < t2 ? t1 : t2) << endl;
		k--;
	}
	return 0;
}