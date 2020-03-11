#include "cstdio"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

struct node
{
	int expo;
	double cof;
};

bool cmp(node a, node b)
{
	return a.expo>b.expo;
}

int main()
{
	vector<node> v1;
	vector<node> v2;
	int n;
	cin >> n;
	v1.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v1[i].expo >> v1[i].cof;
	cin >> n;
	v2.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v2[i].expo >> v2[i].cof;
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	vector<node> v3;
	int i = 0;
	int j = 0;
	while (i < v1.size() && j < v2.size())
	{
		int cm = v1[i].expo - v2[j].expo;
		if (cm > 0) { v3.push_back(v1[i]); i++; }
		if (cm == 0)
		{
			v1[i].cof += v2[j].cof;
			if (v1[i].cof != 0) v3.push_back(v1[i]);
			i++; j++;
		}
		if (cm < 0) { v3.push_back(v2[j]); j++; }
	}
	while (i < v1.size()) { v3.push_back(v1[i]); i++; }
	while (j < v2.size()) { v3.push_back(v2[j]); j++; }
	printf("%d", v3.size());
	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		printf(" %d %.1lf", it->expo, it->cof);
	}
	return 0;
}