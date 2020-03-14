#include "cstdio"
#include "algorithm"
using namespace std;

struct node {
	int addr;
	int data;
	int next;
};

node nodes[100005];

int len(int addr)
{
	int l = 0;
	int cur = addr;
	while (cur!=-1)
	{
		cur = nodes[cur].next;
		l++;
	}
	return l;
}

int main()
{
	int h1, h2, n;
	scanf("%d %d %d", &h1, &h2, &n);
	for (int i = 0; i < n; i++)
	{
		int p, q, r;
		scanf("%d %c %d", &p, &q, &r);
		nodes[p].addr = p;
		nodes[p].data = q;
		nodes[p].next = r;
	}
	int diff = len(h1) - len(h2);
	if (diff<0) swap(h1, h2);
	int cur = h1;
	for (int i = 0; i < abs(diff); i++)
	{
		cur = nodes[cur].next;
	}
	while (cur!=-1&&h2!=-1)
	{
		if (nodes[cur].addr == nodes[h2].addr)
		{
			printf("%05d", cur);
			return 0;
		}
		cur = nodes[cur].next; h2 = nodes[h2].next;
	}
	printf("-1");
	return 0;
}