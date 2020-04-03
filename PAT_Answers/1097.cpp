#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
struct node
{
	int addr;
	int key; 
	int next;
};
node nodes[100086];
bool map[10024];
void print(int head)
{
	auto cur = head;
	while (cur != -1)
	{
		if (nodes[cur].next != -1)
			printf("%05d %d %05d\n", cur, nodes[cur].key, nodes[cur].next);
		else printf("%05d %d -1\n", cur, nodes[cur].key);
		cur = nodes[cur].next;
	}
}
int main()
{
	int head, n;
	cin >> head >> n;
	for (int i = 0; i < n; i++)
	{
		int id;
		cin >> id;
		nodes[id].addr = id;
		cin >> nodes[id].key >> nodes[id].next;
	}
	fill(map, map + 10024, false);
	int dupli_head = -1;
	int dupli_tail = -1;
	int cur = head;
	int prev = -1;
	while (cur != -1)
	{
		while (map[abs(nodes[cur].key)])
		{
			int next = nodes[cur].next;
			if (dupli_head == -1) dupli_head = dupli_tail = cur;
			else
			{
				nodes[dupli_tail].next = cur;
				dupli_tail = cur;
				nodes[cur].next = -1;
			}
			cur = next;
			if (cur == -1) break;
		}
		if (cur == -1) { nodes[prev].next = -1; break; }
		if (prev != -1) nodes[prev].next = cur;
		map[abs(nodes[cur].key)] = true;
		prev = cur;
		cur = nodes[cur].next;
	}
	print(head);
	print(dupli_head);
	return 0;
}