#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
struct node {
	int key;
	int left;
	int right;
};
vector<node> tree;
vector<int> keys;
vector<int> ans;
int n;
int index = 0;
void in(int i)
{
	if (i == -1) return;
	in(tree[i].left);
	tree[i].key = keys[index++];
	in(tree[i].right);
}
void bfs()
{
	queue<int> q = queue<int>();
	q.push(0);
	while (!q.empty())
	{
		auto i = q.front();
		ans.push_back(tree[i].key);
		int left = tree[i].left;
		int right = tree[i].right;
		if (left != -1) q.push(left);
		if (right != -1) q.push(right);
		q.pop();
	}
}
int main()
{
	cin >> n;
	tree.resize(n);
	keys.resize(n);
	for (int i = 0; i < n; i++)
		cin >> tree[i].left >> tree[i].right;
	for (int i = 0; i < n; i++) cin >> keys[i];
	sort(keys.begin(), keys.end());
	in(0);
	bfs();
	for (int i = 0; i < n; i++)
	{
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	return 0;
}