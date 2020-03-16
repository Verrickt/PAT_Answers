#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	auto v = vector<int>(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	while (i<j)
	{
		int sum = v[i] + v[j];
		if (sum > m) j--;
		else if (sum < m) i++;
		else break;
	}
	if (i < j) cout << v[i] << " " << v[j] << endl;
	else cout << "No Solution" << endl;
	return 0;
}