#include "string"
#include "iostream"
#include "algorithm"
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int a1[1024], a2[1024];
	fill(a1, a1 + 1024, 0); fill(a2, a2 + 1024, 0);
	for (auto i : s1) a1[i]++;
	for (auto i : s2) a2[i]++;
	bool flag = true; int diff=0;
	for (int i = 0; i < 1024; i++)
	{
		if (a2[i] > a1[i]) { flag = false; diff += (a2[i] - a1[i]); }
	}
	printf("%s %d", flag ? "Yes" : "No", flag ? s1.size() - s2.size() : diff);
	return 0;
}