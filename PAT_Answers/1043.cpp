#include "iostream"
#include "vector"
#include "cstdio"
#include "cstdlib"
using namespace std;
struct node
{
	node* left;
	node* right;
	int key;
};
vector<int>v;
node* build_bst(int key, node* root)
{
	if (root == nullptr)
	{
		root = (node*)malloc(sizeof(node));
		root->left = root->right = nullptr;
		root->key = key;
		return root;
	}
	if (key < root->key) root->left = build_bst(key, root->left);
	else root->right = build_bst(key, root->right);
	return root;
}
void to_mirror(node* root)
{
	if (root != nullptr)
	{
		swap(root->left, root->right);
		to_mirror(root->left);
		to_mirror(root->right);
	}
}
void post(node* root,vector<int>& r)
{
	if (root == nullptr) return;
	post(root->left,r);
	post(root->right,r);
	r.push_back(root->key);
}
void pre(node* root, vector<int>& r)
{
	if (root == nullptr) return;
	r.push_back(root->key);
	pre(root->left, r);
	pre(root->right, r);
}
bool vector_equals(vector<int>& r1, vector<int>& r2)
{
	if (r1.size() != r2.size()) return false;
	for (int i = 0; i < r1.size(); i++) if (r1[i] != r2[i]) return false;
	return true;
}
int main()
{
	int n;
	cin >> n;
	v.resize(n);
	node* r=nullptr;
	node* m = nullptr;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
		r = build_bst(v[i], r);
		m = build_bst(v[i], m);
	}
	to_mirror(m);
	vector<int> pre1,pre2,post1,post2;
	pre(r, pre1);
	pre(m, pre2);
	post(r, post1);
	post(m, post2);
	vector<int> result;
	if (vector_equals(pre1,v))
	{
		result = post1;
	}
	else if (vector_equals(pre2, v))
	{
		result = post2;
	}
	cout << (result.size()!=0?"YES":"NO") << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
		if (i + 1 != result.size()) cout << " ";
	}
	return 0;
}