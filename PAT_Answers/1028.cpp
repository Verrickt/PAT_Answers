#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
struct stu
{
	int id;
	char name[10];
	int grade;
};
vector<stu> stus;
int tag = 0;
int n, c;
int cmp(stu s1, stu s2)
{
	if (tag == 0)
		return s1.id < s2.id;
	if (tag == 1)
	{
		if (strcmp(s1.name, s2.name) == 0)
		{
			return s1.id < s2.id;
		}
		return strcmp(s1.name, s2.name) < 0;
	}
	if (tag == 2)
	{
		if (s1.grade == s2.grade)
			return s1.id < s2.id;
		return s1.grade < s2.grade;
	}
}
int main()
{
	scanf("%d %d\n", &n, &c);
	tag = c - 1;
	stus.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s %d", &stus[i].id, &stus[i].name, &stus[i].grade);
	}
	sort(stus.begin(), stus.end(), cmp);
	for (auto p : stus)
	{
		printf("%06d %s %d\n", p.id, p.name, p.grade);
	}
}