#include "cstdio"
#include "vector"
#include "iostream"
#include "string"
using namespace std;
bool prime[100005];

int reverse(int i, int radex)
{
	vector<int> v;
	while (i!=0)
	{
		v.push_back(i % radex);
		i /= radex;
	}
	int r = 0;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		r *= radex;
		r += *it;
	}
	return r;
}

int main()
{
	fill(&prime[2], &prime[100005], true);
	for (int i = 2; i < 100005; i++)
	{
		for (int j = 2; i * j < 100005; j++)
			prime[i * j] = false;
	}
	int n, d;
	while (true)
	{
		cin >> n;
		if (n > 0)
		{
			cin >> d;
			if (prime[n] && prime[reverse(n, d)]) printf("Yes\n");
			else printf("No\n");

		}
		else
			return 0;
	}
}