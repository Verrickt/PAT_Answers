#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
bool cmp(long long a, long long b) { return abs(a) > abs(b); }
int main()
{
	vector<long long> c1, c2, p1, p2;
	int nc, np;
	cin >> nc;
	for (int i = 0; i < nc; i++)
	{
		long long n;
		cin >> n;
		if (n > 0) c1.push_back(n); else c2.push_back(n);
	}
	cin >> np;
	for (int i = 0; i < np; i++)
	{
		long long n;
		cin >> n;
		if (n > 0) p1.push_back(n); else p2.push_back(n);
	}
	sort(c1.begin(), c1.end(), cmp);
	sort(c2.begin(), c2.end(), cmp);
	sort(p1.begin(), p1.end(), cmp);
	sort(p2.begin(), p2.end(), cmp);
	long long val = 0;
	int i = 0,j = 0;
	while (i < c1.size() && j < p1.size())
	{
		if (c1[i] * p1[j] < 0) break;
		val += abs(c1[i] * p1[j]);
		i++;
		j++;
	}
	i = 0; j = 0;
	while (i < c2.size() && j < p2.size())
	{
		if (c2[i] * p2[j] < 0) break;
		val += abs(c2[i] * p2[j]);
		i++;
		j++;
	}
	cout << abs(val) << endl;
	return 0;
}