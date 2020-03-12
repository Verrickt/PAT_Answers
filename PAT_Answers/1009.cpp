#include "cstdio"
#include "vector"
#include "algorithm"
using namespace std;
struct poly
{
	int expo;
	double cof;
};
bool cmp(poly p1, poly p2) { return p1.expo > p2.expo; }
int main()
{
	int k;
	scanf("%d", &k);
	vector<poly> p1 = vector<poly>(k);
	for (int i = 0; i < k; i++) scanf("%d %lf", &p1[i].expo, &p1[i].cof);
	scanf("%d", &k);
	vector<poly> p2 = vector<poly>(k);
	for (int i = 0; i < k; i++) scanf("%d %lf", &p2[i].expo, &p2[i].cof);
	vector<poly> p3;
	for (int i = 0; i < p1.size(); i++)
		for (int j = 0; j < p2.size(); j++)
			if (p1[i].cof * p2[j].cof != 0)
				p3.push_back(poly{ p1[i].expo + p2[j].expo,p1[i].cof * p2[j].cof });
	sort(p3.begin(), p3.end(), cmp);

	//inplace acc
	vector<poly> result;
	result.push_back(p3.front());
	for (int i = 1; i < p3.size(); i++)
	{
		if (p3[i].expo == p3[i - 1].expo)
		{
			if (result.empty()) result.push_back(p3[i]);
			result.back().cof += p3[i].cof;
			if (result.back().cof == 0) result.pop_back();
		}
		else
		{
			result.push_back(p3[i]);
		}
	}
	if (result.size() == 0) printf("0");
	else {
		printf("%d ", result.size());
		for (int i = 0; i < result.size(); i++)
		{
			printf("%d %.1lf", result[i].expo, result[i].cof);
			if (i + 1 != result.size()) printf(" ");
		}
	}
	return 0;
}