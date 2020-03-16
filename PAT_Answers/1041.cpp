#include "vector"
#include "cstdio"
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> l = vector<int>(n);
	vector<int> v = vector<int>(100005);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &l[i]);
		v[l[i]]++;
	}
	for (auto i : l)
	{
		if (v[i] == 1)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("None");
	return 0;
}