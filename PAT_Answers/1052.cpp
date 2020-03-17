#include "cstdio"
#include "vector"
#include "algorithm"
using namespace std;
struct node {
	int addr;
	int key;
	int next;
	bool tag = false;
};

bool cmp(node& n1, node& n2)
{
	if (n1.tag == n2.tag) return n1.key < n2;
	else return n1.tag;
}
vector<node> nodes = vector<node>(100086);

int cnt;
void mark(int head)
{
	int h = head; cnt = 0;
	while (h != -1)
	{
		nodes[h].tag = true;
		h = nodes[h].next;
		cnt++;
	}
}
int main()
{
	int n, head;
	scanf("%d %d", &n, &head);
	for (int i = 0; i < n; i++)
	{
		int addr, key, next;
		scanf("%d %d %d", &addr, &key, &next);
		nodes[addr] = node({ addr,key,next });
	}
	mark(head);
	sort(nodes.begin(), nodes.end(), cmp);
	if (cnt == 0)
		printf("0 -1\n");
	else
		printf("%d %05d\n", cnt, nodes[0].addr);
	for (int i = 0; i < cnt; i++)
	{
		if (i + 1 != cnt)
			printf("%05d %d %05d\n", nodes[i].addr, nodes[i].key, nodes[i + 1].addr);
		else
			printf("%05d %d -1\n", nodes[i].addr, nodes[i].key);
	}
	return 0;
}