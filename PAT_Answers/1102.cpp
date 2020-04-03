#include "iostream"
#include "vector"
#include "cstdio"
#include "cctype"
#include "queue"
using namespace std;
struct node
{
	int left=-1;
	int right=-1;
	int parent=-1;
};
vector<node> tree;
vector<int> v1, v2;
int n;
void invert(int index)
{
	if (index == -1)return;
	swap(tree[index].left, tree[index].right);
	invert(tree[index].left);
	invert(tree[index].right);
}
void level(int root){
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		v1.push_back(q.front());
		int left = tree[q.front()].left;
		int right = tree[q.front()].right;
		if (left != -1) q.push(left);
		if (right != -1) q.push(right);
		q.pop();
	}
}
void in(int root)
{
	if (root == -1) return;
	in(tree[root].left);
	v2.push_back(root);
	in(tree[root].right);
}
int main()
{
	cin >> n;
	tree.resize(n);
	for (int i = 0; i < n; i++)
	{
		char l[13], r[13];
		scanf("%s %s", &l, &r);
		tree[i].left = isdigit(l[0]) ? l[0] - '0' : -1;
		tree[i].right = isdigit(r[0]) ? r[0] - '0' : -1;
		if (tree[i].left != -1) tree[tree[i].left].parent = i;
		if (tree[i].right != -1) tree[tree[i].right].parent = i;
	}
	int root = 0;
	while (tree[root].parent != -1) root = tree[root].parent;
	invert(root);
	level(root);
	in(root);
	for (int i = 0; i < n; i++) { if (i != 0) cout << " "; cout << v1[i]; }
	cout << endl;
	for (int i = 0; i < n; i++) { if (i != 0) cout << " "; cout << v2[i]; }
	return 0;
}