#include "cstdio"
#include "vector"
#include "queue"
#include "cstdlib"
using namespace std;
struct node {
	int key;
	node* left;
	node* right;
};
vector<int> post, in;


//refer https://www.liuchuo.net/archives/2090
node* to_tree(int left, int right, int root)
{
	if (left > right) return nullptr;
	int root_index = 0;
	node* n = (node*)malloc(sizeof(node));
	n->key = post[root];
	for (int i = left; i <= right; i++) if (in[i] == n->key) root_index = i;
	n->left = to_tree(left, root_index - 1, root - (right - root_index + 1));
	n->right = to_tree(root_index + 1, right, root - 1);
	return n;
}

int main()
{
	int n;
	scanf("%d", &n);
	post = vector<int>(n), in = vector<int>(n);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	node* root = to_tree(0, n - 1, n - 1);
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* cur = q.front();
		printf("%d", cur->key);
		if (cur->left != nullptr) q.push(cur->left);
		if (cur->right != nullptr) q.push(cur->right);
		q.pop();
		if (q.size() != 0) printf(" ");
	}
	return 0;
}