#include "cstdio"
#include "vector"
#include "algorithm"
using namespace std;
bool cmp1(long int a, long int b)
{
	return a < b;
}
int main()
{
	int m, n;
	scanf("%d", &m);
	vector<long> v1 = vector<long>(m);
	for (int i = 0; i < m; i++) scanf("%ld", &v1[i]);
	scanf("%d", &n);
	v1.resize(m + n);
	for (int i = 0; i < n; i++) scanf("%ld", &v1[i+m]);
	sort(v1.begin(), v1.end(),cmp1);
	printf("%ld", v1[v1.size() / 2]);
	return 0;
}