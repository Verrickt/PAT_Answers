#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int k;
	cin >> k;
	vector<int> v = vector<int>(k);
	for (int i = 0; i < k; i++) scanf("%d", &v[i]);
	int i=0, sum = 0;
	int max = -1;
	sum = 0;
	int p = 0, q = k-1;
	int s = 0;
	for(int i=0;i<k;i++)
	{
		sum += v[i];
		if (sum>max)
		{
			max = sum;
			p = s;
			q = i;
		}
		if (sum<0)
		{
			s = i+1;
			sum = 0;
		}
	}
	if (max < 0) max = 0;
	printf("%d %d %d", max, v[p], v[q]);
	return 0;
}